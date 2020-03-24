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

#define x first
#define y second

pii st, fi; //start, finish

int n;
string s;
map<char, int> m({{'U',0},{'D',1},{'L',2},{'R',3}});
const vi dx = {0, 0, -1, 1};
const vi dy = {1, -1, 0, 0};

vector<pii> d;

int main(){
    while(cin>>st.x>>st.y>>fi.x>>fi.y){
        cin>>n>>s;
        d.clear();
        d.resize(n+1);

        for(int i=0; i<n; ++i){
            int id = m[s[i]];
            d[i+1] = {d[i].x + dx[id], d[i].y + dy[id]};
        }

        // Here d is prefix of the wind's movement
        // we calculate the distance that wind could move the ship
        // in mid days
        // from this pos, we can make k moves in any dir (because of k days)
        // So if we are able to reach in d days, we would definitely be able to reach in
        // days>d, hence we decrease right to reach in less days
        // else increase the days if we are unable to reach

        ll l = 0, r = 1e18;
        while(r-l>1){
            ll mid = l + (r-l)/2;
            ll cnt = mid/n, rem = mid%n;
            ll x = st.x + cnt * 1ll * d[n].x + d[rem].x;
            ll y = st.y + cnt * 1ll * d[n].y + d[rem].y;
            ll dist = abs(x - fi.x) + abs(y - fi.y);

            if(dist<=mid) // can reach
                r = mid; // try reaching in less days
            else 
                l = mid; // increase the days
        }

        if(r>=1e18) r = -1;
        cout<<r<<endl;
        
    } 
    return 0;
}