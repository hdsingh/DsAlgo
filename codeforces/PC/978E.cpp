#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,w;
    while(cin>>n>>w){
        vl a(n);
        forn(i,n) cin>>a[i];
        partial_sum(all(a), a.begin());
        ll mx = 0, mn = 0;
        for(auto x: a){
            mx = max(mx,x);
            mn = min(mn,x);
        }
        ll r = w - mx; // max that we can have in bus are (capacity - max_present_at any pt)
        ll l = -mn; // (since( mn is -ve) , (-mn is +ve), so we need to have at least mn people intialy only then |mn| people can off)
        if(l<=r){
            cout<<r-l+1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}