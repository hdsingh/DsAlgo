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

// we have to color each vertex as 1, 2, 3
// such that there are n1, n2, n3, vertex having (1,2,3).
// Also |col_u - col_v| = 1;
// i.e 1->2, 3->2, 2->1 or 2->3
// so from odd to even number. hence there are 2 groups
// So the graph must be bipartite.
// Since there can be several comnnected components,
// for each comp, we need to divide it into two partitions, which are bipartite
// but we are still not sure to which one 2 should be assigned and (3,1) to which.
// lets say (l,r) be size of each comp
// Hence we will use dp, dp[i][j] = true, if it is possible to assign till ith components
// color 2 to j vertices.
// dp[0][0] = true;
// if(dp[i][j] is true) then dp[i+1][j+l], and dp[i+1][j+r] will also be true
// and now we should backtrack, the coloring
// To do this efficiently, simple idea is to use -1 for impossible, if possible by size of left comp
// and 1 if possible by size of right comp

const int nax = 5e3+5;
int n, n1,n2,n3,m;
vi col(nax,-1);
vvi cur_comp;
vector<vvi> comps; // { {l1_vec, r2_vec}, {l2_vec, r2_vec}}
vvi adj(nax);
bool biparitite = true;

void bfs(int x){
    queue<int> q;
    q.push(x);
    col[x] = 0;
    cur_comp[col[x]].pb(x);

    while(!q.empty()){
        int top = q.front(); q.pop();
        for(auto ad: adj[top]){
            if(col[ad]==-1){
                col[ad] = (col[top]^1);
                cur_comp[col[ad]].pb(ad);
                q.push(ad);
            }else{
                biparitite&=(col[ad]!=col[top]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>n1>>n2>>n3;
    int u,v;
    forn(i,m){
        cin>>u>>v;
        adj[u].pb(v), adj[v].pb(u);
    }
    
    // comps.push_back({{0},{0}}); // counter 0th idx
    fore(i,1,n+1){
        if(col[i]==-1){
            cur_comp.clear(); cur_comp.resize(2);
            bfs(i);
            comps.pb(cur_comp);
        }
    }

    // deb(biparitite);
    if(!biparitite){
        cout<<"NO\n";
        return 0;
    }

    int csz = sz(comps);
    // deb(csz);

    // for(auto comp: comps){
    //     print_vv(comp);
    // }

    vvi dp(csz+1, vi(n+1, -1));
    // is it possible till ith comp, to have j vertices colored as 2
    // dp[csz][n2]== true will be final ans.

    dp[0][0] = 1;
    
    fore(i,0,csz){
        assert(sz(comps[i])==2);
        int l = sz(comps[i][0]), r = sz(comps[i][1]);
        forn(j,n){
            if(~dp[i][j]){
                // deb(i,j);
                dp[i+1][j+l] = 0;
                dp[i+1][j+r] = 1;
            }
        }
    }

    if(dp[csz][n2]==-1){
        cout<<"NO\n"; 
        return 0;
    }

    // print_vv(dp);

    // back track and develop final ans

    for(int i=csz; i>=1; --i){
        assert(~dp[i][n2]);
        if(dp[i][n2]==0){
            int s = sz(comps[i-1][0]);
            n2-=s;
            for(auto x: comps[i-1][0])
                col[x] = 2;
            for(auto x: comps[i-1][1])
                if(n1>0)
                    col[x] = 1, n1--;
                else 
                    col[x] = 3, n3--;

        }else{
            int s = sz(comps[i-1][1]);

            n2-=s;
            assert(n2>=0);
            for(auto x: comps[i-1][1])
                col[x] = 2;
            for(auto x: comps[i-1][0])
                if(n1>0)
                    col[x] = 1, n1--;
                else 
                    col[x] = 3, n3--;
        }
    }

    // deb(n1,n2,n3);
    assert(n2==0), assert(n1==0), assert(n3==0);

    cout<<"YES\n";
    fore(i,1,n+1) cout<<col[i];
    cout<<endl;

    return 0;
}