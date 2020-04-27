#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// Range sum query mutable
struct node{
    int val;
};

class SegmentTree {
    int n;
    vector<node> st;

    node make_node(int val) {
        node res;
        res.val = val;
        return res;
    }
public:
    SegmentTree(vector<int>& a) {
        n = a.size();
        if(!n) return;

        // int x = (int)(ceil(log2(n)));
        // int max_size = 2*(int)pow(2, x);
        int max_size = 4*n;
        st.clear(); st.resize(max_size, node());
        build(1,0,n-1,a);
    }

    void merge(node &cur, node l, node r){
        cur.val = l.val + r.val;
    }

    void build(int pos, int l, int r, vi &a){
        if(l==r){
            st[pos] = make_node(a[l]);
            return;
        }
        int mid = (l+r)/2;
        build(2*pos,l,mid,a);
        build(2*pos+1,mid+1,r,a);
        merge(st[pos] ,st[2*pos] , st[2*pos+1]);
    }
    
    
    void update(int i, int val, int pos, int l, int r) {
        if(l==r){
            st[pos] = make_node(val);
            return;
        }
        int mid = (l+r)/2;
        // if index is <=mid it lies in left part
        if(i<=mid)
            update(i,val,2*pos,l,mid);
        else 
            update(i,val,2*pos+1,mid+1,r);

        merge(st[pos], st[2*pos] , st[2*pos+1]);
    }
    
    node query(int i, int j, int pos, int l, int r) {
        if(i>r || l>j) return make_node(0);
        if(i<=l && r<=j) return st[pos];
        int mid = (l+r)/2;
        node left = query(i,j,2*pos,l,mid);
        node right = query(i,j,2*pos+1,mid+1,r);
        node cur;
        merge(cur, left, right);
        return cur;
    }

    void update(int i, int val){
        update(i,val,1,0,n-1);
    }

    int query(int i,int j){
        node q = query(i,j,1,0,n-1);
        return q.val;
    }
};

int main(){
    vi nums = {1,3,5};
    SegmentTree st(nums);
    int out;
    st.update(0,3);
    out = st.query(1,1); cout<<out<<endl;
    out = st.query(0,1); cout<<out<<endl;
    st.update(1,-3); 
    out = st.query(0,1); cout<<out<<endl;

    return 0;
}

// Example: 
// 1 . other/GSS3