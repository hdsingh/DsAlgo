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

const int MAXN = 250010;
vl fact(MAXN), inv(MAXN), finv(MAXN);

void precalc(int mod){
    int n = MAXN;
    
    fact[0] = finv[0] = inv[1] = 1;

    fore(i, 1, n){
        fact[i] = fact[i-1] * i % mod;
    }
}

int main(){
    ll n, mod;
    while(cin>>n>>mod){
        precalc(mod);
        ll ans = 0;
        for(int i=1; i<=n; i++){
            ans += (i * fact[i]%mod * fact[n-i+1]%mod)%mod;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
}

// Brute force
int main2(){
    int n, m;
    while(cin>>n){
        vi a;
        fore(i, 1, n+1)
            a.pb(i);
        
        ll happy = 0;
        deb(n);
        map<int, int> cnt;
        do{
            int fs = 0; // framed segment
            for(int l=0; l<n; l++){
                for(int r=l; r<n; r++){
                    // cout<<l<<" "<<r<<endl;
                    int mx = *max_element(a.begin() + l, a.begin() + r+1);
                    int mn = *min_element(a.begin() + l, a.begin() + r+1);

                    if((mx - mn) == (r-l))
                        fs++;
                }
            }
            // deb(fs);
            cnt[fs]++;
            happy +=fs;
        }while(next_permutation(all(a)));

        // for(auto a: cnt)    
        //     cout<<a.first<<" : "<<a.second<<endl;
        cout<<n<<" : "<<happy<<endl<<endl<<endl;;
    }
    return 0;
}