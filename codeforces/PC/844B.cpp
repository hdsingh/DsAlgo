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

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

int main(){
    int n, m, x;
    while(cin>>n>>m){
        ll ans = -n*m;
        vector<map<int,int>> rcnt(n), ccnt(m);//row, col count
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>x;
                rcnt[i][x]++;
                ccnt[j][x]++;
            }
        }

        for(auto cnt: {rcnt, ccnt}){
            int sz = cnt.size();
            for(int i=0; i<sz; i++){
                int b = cnt[i][0];
                int w = cnt[i][1];

                ans += (1LL<<b) - 1; // Summation over r : pow(2, n) (-1 for C(n,0))
                ans += (1LL<<w) - 1;

                // for(int clr: {b, w}){
                //     for(int j=2; j<=clr; j++){
                //         ans+= C(clr, j);
                //     }
                // }
            }
        }

        printf("%lld\n", ans);
    } 
    return 0;
}