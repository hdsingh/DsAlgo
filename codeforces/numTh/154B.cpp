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

const int N = 1e5+1;
vi lp(N+1);

void calcLp(){
    for(int i=2; i<=N; i++)
        if(!lp[i])
            for(int j=i; j<=N; j+=i)
                if(!lp[j])
                    lp[j] = i;

}

vi findFact(int n){
    vi facts;
    while(n>1){
        int p = lp[n];
        while(n%p==0)
            n/=p;
        facts.pb(p);
    }
    return facts;
}

int main(){
    calcLp();
    int n,m;
    scanf("%d %d\n", &n, &m);
    char c; int x;
    map<int, bool> on;
    map<int, int> factInUse;
    while(m--){
        scanf("%c %d\n", &c, &x);
        
        if(c=='+'){
            if(on[x]){
                printf("Already on\n");
            }else{
                // turn on
                bool possible = true;
                vi facts = findFact(x);

                for(int f: facts){
                    if(factInUse[f]){
                        possible = false;
                        printf("Conflict with %d\n", factInUse[f]);
                        break;
                    }
                }
                if(possible){
                    on[x] = true;
                    for(int f: facts){
                        factInUse[f] = x;
                    }
                    printf("Success\n");
                }
            }
        }else{ //off -
            if(!on[x]){
               printf("Already off\n"); 
            }else{ //turn off
                on[x] = false;
                vi facts = findFact(x);
                for(int f: facts)
                    factInUse[f] = 0;                

                printf("Success\n");
            }
        }
    }
    return 0;
}