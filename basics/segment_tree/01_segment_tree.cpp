#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// Range sum query mutable
struct node{
    int val;
    node(){};
    node(int V): val(V){};
};

class SegmentTree {
    int n;
    vector<node> st;
public:
    SegmentTree(vector<int>& a) {
        n = a.size();
        if(!n) return;

        int max_size = 4*n;
        st.clear(); st.resize(max_size, node());
        build(1,0,n-1,a);
    }

    node merge(node &l, node &r){
        node cur;
        cur.val = l.val + r.val;
        return cur;
    }

    void build(int pos, int l, int r, vi &a){
        if(l==r){
            st[pos] = node(a[l]);
            return;
        }
        int mid = (l+r)/2;
        build(2*pos,l,mid,a);
        build(2*pos+1,mid+1,r,a);
        st[pos] = merge(st[2*pos] , st[2*pos+1]);
    }
    
    
    void update(int pos, int sl, int sr, int i, int &val){
        if(sl==sr){
            st[pos] = val;
            return;
        }
        int mid = (sl+sr)/2;
        if(i<=mid)
            update(2*pos,sl,mid,i,val);
        else 
            update(2*pos+1,mid+1,sr,i,val);
        st[pos] = merge(st[2*pos], st[2*pos+1]);
    }

    node query(int pos, int sl, int sr, int l, int r){
        if(sr<l || r<sl) return node(0);
        else if(l<=sl && sr<=r) return st[pos];
        int mid = (sl+sr)/2;
        node left = query(2*pos,sl,mid,l,r);
        node right = query(2*pos+1, mid+1,sr, l,r);
        return merge(left,right);
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

