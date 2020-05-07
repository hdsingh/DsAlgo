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
 
vi find_divs(ll n){
    vi out;
    for(int i=2; i*i<=n; ++i){
        if(n%i==0){
            out.pb(i);
            if(n/i!=i)
                out.pb(n/i);
        }
    }
    out.pb(n);
    return out;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; 
    while(cin>>n){
        vi a(n);
        forn(i,n) cin>>a[i];
        int sum = accumulate(all(a),0);
        if(sum==1){
            cout<<-1<<endl;
            continue;
        }

        vi divs = find_divs(sum);

        ll min_moves = 1e18;

        for(auto d: divs){
            ll cur_moves = 0;
            vi group;

            forn(i,n){
                if(a[i]){
                    group.pb(i);
                    int gz = sz(group);
                    if(gz==d){
                        int median = (group[(gz-1)/2] + group[gz/2])/2;
                        for(auto p: group){
                            cur_moves+= abs(median-p);
                        }
                        group.clear();
                    }
                }
            }

            min_moves = min(min_moves, cur_moves);
        }
        cout<<min_moves<<endl;
    }
    return 0;
}