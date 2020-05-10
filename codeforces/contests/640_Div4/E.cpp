#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vi a(n); 
        vi cnt(n+1);
        for(auto &x: a){
            cin>>x;
            cnt[x]++;
        }
    
        int ans = 0;
        forn(i,n){
            int sum = 0;
            fore(j,i,n){
                sum+=a[j];
                if(i==j) continue;
            
                if(sum<=n){
                    ans+=cnt[sum];
                    cnt[sum] = 0;
                }
                if(sum>=n) break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}