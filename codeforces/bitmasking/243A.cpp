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
        vi a(n);
        forn(i, n)
            scanf("%d ", &a[i]);
        
        set<int> uniq;
        set<int> m, newm;
        uniq.insert(a[0]);
        m.insert(a[0]);

        for(int i=1; i<n; i++){
            newm.clear();
            for(auto &s: m)
                newm.insert(s|a[i]);
            m = newm;
            m.insert(a[i]);

            
            for(auto &s: m)
                uniq.insert(s);
        }

        // for(auto &s: uniq)
        //     printf("%d ", s);
        // printf("\n");
        cout<<uniq.size()<<endl;
        
    }
    return 0;
}