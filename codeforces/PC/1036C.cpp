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


const int MAXN = 20;
ll C[MAXN+1][MAXN+1];
// vvl C(MAXN+1, vl(MAXN+1));

void precalc(){
    C[0][0] = 1;
    for(int i=1; i<=MAXN; i++){
        C[i][0] = C[i][i] =1;

        for(int j=1; j<=i/2; j++)
            C[i][j] = C[i][i-j] = C[i-1][j-1] + C[i-1][j];
    }

}

ll Comb(int n, int k){
    if(k<0 || k>n) return 0;
    return C[n][k];
}

ll get(int n, int k){
    ll ans = 0;
    forn(i, k+1)
        ans+=Comb(n, i) * pow(9, i);
    
    return ans;
}

ll classy(ll x){
    string s = to_string(x);

    ll ans = 0;
    int cur = 3;
    int n = s.size();

    forn(i,n){
        if(s[i]=='0') continue;
        int x = n-i;
        ans+=get(x-1, cur);
        --cur;
        if(cur==-1) break;
        ans+= get(x-1, cur) * (s[i]-'1');
    }

    return ans;
}

int main(){
    precalc();
    
    int t;
    ll x, y;
    cin>>t;
    while(t--){
        cin>>x>>y;
        ll ans = classy(y+1) - classy(x);
        cout<<ans<<endl;
    }

    return 0;
}