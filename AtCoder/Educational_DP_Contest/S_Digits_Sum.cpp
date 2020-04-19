#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

int main(){
    string k; cin>>k;
    int d; cin>>d;

    int len = k.size();
    vvi dp(d, vi(2));
    // dp[sum][smaller_already] reprsents the number of ways to choose digits so far
    // such that (sum of digits)%d is 'sum' and smaller_already means whether
    // we have already choosen a digit that is smaller than some digit in K

    dp[0][0] = 1;
    for(int idx=0; idx<len; ++idx){
        vvi ndp(d, vi(2));
        for(int sum=0; sum<d; ++sum){
            for(bool sm_already : {false, true}){
                for(int digit = 0; digit<10; ++digit){
                    if(digit > k[idx] -'0' && !sm_already){
                        break;
                    }
                    
                    // either it was prev smaller or since now the digit chosen is < than k[idx]
                    // so sm_already and we can choose bigger digits in next idx
                    add_self(ndp[(sum+digit)%d][sm_already || digit < k[idx] - '0' ], 
                             dp[sum][sm_already]);
                }
            }
        }
        dp = ndp;
    }

    int ans = (dp[0][false] + dp[0][true])%mod;
    --ans; // since we are counting 0 as well
    if(ans<0){
        ans+=mod;
    }

    cout<<ans<<endl;
    
    return 0;
}