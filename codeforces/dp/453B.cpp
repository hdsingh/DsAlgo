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

// Refer:
// https://www.quora.com/How-do-I-solve-the-question-Little-Pony-and-Harmony-Chest-453B-on-Codeforces

// primes less than 58
vi pr = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
vi a(101);
vi factormask(60);

int dp[101][1<<16], min_b[101][1<<16];
// dp[i][S] = min(dp[i-1][S/T] + abs(a[i]-j), dp[i-1][S] + abs(a[i]-1))
// here T = set of factors of T
// min_b[i][S] represents minimum value of bi that be obtained for
// dp[i][S]

void precalcFactormask(){
    for(int i=1; i<60; ++i)
        for(int j=0; j<16; ++j)
            if(i%pr[j]==0)
                factormask[i]|=(1<<j);
}


int calc(int pos, int mask){
    if(pos==0) return 0;
    if(~dp[pos][mask]) return dp[pos][mask];

    // assign 1 to cur b
    // 1 has no prime facts so mask is passsed unchanged
    dp[pos][mask] = calc(pos-1, mask) + abs(a[pos]-1);
    min_b[pos][mask] = 1;
    
    // now consider all values from 2 to 58
    for(int j=2; j<59; ++j){
        // ensure that all facts of j exist in mask, i.e
        // it has not been used before(upon using a j, remove its facts)
        if((mask&factormask[j])!=factormask[j]) continue;
        
        int cur = calc(pos-1, mask^factormask[j]) + abs(a[pos]-j);
        if(cur<dp[pos][mask]){
            dp[pos][mask] = cur;
            min_b[pos][mask] = j;
        }
    }

    return dp[pos][mask];
}

int main(){
    int n;
    cin>>n;
    fore(i,1,n+1) cin>>a[i];
    int fullmask = (1<<16)-1;
    memset(dp,-1,sizeof(dp));

    precalcFactormask();
    calc(n, fullmask);
    vi bseq;
    for(int i=n, mask = fullmask; i>0; --i){
        int cur = min_b[i][mask];
        bseq.push_back(cur);

        // remove the set of factors of cur_b from the mask
        mask^=factormask[cur];
    }

    reverse(all(bseq));
    print(bseq);
    
    return 0;
}