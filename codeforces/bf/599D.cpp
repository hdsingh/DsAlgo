#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
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

ll squares(ll n, ll m){
    ll sqs = 0;
    fore(sz, 1, min(n,m)+1){
        sqs+= (n-sz+1)*(m-sz+1);
    }
    return sqs;
}

int main(){
    ll x;
    while(cin>>x){
        set<pair<ll, ll>> pts;

        fore(n, 1, 2e6+3){
            ll numer = 6*(ll)x  + (ll)n*(ll)n*(ll)n - n;
            ll denom = 3*(ll)n*((ll)n+1);

            if(numer%denom==0){
                ll m = numer/denom;

                if(n>m)
                    break;

                pts.insert({n,m});
            }
        }

        set<pair<ll, ll>> ans;
        for(auto p: pts){
            ans.insert({p.first, p.second});
            ans.insert({p.second, p.first});
        }

        cout<<ans.size()<<endl;
        for(auto p: ans){
            cout<<p.first<<" "<<p.second<<endl; 
        }

        cout<<endl<<endl;
    }

    return 0;
}