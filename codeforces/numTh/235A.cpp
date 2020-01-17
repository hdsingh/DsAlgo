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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

ll lcm(ll a, ll b){
    int gcd = __gcd(a, b);
    return (a*b)/gcd;
}

ll lcm3(ll a, ll b, ll c){
    return lcm( lcm(a, b), c );
}

void find(int n){
    int mlcm = 0;
    int mi, mj, mk;
    fore(i, 1, n+1)
        fore(j, 1, n+1)
            fore(k, 1, n+1){
                int lc = lcm3(i,j,k);
                if(lc>mlcm){
                    mlcm = lc;
                    mi = i; mj = j; mk = k;
                }
            }

    cout<<n<<" : "<<mi<<" "<<mj<<" "<<mk<<endl;
}

ll find1(int n){
    int mn = max(1, n-6);
    ll mlcm = 0;
    ll mi, mj, mk;
    fore(i, mn, n+1){
        fore(j, mn, n+1){
            fore(k, mn, n+1){
                ll lc = lcm3(i,j,k);
                if(lc>mlcm){
                    mlcm = lc;
                    mi = i; mj = j; mk = k;
                }
            }
        }
    }

    // cout<<n<<" : "<<mi<<" "<<mj<<" "<<mk<<endl; 

    return mi*mj*mk;
}

int main(){
    int n;
    while(cin>>n){
        ll a = find1(n);
        cout<<a<<endl;
    }
                
    return 0;
}