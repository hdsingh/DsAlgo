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

// by observation:
// We can differentiate each cell as good or bad;
// A good cell is having some adjacent cell of same color.
// In each iteration a good cell turns its adjacent bad to good 
// one and the process continues till each cell turns into good.
// A good cell keeps on changing its color in every iteration,
// while bad keeps its color till it does not becomes good
// So a simple solution is to start bfs from every good cell,
// and note the time(iterations) required for each cell to be good.
// if p<time[i][j], its color is same,
// else alternates every time

vvi grid;
vvi tme; // time
vvi state; // record gd/bd

const int gd = 1; //good
const int bd = 0; // bad

int n,m,T;

void bfs(){
    vector<pii> q;
    forn(i,n)
        forn(j,m)
            if(state[i][j]==gd)
                q.pb({i,j});

    int t = 0;
    while(!q.empty()){
        vector<pii> nq;

        forn(l,sz(q)){
            pii top = q[l];
            int x = top.first, y = top.second;
            tme[x][y] = t;

            // push adj bad elements to good
            if(x && state[x-1][y]==bd) state[x-1][y]=gd, nq.pb({x-1,y});
            if(y && state[x][y-1]==bd) state[x][y-1]=gd, nq.pb({x,y-1});
            if(x+1<n && state[x+1][y]==bd) state[x+1][y]=gd, nq.pb({x+1,y});
            if(y+1<m && state[x][y+1]==bd) state[x][y+1]=gd, nq.pb({x,y+1});
        }

        swap(q,nq);
        ++t;
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin>>n>>m>>T){
        tme.clear(); tme.resize(n,vi(m));
        state.clear(); state.resize(n, vi(m));
        grid.clear(); grid.resize(n,vi(m));

        char c;
        forn(i,n)
            forn(j,m){
                cin>>c;
                grid[i][j] = (c=='1');
            }
        // print_vv(grid);
        
        // fill the state with good/bad
        // good if anyone of its adj has same col
        bool all_bad = true;
        forn(i,n){
            forn(j,m){
                bool good = false;
                if(i) good|=(grid[i][j]==grid[i-1][j]);
                if(j) good|=(grid[i][j]==grid[i][j-1]);
                if(i+1<n) good|=(grid[i][j]==grid[i+1][j]);
                if(j+1<m) good|=(grid[i][j]==grid[i][j+1]);
                state[i][j] = good;

                all_bad&=(state[i][j]!=gd);
            }
        }

        // deb(all_bad);

        bfs();


        // print_vv(tme);

        ll i,j,p;
        while(T--){
            cin>>i>>j>>p;
            --i,--j;
            if(all_bad){
                cout<<grid[i][j]<<"\n";
                continue;
            }

            int val = grid[i][j];
            if(p<tme[i][j]){
                cout<<val<<"\n";
            }else{
                ll dif = p - tme[i][j];
                int pol = dif%2;
                if(pol)
                    cout<<!val<<"\n";
                else 
                    cout<<val<<"\n";
            }

        }

    }
    return 0;
}