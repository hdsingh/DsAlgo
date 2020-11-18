#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

// MergeSort Inversion count
class Solution{
public:
    vector<int> countSmaller(vector<int> &a){
        int n = a.size();
        vector<int> ans(n);
        vector<int> indices(n);
        for(int i=0; i<n; ++i)
            indices[i] = i;
        mergeSort(0,n-1,indices,a,ans);
        return ans;
    }
    
    void mergeSort(int lt, int rt, vector<int> &indices, vector<int> &a, vector<int> &ans){
        if(lt>=rt) return;
        int mid = (lt+rt)/2;
        mergeSort(lt,mid,indices,a,ans);
        mergeSort(mid+1,rt,indices,a,ans);
        
        merge(lt,mid,rt,indices,a,ans);
    }
    
    void merge(int lt, int mid, int rt, vector<int> &indices, vector<int> &a, vector<int> &ans){
        int n1 = (mid-lt+1);
        int n2 = (rt-mid);
        vector<int> L(n1), R(n2);
        for(int i=0; i<n1; ++i)
            L[i] = indices[lt+i];
        for(int j=0; j<n2; ++j)
            R[j] = indices[mid + 1 + j];
        
        int ptr = n2-1;
        for(int i=n1-1; i>=0; --i){
            while(ptr>=0 && a[R[ptr]]>=a[L[i]])
                --ptr;
            ans[L[i]]+=(ptr+1);
        }
        
        int i = 0, j = 0, k = lt;
        while(i<n1 && j<n2){
            if(a[L[i]]<a[R[j]])
                indices[k++] = L[i++];
            else 
                indices[k++] = R[j++];
        }
        while(i<n1) indices[k++] = L[i++];
        while(j<n2) indices[k++] = R[j++];
    }
};

const int nax = 1e4+10;

class SegmentTree{
public:
    int n;
    vi st;

    SegmentTree(){
        n = 2*nax;
        st.assign(4*n,0);
    }

    void update(int pos, int sl, int sr, int i){
        if(sl==sr){
            st[pos]++;
            return;
        }
        int mid = (sl+sr)/2;
        if(i<=mid) update(2*pos, sl, mid, i);
        else update(2*pos+1, mid+1, sr, i);
        st[pos] = st[2*pos] + st[2*pos+1];
    }

    int query(int pos, int sl, int sr, int l, int r){
        if(sr<l || r<sl) return 0;
        if(l<=sl && sr<=r) return st[pos];
        int mid = (sl+sr)/2;
        return query(2*pos, sl, mid, l, r) + query(2*pos+1, mid+1, sr, l, r);
    }

    int query(int l, int r){
        return query(1, 0, n-1, l+1e4, r+1e4);
    }

    void update(int i){
        update(1,0,n-1, i+1e4);
    }
};

class Fenwick{
public:
    int n;
    vi ft;

    Fenwick(){
        n = 2*nax + 20;
        ft.assign(n,0);
    }

    void update(int idx, int val){
        while(idx<n){
            ft[idx]+=val;
            idx+= idx & -idx;
        }
    }

    int pref(int idx){
        int ans = 0;
        while(idx>0){
            ans+=ft[idx];
            idx-= idx & -idx;
        }
        return ans;
    }

    int query(int l, int r){
        return pref(r+1e4+10) - pref(l-1 + 1e4+10);
    }

    void update(int i){
        update(i+1e4+10,1);
    }
};

class Solution0 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // SegmentTree st;
        Fenwick st;
        vi out;
        reverse(all(nums));
        for(auto x: nums){
            int cur = st.query(-1e4-2, x-1);
            st.update(x);
            out.pb(cur);
        }
        reverse(all(out));
        return out;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        multiset<int> s;
        vi out;
        reverse(all(nums));
        for(auto x: nums){
            auto pos = s.lower_bound(x);
            out.pb(distance(s.begin(), pos));
            s.insert(x);
        }
        reverse(all(out));
        return out;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution0 sol; vi a, out;
    a = {10001,-9999,5,2,6,1,-10001,10000};
    out = sol.countSmaller(a); print(out);
    return 0;
}