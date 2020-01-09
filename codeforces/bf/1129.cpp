#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

int main(){
    int n,m;
    while(cin>>n>>m){
        vi out(n);
        vi min_dist(n, n-1);
        vvi dist(n, vi(n));

        forn(i, n){
            forn(j,n){
                dist[i][j] = j-i + n*(j<i);
            }
        }
        // print_vv(dist);
        forn(i, m){
            int u, v;
            cin>>u>>v;
            --u, --v;
            out[u]++;
            min_dist[u] = min(min_dist[u], dist[u][v]);
        }

        forn(s,n){
            int ans = 0;
            forn(i, n){
                if(out[i]>0){
                    ans = max(ans, dist[s][i] + n*(out[i]-1) + min_dist[i]);
                }
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}