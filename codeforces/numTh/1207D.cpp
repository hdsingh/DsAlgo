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
const int mod = 998244353;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

const int maxn = 3e5+1;
vl fact(maxn);
void preCalcFact(){
    fact[1] = 1;
    fore(i, 2, maxn){
        fact[i] = fact[i-1]*i%mod;
    }
}


// Good = Total(n!) - (sorted1 + sorted2  - common)
int main(){
    preCalcFact();
    int n;
    while(cin>>n){
        vector<pii> a(n);
        map<int, int> c1;
        map<int, int> c2;
        ll s1(0), s2(0), common(0);
        forn(i, n){
            cin>>a[i].first>>a[i].second;
            c1[a[i].first]++;
            c2[a[i].second]++;
        }

        // sort by 1
        sort(all(a), [](pii &p, pii &q){
            return p.first<q.first;
        });

        // check a sorted
        bool a_sorted = true;
        fore(i,1, n){
            if(a[i-1].first>a[i].first){
                a_sorted = false;
                break;
            }
        }
        if(a_sorted){
            s1 = 1;
            // c1! * c2! * c3! ..
            for(auto x: c1){
                s1 = fact[x.second] * s1 % mod;
            }
        }else 
            s1 = 0;

        // sort by 2
        sort(all(a), [](pii &p, pii &q){
            return p.second<q.second;
        });
    
        // check b sorted
        bool b_sorted = true;
        fore(i,1, n){
            if(a[i-1].second>a[i].second){
                b_sorted = false;
                break;
            }
        }

        if(b_sorted){
            s2 = 1;
            // c1! * c2! * c3! ..
            for(auto x: c2){
                s2 = fact[x.second] * s2 % mod;
            }
        }else 
            s2 = 0;
        
        if(a_sorted && b_sorted){
            // Common // by 1 and if both of 1 are equal then by b
            sort(all(a), [](pii &p, pii &q){
                if(p.first==q.first)
                    return p.second<q.second;
                return p.first<q.first;
            });

            // check b sorted
            b_sorted = true;
            fore(i,1, n){
                if(a[i-1].second>a[i].second){
                    b_sorted = false;
                    break;
                }
            }

            if(b_sorted){
                common = 1;
                map<pii, int> m;
                for(auto x: a)
                    m[x]++;
                
                for(auto x: m)
                    common = common*fact[x.second]%mod;
            }else
                common = 0;
        }

        // ll bad =  s1 + s2 - common;
        // ll good = fact[n] - bad ;
        // // good = fact[n] - s1 - s2 + common;
        // deb3(s1, s2, common);
        ll good = fact[n];
        add_self(good, mod - s1);
        add_self(good, mod - s2);
        add_self(good, common);

        cout<<good<<endl;

    }
    return 0;
}