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

int n,m,t;
vvi adj;
vi vis;
set<int> cycle;

void dfs(int x){
    cycle.insert(x);
    for(auto ad: adj[x])
        if(!vis[ad]){
            vis[ad] = 1;
            dfs(ad);
        }
}

void sort_it(vi &a, set<int> &cycle){
    vi cp;
    for(auto x: cycle)
        cp.push_back(a[x]);
    sort(all(cp));

    int i = 0;
    for(auto x: cycle)
        a[x] = cp[i++];
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        adj.clear(); vis.clear();
        adj.resize(n); vis.resize(n);

        vi a(n), p(m);
        forn(i,n) cin>>a[i];

        forn(i,m){
            cin>>p[i];
            --p[i];
        }

        sort(all(p));
        for(auto x:p)
            if(x+1<n) adj[x].push_back(x+1);
        
        // print_vv(adj);

        for(auto x: p){
            if(!vis[x]){
                vis[x] = 1;
                cycle.clear();
                dfs(x);
                // print(vi(all(cycle)));

                sort_it(a, cycle);
            }
        }

        // print(a);
        string out = is_sorted(all(a)) ? "YES" : "NO";
        cout<<out<<endl;


    }
    return 0;
}

int main1(){
    int t,n,m,x;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vi a(n), p(n);
        forn(i,n) cin>>a[i];
        forn(i,m){
            cin>>x;
            p[x-1] = 1;
        }

        bool ok;
        while(true){
            ok = false;
            forn(i,n)
                if(p[i] && a[i]>a[i+1]){
                    ok = true;
                    swap(a[i],a[i+1]);
                }

            if(!ok) break;
        }

        string out = is_sorted(all(a)) ? "YES" : "NO";
        cout<<out<<endl;
        
    }
    return 0;
}