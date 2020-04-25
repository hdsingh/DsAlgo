#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// Range sum query mutable
class SegmentTree {
    int n;
    vi st;
public:
    SegmentTree(vector<int>& a) {
        n = a.size();
        if(!n) return;

        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x);
        // or max_size = 4*n
        st.clear(); st.resize(max_size);
        build(1,0,n-1,a);
    }

    void merge(int &cur, int l, int r){
        cur = l + r;
    }

    void build(int pos, int l, int r, vi &a){
        if(l==r){
            st[pos] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*pos,l,mid,a);
        build(2*pos+1,mid+1,r,a);
        merge(st[pos] ,st[2*pos] , st[2*pos+1]);
    }
    
    
    void update(int i, int val, int pos, int l, int r) {
        if(l==r){
            st[pos] = val;
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
    
    int query(int i, int j, int pos, int l, int r) {
        if(i>r || l>j) return 0;
        if(i<=l && r<=j) return st[pos];
        int mid = (l+r)/2;
        int left = query(i,j,2*pos,l,mid);
        int right = query(i,j,2*pos+1,mid+1,r);
        int cur;
        merge(cur, left, right);
        return cur;
    }

    void update(int i, int val){
        update(i,val,1,0,n-1);
    }

    int query(int i,int j){
        return query(i,j,1,0,n-1);
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
