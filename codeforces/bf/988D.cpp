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
        forn(i,n)
            cin>>a[i];
        
        sort(all(a));
        vi res = {a[0]};

        forn(i, n){
            forn(j, 31){
                int lx = a[i] - (1<<j);
                int rx = a[i] + (1<<j);
                bool isl = binary_search(all(a), lx);
                bool isr = binary_search(all(a), rx);

                if(isl && isr && res.size()<3){
                    res = {lx, a[i], rx};
                }else if(isl && res.size()<2){
                    res = {lx, a[i]};
                }else if(isr && res.size()<2){
                    res = {rx, a[i]};
                }
            }
            if(res.size()==3)
                break;
        }

        cout<<res.size()<<endl;
        for(auto x: res)
            cout<<x<<" ";
        cout<<endl;
        cout<<endl;

    }
    
    return 0;
}