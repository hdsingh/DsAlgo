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
    int n, l;
    while(cin>>n>>l){
        scanf("\n");
        char c;

        vvi s(n, vi(l));
        forn(i, n){
            forn(j, l){
                scanf("%c", &c);
                s[i][j] = c-'0';
            }
            scanf("\n");
        }
        
        vi perm(l);
        forn(i, l)
            perm[i] = i;
        
    int ans = INT_MAX;
        do{
            int mi = INT_MAX; int mx = INT_MIN;
            forn(i, n){
                int val = 0;
                forn(j, l){
                    val = 10*val + s[i][perm[j]];
                }
                // cout<<i<<" "<<val<<endl;
                mi = min(mi, val);
                mx =max(mx, val);
            }
            ans = min(ans, mx-mi);

        }while(next_permutation(all(perm)));

        cout<<ans<<endl;

    }
    
    return 0;
}