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

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string> a(n+2, string(m+2,'#'));
        char c;
        fore(i,1,n+1){
            fore(j,1,m+1){
                cin>>a[i][j];
            }
        }

        // fore(i,1,n+1){
        //     fore(j,1,m+1){
        //         cout<<a[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;        

        int cntB = 0, cntG = 0;
        fore(i,1,n+1) 
            fore(j,1,m+1){
                if(a[i][j]=='B') ++cntB;
                else if(a[i][j]=='G') ++cntG;
            }
        
        if(!cntG){
            cout<<"Yes\n";
            continue;
        }

        fore(i,1,n+1){
            fore(j,1,m+1){
                if(a[i][j]=='B'){
                    if(a[i-1][j]=='.') a[i-1][j] = '#';
                    if(a[i][j-1]=='.') a[i][j-1] = '#';
                    if(a[i+1][j]=='.') a[i+1][j] = '#';
                    if(a[i][j+1]=='.') a[i][j+1] = '#';
                }
            }
        }

        // fore(i,1,n+1){
        //     fore(j,1,m+1){
        //         cout<<a[i][j];
        //     }
        //     cout<<endl;
        // }  

        // cout<<endl;

        // check every good can escape
        // no bad can escape
        int cntg = 0;
        bool bseen = false;
        queue<pii> q;
        if(a[n][m]!='#'){
            q.push({n,m});
            a[n][m] = '#';

            while(!q.empty()){
                pii top = q.front(); q.pop();
                int i = top.first, j = top.second;
                vector<pii> dirs = {{i+1,j}, {i,j+1},{i-1,j},{i,j-1}};
                for(pii d: dirs){
                    if(a[d.first][d.second]=='G'){
                        a[d.first][d.second] = 'g';
                        cntg++;
                        q.push({d.first,d.second});
                    }else if(a[d.first][d.second]=='.'){
                        a[d.first][d.second] = '#';
                        q.push({d.first,d.second});
                    }else if(a[d.first][d.second]=='B'){
                        bseen = true; break;
                    }
                }
            }


        }


        // deb(bseen, cntg, cntG);

        if(bseen || (cntG!=cntg)){
            cout<<"No\n";
        }else{
            cout<<"Yes\n";
        }

        // cout<<endl;
    }
    return 0;
}