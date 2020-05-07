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

template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(const T &v){if(sz(v)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(v[0]); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<sz(v); i++){cout<<i<<" {";for(auto j = 0; j!=sz(v[i]); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// For each col, independently find the cnt-> number of ele that will
// be at correct pos, if shifted by i
// Then for each cyclicty, check the moves req,
// moves req for cyclicity i = (i + (n - cnt[i])) (i up shift, + changes)
// Then for each element we need to check its cyclicity
// to find shift for a[i][j], it correct pos will be a[i][j]/m,
// hence the shift req from i, = (i-pos + n)%n (we need to go from i to pos 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        vvi a(n,vi(m));
        forn(i,n)
            forn(j,m){
                cin>>a[i][j];
                --a[i][j];
            }
        ll moves = 0;

        forn(j,m){
            vector<int> cnt(n+1);
            forn(i,n){
                int col = a[i][j]%m;
                if(col!=j) continue;
                int row = a[i][j]/m;
                if(row>=n) continue;
                int cyclicity = (i - row + n)%n;
                cnt[cyclicity]++;
            }

            int mn_moves = n; // replace all
            forn(i,n){
                mn_moves = min(mn_moves, (i + n - cnt[i]));
            }

            moves+=mn_moves;
        }

        cout<<moves<<endl;

    }
    return 0;
}