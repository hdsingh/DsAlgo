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

char c;
int n,m,k,x,y;
vvi graph;
unordered_map<int, int> grpCnt;
int grpId;
vvi dirs =  {{0,1},{1,0},{-1,0},{0,-1}};

void dfs(int x, int y, const int grpId){
    graph[x][y] = grpId; //visited

    for(auto dir: dirs){
        int nx = x + dir[0];
        int ny = y + dir[1];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

        if(graph[nx][ny]==0) grpCnt[grpId]++;
        else if(graph[nx][ny]==1) dfs(nx, ny, grpId);
    }    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(cin>>n>>m>>k){
        graph.clear();
        graph.resize(n, vi(m));
        grpId = 2;
        grpCnt.clear();
        
        forn(i,n)
            forn(j,m){
                cin>>c;
                graph[i][j] = c=='.';
            }
        
        forn(i,k){
            cin>>x>>y;
            --x;--y;
            if(graph[x][y]==1){
                dfs(x,y, grpId++);
                cout<<grpCnt[graph[x][y]]<<endl;
            }else{
                cout<<grpCnt[graph[x][y]]<<endl;
            }
        }
    }

    return 0;
}