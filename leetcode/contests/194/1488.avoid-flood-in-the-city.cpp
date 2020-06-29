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

// Bw two positions having same value choose a pos with 0, 
// such that it is as close as possible to the last seen( 2nd end)
// So that if some other value appearing later wants to use some pos, it is able
class Solution {
    int ex = 1e9-21311; // replace with some random value
    // int ex = 0;
public:
    vector<int> avoidFlood(vector<int>& a) {
        int n = a.size();
        vi ans(n,ex);
        set<int> zpos; 
        map<int,int> last_seen;

        bool valid = 1;
        for(int i=n-1; i>=0; --i){
            if(!a[i]){
                zpos.insert(i);
            }else{
                ans[i] = -1;
                if(last_seen.count(a[i])){
                    int at = last_seen[a[i]];
                    auto pos = zpos.upper_bound(at);
                    if(pos!=zpos.begin()){
                        --pos;
                        ans[*pos] = a[i];
                        zpos.erase(pos);
                    }else{
                        valid = 0;
                    }
                }
                last_seen[a[i]] = i;
            }
        }

        if(!valid) return {};
        return ans;
    }
};

int main(){
    Solution sol;
    vvi as = {
        {1,0,2,0},
        {1,2,3,4},
        {1,2,0,0,2,1},
        {1,2,0,1,2},
        {69,0,0,0,69},
        {10,20,20},
        { 1,0,2,0,2,1 },
    } ;
    for(auto a: as){
        vi out = sol.avoidFlood(a); print(out);
    }
    return 0;
}