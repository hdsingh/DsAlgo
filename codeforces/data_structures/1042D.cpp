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
typedef pair<ll, ll> pll;
// for each L
// for each R(L to N) 
// pre[R] - pre[L-1]<t
// pre[R] - t < pre[L-1]
// so for each R we want to know how many
// pre[L-1] are there which are greater than (pre[R] - t)
// Using order stats, we can know how many are less, so subtract it from tot size

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,t;
    while(cin>>n>>t){
        vl a(n+1); fore(i,1,n+1) cin>>a[i];
        partial_sum(all(a), a.begin());
        // print(a);
        
        ordered_set<pll> os;

        ll ans = 0;
        os.insert({0,0});
        for(int r=1; r<=n; ++r){
            ans+= os.size() - os.order_of_key({a[r]-t, r});
            os.insert({a[r],r});
        }

        cout<<ans<<endl;

    }
    return 0;
}

