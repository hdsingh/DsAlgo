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

// s = x + 2*(a&b)
// (s-x)/2 = a&b
// here x and a&b look complementary
// if ai==bi==a&b, then x=0, and we have no choice
// if x = 1, then {0,1} or {1,0}, hence 2 choices
// so each set bit in x corrsponds to 1 choice
// if a==0 and all bits are set, then in one case we will have x,0
// which as mentioned in the question is not required
// ex for 7,7 (111) -> (1,6), (6,1), (2,5),(5,2), (3,4), (4,3), (0,7), (7,0)
// all satisfy the condition however in (0,7) and (7,0) 0 is non positive hence -2
int main(){
    ll s, x;
    while(cin>>s>>x){
        ll a = (s-x)/2;

        if(a<0 || (a&x) || x + 2*a != s){
            cout<<0<<endl;
            continue;
        }

        int set_in_x = __builtin_popcountll(x);
        // deb(set_in_x);
        ll ans = (1LL<<set_in_x);
        if(a==0){   
            ans-=2;
        }
        cout<<ans<<endl;
        

    }
    return 0;
}