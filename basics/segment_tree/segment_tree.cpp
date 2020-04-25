#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" "<<x<<endl;
typedef vector<int> vi;

// Ref: https://github.com/mission-peace/interview/blob/master/src/com/interview/tree/SegmentTreeMinimumRangeQuery.java
// Range minimum query
const int inf = 1e9;

class SegmentTree {
    vi st;
    int n;
    vi a; // input array
    vi lazy;
public:
    SegmentTree(vi &arr){
        a = arr;
        n = a.size();
        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x) - 1;
        st.clear(); lazy.clear();
        st.resize(max_size+1, inf);
        lazy.resize(max_size+1);

        build(0,n-1,1);
    }

    // node position, segment_left, segment_right
    void build(int l, int r, int pos){
        if(l==r){
            st[pos] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(l, mid, 2*pos);
        build(mid+1, r, 2*pos+1);
        st[pos] = min(st[2*pos], st[2*pos+1]);
    }

    // point update
    void update(int index, int delta){
        // a[index] +=delta; // optional
        updateP(index, delta, 0, n-1, 1);
    }

    // Range update (start range, end range)
    void update(int sr, int er, int delta){
        // optional (only if necessary)
        // for(int i=sr; i<=er; ++i) a[i]+=delta;
        updateR(sr, er, delta, 0, n-1, 1);
    }

    int query(int ql, int qh){
        return query(ql, qh, 0, n-1, 1);
    }

    int queryRL(int ql, int qh){
        return queryRL(ql, qh, 0, n-1, 1);
    }

    void updateRL(int sr, int er, int delta){
        updateRL(sr, er, delta, 0, n-1, 1);
    };


    int query(int ql, int qh, int l, int h, int pos){
        if(ql>h || l>qh) return INT_MAX;
        if(ql<=l && h<=qh) return st[pos];

        int mid = (l+h)/2;
        return min(query(ql, qh, l, mid, 2*pos),
                   query(ql, qh, mid+1, h, 2*pos+1));
    }

    void updateP(int index, int delta, int l, int r, int pos){
        if(index<l || r>index) return;

        // possible only when it is index
        if(l==r){
            st[pos] +=delta;
            return;
        }   
        int mid = (l+r)/2;
        updateP(index, delta, l, mid, 2*pos);
        updateP(index, delta, mid+1, r, 2*pos+1);
        st[pos] = min(st[pos*2], st[pos*2+1]);
    }

    void updateR(int sr, int er, int delta, int l, int r, int pos){
        if(l>er || sr>r || l>r) return;

        if(l==r){
            st[pos]+=delta;
            return;
        }

        int mid = (l+r)/2;
        updateR(sr, er, delta, l, mid, 2*pos);
        updateR(sr, er, delta, mid+1, r, 2*pos+1);
        st[pos] = min(st[pos*2], st[pos*2+1]);
    }

    void updateRL(int sr, int er, int delta, int l, int h, int pos){
        if(l>h) return;

        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        if(lazy[pos]){
            st[pos]+=lazy[pos];
            if(l!=h){ // not a leaf node
                lazy[2*pos]+=lazy[pos];
                lazy[2*pos+1]+=lazy[pos];
            }
            lazy[pos] = 0;
        }

        // no overlap
        if(h<sr || er<l) return;

        // total overlap
        if(sr<=l && h<=er){
            st[pos] +=delta;
            if(l!=h){
                lazy[2*pos]+=delta;
                lazy[2*pos+1]+=delta;
            }
            return;
        }

        //otherwise partial overlap so look both left and right.
        int mid = (l+h)/2;
        updateRL(sr,er,delta,l,mid,2*pos);
        updateRL(sr,er,delta,mid+1,h,2*pos+1);
        st[pos] = min(st[pos*2], st[pos*2+1]);
    }

    int queryRL(int ql, int qh, int l, int h, int pos){
        if(l>h) return INT_MAX;

        if(lazy[pos]){
            st[pos]+= lazy[pos];
            if(l!=h){
                lazy[2*pos]+=lazy[pos];
                lazy[2*pos+1]+=lazy[pos];
            }
            lazy[pos] = 0;
        }

        // no overlap
        if(ql>h || qh<l) return INT_MAX;

        // total overlap
        if(ql<=l && h<=qh) return st[pos];

        // partial overlap
        int mid = (l+h)/2;
        return min(queryRL(ql, qh, l, mid, 2*pos),
                   queryRL(ql, qh, mid+1, h, 2*pos+1));
    }
};

int main(){
    vi a = {0,3,4,2,1,6,-1};
    SegmentTree segTree(a);

    // // non lazy
    assert(0 == segTree.query(0,3));
    assert(1 == segTree.query(1,5));
    assert(-1 == segTree.query(1,6));
    segTree.update(2,1);
    assert(2 == segTree.query(1,3));
    segTree.update(3,5,-2);
    assert(-1 == segTree.query(5,6));
    assert(0 == segTree.query(0,3));

    // Lazy prop
    a = {-1,2,4,1,7,1,3,2};
    SegmentTree segTreeL(a); 
    segTreeL.updateRL(0,3,1);
    segTreeL.updateRL(0,0,2);
    int out = segTreeL.queryRL(3,5);
    assert(1==segTreeL.queryRL(3,5));

    return 0;
}