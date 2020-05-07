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

// If a and b are not coprime, make them co-prime
// making coprime represents removing un-imp elememts
// ex: for a =10, b =70, we know the ele to be colored is always 10*n
// so we can rename 10,20,30,... to 1,2,3,4,..., since it doesnot affect coloring
// Now if we have painted a at pos in b, we can paint pos+b in b
// So bw these two locs (pos, pos+b) (has size b-1)
// We need to check what is the max amount of reds we can have.
// If max_reds>=k, then "REBEL" else "OBEY".
// max_reds in segment of size b-1 = ceil(b-1)/r
// The ceil is important here, because ex:
// for a = 3, b = 5,
// we have 5(,6,7,8,9),10 : 6 and 9 i.e two reds 

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; ll r,b,k;
    cin>>t;
    while(t--){
        cin>>r>>b>>k;

        ll gc = __gcd(r,b);
        r/=gc;
        b/=gc;
        if(r>b) swap(r,b);

        if((b-1 + r-1)/r>=k)
            cout<<"REBEL\n";
        else 
            cout<<"OBEY\n";

    }
    return 0;
}