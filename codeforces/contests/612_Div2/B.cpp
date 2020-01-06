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
    int n,k;
    while(cin>>n>>k){
        vvi a(n);
        set<vi> s;
        int cnt = 0;

        string r;
        forn(i, n){
            cin>>r;
            vi v;
            for(char c: r)
                v.pb(c/3%3);
            
            a[i] = v;
            s.insert(v);
            
        }

        vi x, y, z; 
        z.resize(k);
        forn(i,n){
            fore(j, i+1, n){
                forn(l, k){
                    z[l] = (6 - a[i][l] - a[j][l])%3;
                }

                if(s.find(z)!=s.end())
                    cnt++;
            }
        }
        cout<<cnt/3<<endl;
    }
    
    return 0;
}
