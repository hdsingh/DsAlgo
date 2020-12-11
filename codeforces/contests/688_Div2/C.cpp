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

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n; cin>>n;
        vvi grid(n, vi(n));
        forn(i,n) forn(j,n){
            char c; cin>>c; 
            grid[i][j] = c-'0';
        }
        if(n<=1){
            forn(i,10) cout<<0<<" ";
            cout<<"\n";
            continue;
        }
        // cout<<grid;
        auto handle = [&](int d){
            vl cols(n);
            forn(i,n){
                int lt = -1, rt = -1;
                forn(j,n){
                    if(grid[i][j]==d){
                        if(lt==-1) lt = j;
                        rt = j;
                    }
                }
                if(lt!=-1){
                    cols[i] = max({n-1-lt,rt,rt-lt});
                }
            }

            ll ans = 0;
            forn(i,n){
                if(!cols[i]) continue;
                for(int j=i+1; j<n; ++j){
                    if(cols[j]){
                        max_self(ans, cols[i]*(j-i));
                    }
                }

                for(int j=i-1; j>=0; --j){
                    if(cols[j]){
                        max_self(ans, cols[i]*(i-j));
                    }
                }
            }
        

            vi rows(n);
            forn(j,n){
                int lt = -1, rt = -1;
                forn(i,n){
                    if(grid[i][j]==d){
                        if(lt==-1) lt = i;
                        rt = i;
                    }
                }
                if(lt!=-1){
                    rows[j] = max({n-1-lt,rt,rt-lt});
                }
            }
            // cout<<cols<<rows;
            forn(i,n){
                if(!rows[i]) continue;
                for(int j=i+1; j<n; ++j){
                    if(rows[j]){
                        max_self(ans, rows[i]*(j-i));
                    }
                }

                for(int j=i-1; j>=0; --j){
                    if(rows[j]){
                        max_self(ans, rows[i]*(i-j));
                    }
                }
            }
        
            // deb(d,ans);
            return ans;
        };

        handle(1);
        forn(i,10){
            cout<<handle(i)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}