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

const int N = 3e5+10;
int n;
int a[2][N];
ll s123[2][N], s321[2][N], s111[2][N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,2)
        forn(j,n)
            cin>>a[i][j];

    forn(i,2){
        for(int j=n-1; j>=0; --j){
            s123[i][j] = s123[i][j+1] + (j+1) * 1LL * a[i][j];
            s321[i][j] = s321[i][j+1] + (n-j) * 1LL * a[i][j];
            s111[i][j] = s111[i][j+1] + a[i][j];
        }
    }

    ll res=0, sum=0;

    for(int i=0, j=0; j<n; ++j, i^=1){
        ll nres = sum;
        nres += s123[i][j] + j * 1LL * s111[i][j];
        nres += s321[i^1][j] + (j+n) * 1LL * s111[i^1][j];

        res = max(res, nres);

        sum+=a[i][j] *1LL * (j+j+1);
        sum+=a[i^1][j] * 1LL * (j+j+2);
    }

    for(int j=0; j<n; ++j) res-=a[0][j] + a[1][j];
    cout<<res<<endl;

    return 0;