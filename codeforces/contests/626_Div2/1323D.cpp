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

int bf(vi &a){
    int out = 0;
    int n = a.size();
    forn(i,n){
        fore(j,i+1, n){
            out^=(a[i]+a[j]);
        }
    }
    return out;
}

// Ref: Tutorial + comments
// We will count for each bit. The bit will be on when the bits on at pos k are odd else off.
// To count the number of bits which set pos k, we will consider the pairs whose sum is (1<<k)
// To limit the bits we will take nums % (2^(k+1)). 
// So now to numbers upon adding can range from 0 to 2*(2^(k+1)).
// Only the values in range [2^k, 2^(k+1)) and [2^(k+1) + 2^(k), max val sum can take]
// will turn on the kth bit
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n){
        vi a(n); forn(i,n) cin>>a[i];

        sort(all(a));

        ll ans = 0;
        for(int k=0; k<27; ++k){
            vi b(n);
            forn(i,n) b[i] = a[i]%(1<<(k+1));
            sort(all(b));

            ll cnt = 0;
            forn(i,n){
                int l = lower_bound(b.begin()+i+1, b.end(), (1<<k) - b[i] ) - b.begin();
                int r = lower_bound(b.begin()+i+1, b.end(), (1<<(k+1)) -b[i] ) - b.begin();
                cnt+=r-l;

                l = lower_bound(b.begin()+i+1, b.end(), (1<<(k+1)) + (1<<k) - b[i] ) - b.begin();
                cnt+= n-l;
            }
            ans |= (1LL<<k) * (cnt&1); // if odd only then xor value at kth pos will be 1
        }
        cout<<ans<<endl;
        
    }
    return 0;
}