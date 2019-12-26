#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

// Main idea: Reverse the seq and then solve, i.e instead of destroying the array construct it,
// The destoyed elements will give boundaries for inclusion(sum) of elements
int main(){
    int n;
    while(cin>>n){
        vi arr(n+1);
        vi seq(n+1);

        for(int i=1; i<=n; i++)
            cin>>arr[i];
        for(int i=1; i<=n; i++)
            cin>>seq[i];
        
        vector<ll> pf(n+1);
        for(int i=1; i<=n; i++)
            pf[i] = pf[i-1]+arr[i];
        
        set<int> dst; // destroyed
        for(int i=0; i<=n+1; i++)
            dst.insert(i);
        
        vector<ll> out = {0};
        ll mxval = 0;
        for(int i=n; i>1; i--){
            int el = seq[i];
            dst.erase(el); //undestroy(restore)

            auto it =  dst.lower_bound(el);  
            int r = *it;
            int l = *--it; // left destroyed el
            
            mxval =  max(mxval, pf[r-1]-pf[l]);
            out.push_back(mxval);
        }

        for(int i=n-1; i>=0; i--)
            printf("%lld\n", out[i]);
        
        // cout<<endl;
    }

    return 0;
}