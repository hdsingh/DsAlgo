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
typedef pair<ll, ll> pll;
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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

vi getRandSeq(int l, int r, int len){
    vi a(len);
    for(int i=0; i<len; ++i)
        a[i] = getRand(l,r);
    return a;
}

vi getUniqRandSeq(int l, int r, int len){
    if(r-l+1<len) return {};
    vi a(len);
    set<int> seen;
    for(int i=0; i<len; ++i) {
        a[i] = getRand(l,r);
        if(seen.count(a[i])) --i;
        else seen.insert(a[i]);
    }
    return a;
}

class Solution  {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> a, b;
        for(int i=0; i<n/2; ++i) a.push_back(nums[i]);
        for(int j=n/2; j<n; ++j) b.push_back(nums[j]);
        vector<int> s1 = subsets(a), s2 = subsets(b);

        int ans = INT_MAX;
        for(auto x: s2){
            auto pos = lower_bound(s1.begin(), s1.end(), goal-x);
            if(pos!=s1.end()) ans = min(ans, abs(*pos+x-goal));
            if(pos!=s1.begin()){
                --pos;
                ans = min(ans, abs(x+*pos-goal));
            }
        }
        return ans;
    }
    
    vector<int> subsets(vector<int> &a){
        int n = a.size();
        unordered_set<int> s;
        for(int mask=0; mask<(1<<n); ++mask){
            int sum = 0;
            for(int i=0; i<n; ++i){
                if((mask>>i)&1){
                    sum+=a[i];
                }
            }
            s.insert(sum);
        }
        vector<int> out;
        for(auto x: s) out.push_back(x);
        sort(out.begin(), out.end());
        return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; int n, out, goal; vi a; 
    n = 40; a = getRandSeq(1,1e7,n);
    goal = getRand(1,1e5);
    a = {5,-7,3,5}, goal = 6;
    a = {7,-9,15,-2}, goal = -5;
    out = sol.minAbsDifference(a,goal); deb(out);
    return 0;
}