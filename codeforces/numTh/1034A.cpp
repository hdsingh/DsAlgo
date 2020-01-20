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
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

const int N = 1.5*1e7;

vi primeFact(int &n){
    vi fact;
    for(int d=2; d*d<=n; d++){
        if(n%d==0){
            while(n%d==0)
                n/=d;
            fact.pb(d);
        }
    }
    if(n>1)
        fact.pb(n);
    return fact;
}

int main(){
    vi lp(N+1);
    vi pr;
    // for(int i=2; i<=N; i++){
    //     if(!lp[i]){
    //         for(int j=i; j<=N; j+=i)
    //             if(!lp[j])
    //                 lp[j] = i;
    //     }
    // }

    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }

    int n,x;
    // vvi facts = prefact(MAXN);
    while(cin>>n){
        vi a(n);
        forn(i, n){
            cin>>a[i];
        }
        int gc = a[0];
        fore(i,1, n){
            gc = __gcd(gc, a[i]);
        }

        // deb(gc);
        // divide by gc
        forn(i,n)
            a[i]/=gc;

        map<int, int> m;
        for(int &x: a){
            while(x>1){
                int p = lp[x];
                while(x%p==0)
                    x/=p;
                m[p]++;
            }
        }

        int mx = 0;
        for(auto x: m){
            mx = max(x.second, mx);
        }

        int ans = n-mx;
        if(ans==n)
            cout<<-1<<endl;
        else 
            cout<<ans<<endl;

    }
    return 0;
}