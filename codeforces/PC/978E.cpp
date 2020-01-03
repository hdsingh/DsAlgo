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
    int n, w, x;
    while(cin>>n>>w){
        int b = 0;
        int minB = INT_MAX;
        int maxB = INT_MIN;
        
        while(n--){
            cin>>x;
            b+=x;
            minB = min(b, minB);
            maxB = max(b, maxB);
        }

        if(-minB > w || maxB>w){
            cout<<0<<endl;
            return 0;
        }

        int l, r;
        if(minB<0)
            l = -minB;
        else
            l = 0;
        
        if(maxB<=0)
            r = w;
        else 
            r = w - maxB;
        
        // deb(l); deb(r);
        cout<<max(0, r-l+1)<<endl;

        // cout<<endl;

    }
    return 0;
}