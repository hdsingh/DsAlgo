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
    int n,x;
    while(cin>>n){
        // Prove a seq in non-in(dec)
        vi dec; //all inc
        vi firsts; vi lasts;
        forn(i, n){
            int len; cin>>len;
            
            int f, l; //first, last
            cin>>f;
            int prev = f;
            l = f;

            bool decrease = true;

            forn(j, len-1){
                cin>>l;
                if(prev<l)
                    decrease = false;
                prev = l;
            }

            if(decrease){
                dec.pb(i);
                firsts.pb(f);
                lasts.pb(l);
            }
        }


        sort(all(firsts));
        sort(all(lasts));
        ll res = (ll)n * n;
        int j=0;

        for(int i=0; i<firsts.size(); i++){
            while(j<lasts.size() && firsts[i] > lasts[j]) 
                j++;
            res -= (lasts.size() - j);
        }
        

        cout<<res<<endl;
    }
    return 0;
}