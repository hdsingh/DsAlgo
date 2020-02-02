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
const int mod = 998244353;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }
inline ll fpow(ll n, ll k, int p = mod) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

int main(){
    int n;
    cin>>n;
    vi a(n);
    forn(i, n)
        cin>>a[i];
    map<int, int> lst;
    vi last_pos(n);

    for(int i=n-1; i>=0; i--){
        if(!lst.count(a[i]))
            lst[a[i]] = i;
        last_pos[i] = lst[a[i]];
    }

    int ans = 1;
    int cur_max = -1;
    forn(i,n-1){
        cur_max = max(cur_max, last_pos[i]);
        if(cur_max == i)    
            ans = 2*ans%mod;
    }

    // print(last_pos);

    cout<<ans<<endl;
}

// int main(){
//     int n;
//     cin>>n;
//     // while(cin>>n){
//         int x, ans;
//         map<int, int> m;
//         int lp = INT_MAX;
//         int pos = 0;
//         bool found_again = false;
//         int prev = -1;
//         vi a(n);
//         forn(i, n)
//             cin>>a[i];
//         reverse(all(a));

//         for(int x: a){
//             cin>>x;
//             if(x==prev) continue;

//             if(m[x]==0){
//                 m[x] = pos;
//                 pos++;
//             }else{
//                 found_again = true;
//                 lp = min(lp, m[x]);
//             }
//             prev = x;
//         }

//         // deb2(pos, lp);
//         if(found_again){
//             ans = fpow(2, lp);
//         }else 
//             ans = fpow(2, pos-1);
        
//         cout<<ans<<endl;
//     // }
//     return 0;
// }