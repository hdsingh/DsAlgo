#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(ll i = ll(l); i < ll(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
#define deb2(x, y) cout << #x <<" "<< x <<" "<< #y<<" "<< y<< endl;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

int main(){
    ll n;

    while(cin>>n){
        ll val;
        set<ll> ans;
        for(ll i=1; i*i<=n; i++){
            if(n%i!=0) continue;

            val = ( (2*1 + ((n/i)-1)*i) *(n/i))/2;
            ans.insert(val);

            if(i*i==n) continue;

            val = ( (2*1 + (i-1)*(n/i)) *i)/2;
            ans.insert(val);
        }
        for(auto x: ans)
            cout<<x<<" ";
        
        cout<<endl;


    }
    return 0;
}

int main1(){
    ll n;
    while(cin>>n){
        set<ll> ans;
        // ans.insert(1);

        fore(i, 1, sqrt(n)+1){
            if(n%i!=0) continue;
            int t = n/i;
            ll val = ( (2*1 + (t-1)*i) *t)/2;

            // cout<<i<<" "<<val<<endl;
            ans.insert(val);

            t = i; i = n/i;
            val = ( (2*1 + (t-1)*i) *t)/2;
            i = n/i;

            // cout<<i<<" "<<val<<endl;
            ans.insert(val);
        }

        for(auto x: ans)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}