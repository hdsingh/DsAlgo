#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// Range sum query mutable
struct node{
    int val;
    node(){};
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

        int max_size = 4*n;
        st.clear(); st.resize(max_size, node());
        build(1,0,n-1,a);
    }

    void merge(node &cur, node &l, node &r){
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
    
    
    void update(int pos, int l, int r, int i, int val) {
        if(l==r){
            st[pos] = make_node(val);
            return;
        }
        int mid = (l+r)/2;
        // if index is <=mid it lies in left part
        if(i<=mid)
            update(2*pos,l,mid,i,val);
        else 
            update(2*pos+1,mid+1,r,i,val);

        merge(st[pos], st[2*pos] , st[2*pos+1]);
    }
    
    node query(int pos, int l, int r, int i, int j) {
        if(i>r || l>j) return make_node(0);
        if(i<=l && r<=j) return st[pos];
        int mid = (l+r)/2;
        node left = query(2*pos,l,mid,i,j);
        node right = query(2*pos+1,mid+1,r,i,j);
        node cur;
        merge(cur, left, right);
        return cur;
    }

    void update(int i, int val){
        update(1,0,n-1,i,val);
    }

    int query(int i,int j){
        node q = query(1,0,n-1,i,j);
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
// 1. other/GSS3
// 2. https://codeforces.com/contest/1354/problem/D 
// 3. https://codeforces.com/problemset/problem/380/C (Brackets)
// 4. https://codeforces.com/contest/339/problem/D (Bitwise level based)
// 5. https://codeforces.com/contest/459/problem/D (Range Sum Query)
// 6. https://codeforces.com/contest/61/problem/E (Left greater + Right Lesser)
// 7. https://codeforces.com/problemset/problem/522/D ( Offline Processing + Range minimum Query )
// 8. (https://codeforces.com/contest/474/problem/F) (Count gcd of a range and number times it appears)

