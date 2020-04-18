#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

vi factors(int k){
    vi out;
    out.pb(1);
    for(int i=2; i*i<=k; ++i){
        if(k%i==0)
            out.pb(i);
    }
    return out;
}

ll calc(int f1, int f2, int x1, int y1){
    ll ans = 0;
    if(f1<=x1 && f2<=y1){
        ans+=(x1-f1+1)*(y1-f2+1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k, x;
    while(cin>>n>>m>>k){
        map<int,int> cnta, cntb;
        
        int sum = 0;
        forn(i,n){
            cin>>x;
            sum+=x;
            if((!x && sum) || i==n-1){
                cnta[sum]++;
                sum = 0;
            }
        }

        sum = 0;
        forn(i,m){
            cin>>x;
            sum+=x;
            if((!x && sum) || i==m-1){
                cntb[sum]++;
                sum = 0;
            }
        }

        // print_m(cnta);
        // print_m(cntb);

        // factors of k
        vi fs = factors(k);
        // print(fs);

        ll out = 0;
        for(auto p1: cnta){
            for(auto p2: cntb){
                for(auto f: fs){
                    int f2 = k/f;
                    out+= calc(f, f2, p1.first, p2.first)*(ll)p1.second*(ll)p2.second;
                    if(f!=f2)
                        out+= calc(f2, f, p1.first, p2.first)*(ll)p1.second*(ll)p2.second;
                }
            }
        }
        cout<<out<<endl;
    }
    return 0;
}
