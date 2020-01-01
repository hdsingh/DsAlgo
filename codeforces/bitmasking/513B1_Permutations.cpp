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

int f(vi &a){
    int n = a.size();
    int res = 0;
    fore(i,0,n){
        fore(j,i,n){
            int mi = INT_MAX;
            fore(k, i, j+1){
                mi = min(mi, a[k]);
            }
            res+=mi;
        }
    }
    return res;
}

int main(){
    vi a = {2,1};
    int n, m;
    while(cin>>n>>m){
        vi a;
        fore(i,1,n+1)
            a.pb(i);
        
        int mx = f(a);
        m--;
        while(m){
            next_permutation(all(a));
            if(f(a)==mx)
                m--;
        }

        forn(i,n)
            printf("%d ", a[i]);
        printf("\n");


    }
    return 0;
}