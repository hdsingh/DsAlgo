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

int main(){
    int n;
    while(cin>>n){
        vi f(n+1);
        vi misix; //missing indexes
        set<int> misf;

        fore(i, 1, n+1)
            misf.insert(i);

        fore(i, 1, n+1){
            scanf("%d ", &f[i]);
            if(!f[i])
                misix.pb(i);
            else
                misf.erase(f[i]);
        }

        vi mis(all(misf));
        // print(mis); //misf 
        // print(misix);
        // cout<<endl;

        int sz = mis.size();
        // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        while(true){
            shuffle(all(mis), rng);
            bool good = true;
            forn(i, sz){
                if(misix[i]==mis[i]){
                    good = false;
                    break;
                }
            }

            if(good){
                forn(i, sz)
                    f[misix[i]] = mis[i];
                break;
            }
        }

        fore(i, 1 , n+1){
            printf("%d ", f[i]);
        }
        printf("\n");



    }
    return 0;
}