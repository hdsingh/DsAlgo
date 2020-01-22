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

int main(){
    int n, k;
    scanf("%d %d\n", &n, &k);
    vi a(n);
    forn(i,n)   
        scanf("%d ", &a[i]);

    map<vector<pii>, int> m;
    ll cnt = 0;
    forn(i, n){
        int x = a[i];
        vector<pii> pc, npc; //prime count, new prime count
        for(int j=2; j*j<=x; j++){
            if(x%j==0){
                int c = 0;
                while(x%j==0){
                    x/=j;
                    c++;
                }
                if(c%k)
                    pc.pb({j, c%k});
            }
        }
        if(x>1)
            pc.pb({x, 1});

        // in order to get p^k, we need a list in which count of prime is: k - present count
        for(auto sth: pc){
            npc.pb({sth.first, k - sth.second});
        }
        cnt+=m[npc];
        m[pc]++;    
    }

    printf("%lld\n", cnt);

    return 0;
}