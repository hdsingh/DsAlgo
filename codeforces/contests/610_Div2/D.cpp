#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
const int inf = 1e9;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

int main(){
    int test;
    cin>>test;
    while(test--){
        ll n, t, a, b;
        cin>>n>>t>>a>>b;

        vector<pll> v;
        vector<int> hard(n); //category
        int cntA = 0, cntB = 0;

        for(int i=0; i<n; i++){
            cin>>hard[i];
            if(hard[i]) cntB++;
            else cntA++;
        }

        for(int i=0; i<n; i++){
            ll time; cin>>time;
            v.push_back({time, hard[i]});
        }

        v.push_back({t+1, 0});
        sort(v.begin(), v.end());

        ll cnt1 = 0, cnt2 = 0;
        ll ans = 0;

        for(int i=0; i<=n; i++){
            ll need = a*cnt1 + b*cnt2;
            ll has =  v[i].first - 1 - need;
            if(has>=0){
                ll canA = min( (cntA - cnt1), has/a); //min(remaining, possible)
                has-=canA*a;
                ll canB = min( (cntB-cnt2), has/b);
                ans = max(ans, cnt1 + cnt2 + canA + canB);
            }
            
            if(v[i].second)
                cnt2++;
            else
                cnt1++;
                

        }

        cout<<ans<<endl;

    } 
    return 0;
}