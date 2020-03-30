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

int main(){
    int q,n;
    cin>>q;
    while(q--){
        cin>>n; 
        vi t(n);
        forn(i,n) cin>>t[i];

        // all eq
        bool all_eq = true;
        fore(i,1,n){
            if(t[i]!=t[0]){
                all_eq = false;
                break;
            }
        }

        if(all_eq){
            cout<<1<<endl;
            forn(i,n) cout<<1<<" ";
            cout<<endl;
            continue;
        }

        // if n even, we can color in alternating cols
        if(n%2==0){
            cout<<2<<endl;
            forn(i,n) cout<<(i%2 + 1)<<" ";
            cout<<endl;
            continue;
        }

        // If two types are equal we can just merge them and the
        // remaining seq will act like even, (i,i+1 will have saem color)
        bool ok = false;
        forn(i,n){
            if(ok) continue;
            if(t[i]==t[(i+1)%n]){
                vi ans(n);
                int c = 0;
                fore(j,i+1, n){
                    ans[j] = c + 1;
                    c^=1;
                }

                c = 0;
                for(int j=i; j>=0; --j){
                    ans[j] = c + 1;
                    c^=1;
                }

                cout<<2<<endl;
                forn(j,n) cout<<ans[j]<<" ";
                cout<<endl;
                ok = true;
            }
        }
        if(ok) continue;

        cout<<3<<endl;
        forn(i,n-1) cout<< i%2 + 1 <<" ";
        cout<<3<<endl;

    }
    return 0;
}