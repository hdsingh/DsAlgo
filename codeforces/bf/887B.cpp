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
    string s;
    while(cin>>s){
        int n = s.size();
        vi preA(n+1);
        vi preB(n+1);

        for(int i=1; i<=n; i++){
            char c = s[i-1];
            preA[i] = preA[i-1] + (c=='a' ? 1 : 0);
            preB[i] = preB[i-1] + (c=='b' ? 1 : 0);
        }

        int res = 0;
        for(int i=0; i<=n; i++){
            int as = preA[i];
            int mx_ba = 0;
            for(int j=i+1; j<=n; j++){
                int bs = preB[j] - preB[i];
                int nxt_as = preA[n] - preA[j];

                int ba  = bs+nxt_as;
                mx_ba = max(mx_ba, ba);
                
            }
            int ans = as + mx_ba;
            res = max(ans, res);
        }
        cout<<res<<endl;

    }

    return 0;
}