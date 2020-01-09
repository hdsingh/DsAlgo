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
    int n, m;
    while(cin>>n>>m){
        vi a(n);
        vvi segAffect(n); // ith segments affecting ith pos
        forn(i, n)
            cin>>a[i];
        
        vi acc(n);
        vvi segs;
        int l,r;
        forn(i, m){
            cin>>l>>r;
            --l; --r;
            segs.push_back({l,r});

            fore(j, l, r+1){
                --acc[j];
                segAffect[j].push_back(i);
            }
        }

        // print(acc);

        int mxdiff = 0;
        int grt_i = 0;
        forn(i, n){
            vi nacc = acc; //new acc
            for(auto s: segAffect[i]){
                for(int j= segs[s][0]; j<=segs[s][1]; j++){
                    ++nacc[j];
                }
            }

            // Apply nacc
            int mn = INT_MAX;
            int mx = INT_MIN;
            for(int k=0; k<n; k++){
                int x = a[k] + nacc[k];
                mn = min(x, mn);
                mx = max(x, mx);

            }

            if(mx-mn > mxdiff){
                mxdiff = mx-mn;
                grt_i = i;
            }
        }

        set<int> ans;
        forn(i, m)
            ans.insert(i);
        
        for(auto x: segAffect[grt_i]){
            ans.erase(x);
        }

        cout<<mxdiff<<endl;
        cout<<ans.size()<<endl;
        for(auto x: ans)
            cout<<x+1<<" ";
        cout<<endl<<endl;

    }
    return 0;
}