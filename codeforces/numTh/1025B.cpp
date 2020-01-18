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

// Prime factorisation
void add_divisors(int x, set<int> &cdiv){
    for(int i=2; i*i<=x; i++){
        if(x%i==0){
            while(x%i==0)
                x/=i;
            cdiv.insert(i);
        }
    }
    if(x>1)
        cdiv.insert(x);
    // print(cdiv);
}

int main(){
    int n, x, y;
    cin>>n;
        set<int> cdiv;
        cin>>x;
        cin>>y;
        add_divisors(x, cdiv);
        add_divisors(y, cdiv);

        bool no_common = cdiv.empty() ? true : false;

        for(int i=0; i<n-1; i++){
            cin>>x; 
            cin>>y;

            vi todel;
            for(int div: cdiv){
                if(x%div!=0 && y%div!=0){
                    todel.pb(div);
                }
            }

            for(int de : todel)
                cdiv.erase(de);
            
            if(cdiv.empty()){
                no_common = true;
                break;
            }
        }
        if(no_common)
            cout<<-1<<endl;
        else{
            cout<<*cdiv.begin()<<endl;
        }
    return 0;
}