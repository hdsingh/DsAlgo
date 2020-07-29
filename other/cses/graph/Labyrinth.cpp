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

#define x first
#define y second

const map<vi, char> dirs = {
    {{-1,0},'U'},
    {{0,1},'R'},
    {{1,0},'D'},
    {{0,-1},'L'},
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    while(cin>>n>>m){
        vs grid(n+2, string(m+2,'#'));
        vector<vector<pii>> par(n+2, vector<pii>(m+2));
        vs saveDir(n+2, string(m+2,'.'));
        pii pA, pB;
        fore(i,1,n+1){
            fore(j,1,m+1){
                cin>>grid[i][j];
                if(grid[i][j]=='A'){
                    pA = {i,j};
                }else if(grid[i][j]=='B'){
                    pB = {i,j};
                }
            }
        }

        vector<pii> q;
        q.pb(pA);
        grid[pA.x][pA.y] = '#';

        int steps = 0;
        bool found = 0;
        while(sz(q)){
            if(found) break;
            vector<pii> nq;
            ++steps;
            for(auto top: q){
                if(found) break;
                for(auto dir: dirs){
                    int nx = top.x + dir.x[0];
                    int ny = top.y + dir.x[1];
                    if(grid[nx][ny]=='#') continue;
                    nq.pb({nx,ny});
                    par[nx][ny] = top;
                    saveDir[nx][ny] = dir.y;
                    if(grid[nx][ny]=='B'){
                        found = 1; break;
                    }
                    grid[nx][ny] = '#';
                }
            }
            q = nq;
        }

        if(!found){
            cout<<"NO\n"; continue;
        }
        cout<<"YES\n";
        string ans;
        pii cur = pB;
        while(cur!=pA){
            ans+=saveDir[cur.x][cur.y];
            cur = par[cur.x][cur.y];
        }
        reverse(all(ans));
        cout<<steps<<"\n"<<ans<<"\n";

    }
    return 0;
}

