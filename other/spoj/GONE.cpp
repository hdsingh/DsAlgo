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

const int nax = 100;
vb isPrime(nax,1);

void precalc(){
    isPrime[0] = isPrime[1] = 0;
    for(int i=2; i*i<nax; ++i){
        if(isPrime[i]){
            for(int j=i*i; j<nax; j+=i)
                isPrime[j] = 0;
        }
    }
}

int dp[20][100][2]; // (pos, sum, tight from beg till pos)

int find_cnt(int num){
    string s = to_string(num);
    int n = sz(s);

    memset(dp, 0, sizeof(dp));
    dp[n][0][0] = dp[n][0][1] = 1;

    for(int i=n-1; i>=0; --i){
        for(int sum=0; sum<100; ++sum){
            for(int tight : {0,1}){
                int cd = (s[i] - '0');
                if(tight){
                    for(int d=0; d<=cd; ++d)
                        if(sum-d>=0)
                            dp[i][sum][1] += (d==cd) ? dp[i+1][sum-d][1] : dp[i+1][sum-d][0];
                }else{
                    for(int d=0; d<10; ++d)
                        if(sum-d>=0)
                            dp[i][sum][0] += dp[i+1][sum-d][0];
                }
            }
        }
    }    

    int ans = 0;
    for(int i=0; i<100; ++i)
        if(isPrime[i])
            ans+=dp[0][i][1];
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    precalc();

    int T;
    cin>>T;
    while(T--){
        int l, r;
        cin>>l>>r;
        int ans = find_cnt(r) - find_cnt(l-1);
        cout<<ans<<"\n";
    }
    
    return 0;
}

// similar to [C. Classy Numbers](https://codeforces.com/contest/1036/problem/C)