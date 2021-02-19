#include <bits/stdc++.h>
using namespace std;

// range max query here
class SegmentTree{
    int n;
    vector<int> st; // use struct data type instead of int if required
    vector<int> clazy; // check lazy
    vector<int> lazy; // stores lazy value
public:
    SegmentTree(int N){
        n = N;
        st.assign(4*n+5,0);
        clazy.assign(4*n+5, false);
        lazy.assign(4*n+5,0);
    }

    void merge(int &cur, int l, int r){
        // merge accordingly 
    }
    
    void build(int pos, int l, int r){
        if(l==r){
            // assign according to array values if initially present
            st[pos] = 0; lazy[pos] = false; 
            return;
        }
        int mid = (l+r)/2;
        build(2*pos, l, mid);
        build(2*pos+1, mid+1, r);
        // merge function
        merge(st[pos], st[2*pos], st[2*pos+1]);
    }

    
    int query(int pos, int l, int r, int i, int j){
        if(clazy[pos]) propagate(pos, l, r); 
        if(l>j || i>r) return 0; // out of range, return sth to be ignored
        if(i<=l && r<=j) return st[pos]; // complete overlap

        // partial overlap
        int mid = (l+r)/2;

        int cur;
        int left = query(2*pos, l, mid, i, j);
        int right = query(2*pos+1, mid+1, r, i, j);
        merge(cur, left, right);
        return cur;
    }
    
    void update(int pos, int l, int r, int i, int j, int val){
        if(clazy[pos]) propagate(pos,l,r);
        if(l>j || i>r) return;
        if(i<=l && r<=j){
            clazy[pos] = 1;
            lazy[pos] = val;
            propagate(pos,l,r);
            return;
        }
        int mid = (l+r)/2;
        update(2*pos, l, mid, i, j, val);
        update(2*pos+1, mid+1, r, i, j, val);
        merge(st[pos], st[2*pos], st[2*pos+1]);
    }

    int pQuery(int pos, int l, int r, int index){
        if(clazy[pos]) propagate(pos,l,r);
        if(l==r) return st[pos];
        int mid = (l+r)/2;
        if(pos<=mid)
            return pQuery(2*pos, l, mid, index);
        // else 
        return pQuery(2*pos+1, mid+1, r, index);
    }

    void pUpdate(int pos, int l, int r, int index, int val){
        if(clazy[pos]) propagate(pos,l,r);
        if(l==r){
            clazy[pos] = 1;
            lazy[pos] = val;
            propagate(pos,l,r);
            return;
        }
        int mid = (l+r)/2;
        if(pos<=mid)
            pUpdate(pos*2, l, mid, index, val);
        else 
            pUpdate(pos*2+1, mid+1, r, index, val);
        merge(st[pos], st[2*pos], st[2*pos+1]);
    }

    void propagate(int pos, int l, int r){
        if(l!=r){ // not a leaf
            clazy[2*pos] = clazy[2*pos+1] = 1;
            lazy[2*pos] = lazy[2*pos+1] = lazy[pos];
        }
        st[pos] = lazy[pos];
        clazy[pos] = 0;
    }
};

int main(){
    
    return 0;
}

// Usage Examples: 
// 1. https://leetcode.com/problems/falling-squares/