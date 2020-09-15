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

// Refer: https://leetcode.com/problems/online-majority-element-in-subarray/discuss/356227/C%2B%2B-Codes-of-different-approaches-(Random-Pick-Trade-off-Segment-Tree-Bucket)
// Refer: https://leetcode.com/problems/online-majority-element-in-subarray/discuss/356108/C%2B%2B-160-ms-frequency-%2B-binary-search

class MajorityChecker1 {
    map<int,vi> locs;
    vi st; // mx element of a range;
    int n;
public:
    MajorityChecker1(vector<int>& a) {
        n = sz(a);
        forn(i,n) locs[a[i]].pb(i);
        st.assign(4*n, -1);
        build(1,0,n-1,a);
    }

    void build(int pos, int sl, int sr, vi &a){
        if(sl==sr){
            st[pos] = a[sl];
            return;
        }
        int mid = (sl+sr)/2;
        build(2*pos, sl, mid,a);
        build(2*pos+1,mid+1, sr, a);
        
        if(st[2*pos]!=-1 && 2 * get_occ(st[2*pos], sl, sr) > sr - sl +1){
            st[pos] = st[2*pos];
        }else if(st[2*pos+1]!=-1 && 2* get_occ(st[2*pos+1], sl, sr) > sr - sl + 1){
            st[pos] = st[2*pos+1];
        }
    }

    // {val, times}
    pii query(int pos, int sl, int sr, int l, int r){
        if(sr<l || r<sl) return {-1,-1};
        if(l<=sl && sr<=r){
            int times = get_occ(st[pos],l,r);
            if(st[pos]!=-1 && 2*times > r-l+1)
                return {st[pos], times};
            return {-1,-1};
        }
        int mid = (sl+sr)/2;
        pii ql = query(2*pos,sl,mid,l,r);
        if(ql.first!=-1) return ql;
        pii qr = query(2*pos+1,mid+1,sr,l,r);
        return qr;
    }

    int get_occ(int val, int l, int r){
        if(2*sz(locs[val])<=r-l+1) return 0;
        auto lpos = lower_bound(all(locs[val]), l);
        if(lpos==locs[val].end()) return 0;
        auto rpos = upper_bound(all(locs[val]), r);
        return rpos - lpos;
    }
    
    int query(int left, int right, int threshold) {
        pii ans = query(1,0,n-1,left, right);
        if(ans.second>=threshold) return ans.first;
        return -1;
    }
};

class MajorityChecker {
    vector<pair<int,vi>> locs;
public:
    MajorityChecker(vector<int>& arr) {
        unordered_map<int,vi> m;
        int n = sz(arr);
        forn(i,n){
            m[arr[i]].pb(i);
        }   
        for(auto &p: m) locs.pb(p);
        sort(all(locs),[&](pair<int,vi> &p1, pair<int,vi> &p2){
            return sz(p1.second) > sz(p2.second);
        });
    }
    
    int query(int left, int right, int threshold) {
        for(auto &p: locs){
            if(sz(p.second)<threshold) break;
            auto lpos = lower_bound(all(p.second),left);
            auto rpos = upper_bound(all(p.second),right);
            if(rpos-lpos>=threshold) return p.first;
        }
        return -1;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vi a = {1,1,2,2,1,1}; int out;
    MajorityChecker majorityChecker(a);
    out = majorityChecker.query(0,5,4); deb(out); // returns 1
    out = majorityChecker.query(0,3,3); deb(out); // returns -1
    out = majorityChecker.query(2,3,2); deb(out); // returns 2
    return 0;
}