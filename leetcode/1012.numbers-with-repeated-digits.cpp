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


// ans = # with no digit repeat
// calculate separately for (d-1) digit numbers
// and for numbers having same len and no repeat use digit dp;
class Solution {
    vi a;
    int dp[10][1<<10][2];
    int len;
public:
    int numDupDigitsAtMostN(int n) {
        if(n<=10) return 0;
        vi seq = {9,9,8,7,6,5,4,3,2,1,1};
        int lower = log10(n);
        int ans = 0;
        int tot = 1;
        forn(i,lower){
            tot*=seq[i];
            ans+=tot;
        }
        memset(dp, -1, sizeof(dp));
        a.clear();
        int temp = n;
        while(temp){
            a.pb(temp%10); temp/=10;
        }
        reverse(all(a));
        len = sz(a);

        ans+=dfs(0,0,1);
        return n - ans;  
    }

    // digits having same len as a,
    int dfs(int pos, int mask, bool tight){
        if(pos>=len) return 1;
        int ans = dp[pos][mask][tight];
        if(~ans) return ans;
        ans = 0;

        if(tight){
            for(int d=0; d<=a[pos]; ++d){
                if(!d && !pos) continue; // dont use 0 at 0th index
                if((mask>>d)&1) continue;
                ans+=dfs(pos+1,mask|(1<<d), d==a[pos]);
            }
        }else{
            for(int d=0; d<10; ++d){
                if((mask>>d)&1) continue;
                ans+=dfs(pos+1,mask|(1<<d), 0);
            }
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; int out;
    int c = 1e9;
    vi a = {100, 20, c};
    for(auto x: a){
        out = sol.numDupDigitsAtMostN(x); deb(x,out);
    }
    return 0;
}