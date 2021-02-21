#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
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
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};
#define x first
#define y second

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n, m; cin>>n>>m;
        vs a(n);
        forn(i,n) cin>>a[i];
        vi good;
        forn(i,n){
            if(!good.empty()) break;
            fore(j,i+1,n){
                if(a[i][j]==a[j][i]){
                    good = {i+1,j+1};
                    break;
                }
            }
        }
        if(!good.empty()){
            cout<<"YES\n";
            forn(i,m+1){
                cout<<good[i%2]<<" ";
            }
            cout<<"\n";
            continue;
        }
        // aa or bb not found
        // so it would be ab, ba
        // if m is odd aba or bab will be pal for any pair
        if(m%2){
            cout<<"YES\n";
            forn(i,m+1){
                cout<<((i%2)+1)<<" ";
            }
            cout<<"\n";
            continue;
        }

        // m is even
        vvi aba(n), bab(n);
        forn(i,n){
            forn(j,n){
                if(i==j) continue;
                if(a[i][j]=='a' && a[j][i]=='b'){
                    aba[i].pb(j);
                }
                if(a[i][j]=='b' && a[j][i]=='a'){
                    bab[i].pb(j);
                }
            }
        }

        bool ok = 0;
        vi out; // {x,y,z}
        forn(x,n){
            if(ok) break;
            for(auto y: aba[x]){
                if(ok) break;
                for(auto z: aba[y]){
                    if(z!=x){
                        out = {x,y,z};
                        ok = 1; break;
                    }
                }
            }

            for(auto y: bab[x]){
                if(ok) break;
                for(auto z: bab[y]){
                    if(z!=x){
                        out = {x,y,z};
                        ok = 1; break;
                    }
                }
            }
        }

        if(ok){
            cout<<"YES\n";
            int x = out[0]+1, y = out[1]+1, z = out[2]+1;
            if((m/2)&1){
                cout<<x<<" "<<y<<" "<<z<<" ";
                forn(i,(m-1)/2){
                    if(i%2==0) cout<<y<<" "<<x<<" ";
                    else cout<<y<<" "<<z<<"\n";
                }
            }else{
                cout<<y<<" ";
                forn(i,m/4){
                    cout<<z<<" "<<y<<" "<<x<<" "<<y<<" ";
                }
                cout<<"\n";
            }
        }else{
            cout<<"NO\n";
        }
        
    }
    return 0;
}