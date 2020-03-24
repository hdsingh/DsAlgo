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
typedef long double ld;
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

ld maxv = 1e18 + 10;
ll n,p, sum;
vl a, b;
vector<ld> c; // a/b, seconds it can survive without charge

bool canSurvive(ld t){ // check if can survive for time t
    ld totNeed = 0;
    forn(i,n){
        ld need = max((ld)0, (t - c[i])*a[i] );
        totNeed+=need;
    }
    ld supply  = p*t;
    return totNeed<=supply;
}


int main(){
    while(cin>>n>>p){
        sum = 0;
        a.clear(), b.clear(); a.resize(n), b.resize(n);
        c.clear(), c.resize(n);

        forn(i,n){
            cin>>a[i]>>b[i];
            c[i] = ((ld)b[i])/(ld)a[i];
            sum+=a[i];
        }
        
        if(sum<=p){
            printf("-1\n");
            continue;
        }

        // since doubles are involved here it is better to 
        // approximate the steps 
        ld lt = 0, rt = maxv;
        for(int i=0; i<220; ++i){
            ld mid = lt + (rt-lt)/2;
            if(canSurvive(mid))
                lt = mid;
            else 
                rt = mid;
        }

        if(lt>maxv-100)
            printf("-1\n");
        else 
            printf("%10f\n",(double)lt);

    }
    return 0;
}