#include <bits/stdc++.h>
using namespace std;
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

void bin(unsigned n) 
{ 
    unsigned i; 
    for (i = 1 << 16; i > 0; i = i / 2) 
        (n & i)? printf("1"): printf("0"); 
} 

int main(){
    ll a, b;
    while(cin>>a>>b){
        int cnt = 0;
        int t = log2(b);
        // deb(t);

        for(int i=0; i<=t; i++){
            ll mask = (1LL<<(i+1)) - 1;
            // deb(mask);
            for(int j=i-1; j>=0; j--){
                ll x = mask ^ (1LL<<j);
                // cout<<x<<" "; bin(x); cout<<endl;
                if(x>=a && x<=b)
                    cnt++;
            }
        }

        cout<<cnt<<endl;
    }
    
    return 0;
}