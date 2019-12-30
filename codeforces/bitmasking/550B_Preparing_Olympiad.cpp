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

int main(){
    int n, l, r, x;
    while(cin>>n>>l>>r>>x){
        vi a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        int cnt = 0;
        // vvi subs; vvi ans;
        for(int mask=0; mask<(1<<n); mask++){
            // vi sub;
            int sum = 0; int mi = 1e7; int mx = -1e7;
            for(int j=0; j<n; j++){
                if( !(mask & (1<<j)) ){
                    // sub.push_back(a[j]);
                    mi = min(mi, a[j]);
                    mx = max(mx, a[j]);
                    sum+=a[j];
                }

                
            }
            if(sum>=l && sum<=r && mx-mi >= x){
                cnt++;
                // ans.push_back(sub);
            }
            // subs.push_back(sub);
        }

        cout<<cnt<<endl;
        // print_vv(subs);
        // cout<<"ans: ";
        // print_vv(ans);
    }
    return 0;
}