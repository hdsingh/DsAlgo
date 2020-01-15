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
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

vvi precompute_divisors(int n){
    vvi div(n+1); //divisors
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            div[j].pb(i);
        }
    }
    return div;
}

int main(){
    vvi divisors = precompute_divisors(101);
    int n;
    while(cin>>n){
        vi a(n);
        forn(i, n)
            cin>>a[i];
        
        sort(all(a));

        int sum = accumulate(all(a), 0);

        int minval = sum;
        for(int i=1; i<n; i++){
            for(int d : divisors[a[i]]){
                int val = sum - a[i] - a[0] + a[i]/d + a[0]*d;
                min_self(minval, val);
            }
        }

        cout<<minval<<endl;
    }
    return 0;
}