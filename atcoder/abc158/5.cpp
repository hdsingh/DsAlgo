#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Consider 1231 , p = 3
// we will start from right and move towards left forming the number
// Logic same as count subarray sum equals K
// take number formed %3 from r to l
//  1  2   3   1   X
//  1  0   1   1   0
// i.e 1%3 = 1, 31%3 = 1, 231%3 = 0, 1231%3 = 1
// Since we know that if remainder after mod is same, the number in 
// bw same mods is divisible by p [LC 974]
// Example from numbers bw first 1 and second 1 : (12) is divisible 
// by 3.
// Since every number except 2, 5 is coprime to 10, the above logic is valid
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p; string s;
    while(cin>>n>>p>>s){
        ll ans = 0;
        if(p==2){
            for(int i=0; i<n; ++i){
                if((s[i]-'0')%2==0)
                    ans+=i+1; // all substring from beg to here
            }
        }else if(p==5){
            for(int i=0; i<n; ++i){
                if((s[i]-'0')%5==0)
                    ans+=i+1;
            }
        }else{
            map<int,int> cnt;
            cnt[0] = 1;
            int tot = 0; int p10 = 1;
            for(int i=n-1; ~i; --i){
                tot = ((s[i]-'0')*p10 + tot)%p;
                cnt[tot]++;
                p10 = (p10*10)%p;
            }

            // C(n,2)
            for(auto x: cnt){
                if(x.second>=2)
                    ans+= ((ll)x.second * (ll)(x.second-1))/2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}