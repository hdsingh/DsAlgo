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
    int n, k;
    while(cin>>n>>k){
        vi a(n);
        forn(i, n)
            cin>>a[i];
        
        vvi vals(2 * 1e5 + 2);

        forn(i, n){
            int cur = a[i];
            int ops = 0;
            while(cur>0){
                vals[cur].pb(ops);
                cur>>=1;
                ++ops;
            }
        }

        int ans = inf;
        forn(i, 2*1e5+1){
            if(vals[i].size()>=k){
                sort(all(vals[i]));
                int val = accumulate(vals[i].begin(), vals[i].begin()+ k, 0);
                ans = min(ans, val);
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}