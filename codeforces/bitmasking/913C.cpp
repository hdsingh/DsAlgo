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

const int maxL = 20;
const int maxb = 5;

int main(){
    int n, L;
    while(cin>>n>>L){
        vi c(n);
        forn(i, n)
            cin>>c[i];
        
        fore(i, 1, n)
            c[i] = min(2*c[i-1], c[i]);
        
        // print(c);

        ll ans = 4e18;
        ll sum = 0;
        for(int i=n-1; i>=0; i--){
            ll need = L/(1<<i);
            sum += need * c[i];
            L -= need<<i; //need * 2^i
            ans = min(ans, sum + (L>0) * c[i]);
        }
        cout<<ans<<endl;
    }
}