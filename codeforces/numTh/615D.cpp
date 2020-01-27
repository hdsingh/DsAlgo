#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
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
inline ll fpow(ll n, ll k, int p = mod) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int mult(ll a, ll b, int p = mod) {return a * b % p;}
int inverse(int a){return fpow(a, mod-2)%mod;}


template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

int main(){
    int m, x;
    while(cin>>m){
        map<int, int> pcnt;
        forn(i, m){
            cin>>x;
            pcnt[x]++;
        }

        ll d = 1;
        ll ans = 1;
        ll fp;
        for(auto pc: pcnt){
            ll p = pc.first;
            ll c = pc.second;
            fp = fpow(p, (c+1)*c/2);
            ans = fpow(ans, c+1) * fpow(fp, d)%mod;
            d = d*(c+1)%(mod-1);         
        }

        cout<<ans<<endl;
    }

}

// int main1(){
//     int m,x;
//     while(cin>>m){
//         map<int,int> pcnt; //primes count
//         forn(i, m){
//             cin>>x;
//             pcnt[x]++;
//         }

//         // Find total factors d => (e1+1).(e2+1).(e3+1)..
//         // and n
//         ll d = 1;
//         ll n = 1;
//         bool is_sqrt = true;
//         for(auto pc : pcnt){
//             d = d*(pc.second+1)%mod;
//             n = n*fpow(pc.first, pc.second)%mod;
//             if(pc.second%2==1) is_sqrt = false;
//         }

//         ll ans = fpow(n, d/2)%mod;

//         if(is_sqrt){ // multiple by sqrt once
//            for(auto pc : pcnt){
//             ans = ans*fpow(pc.first, pc.second/2)%mod;
//             } 
//         }

//         // deb(d);
//         // deb(n);
//         // product of factors = pow(n, d/2);

//         cout<<ans%mod<<endl;

        
//     }
//     return 0;
// }