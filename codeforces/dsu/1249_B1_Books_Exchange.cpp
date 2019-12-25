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

int main(){
    int q, n;
    cin>>q;
    while(q--){
        cin>>n;
        vi a(n+1);
        for(int i=1; i<=n; i++)
            cin>>a[i];

        vi ans(n+1, -1);

        for(int i=1; i<=n; i++){
            if(ans[i]==-1){

                int t = 1;
                int pos = a[i];
                vi cycle;
                while(pos!=i){
                    t++;
                    cycle.push_back(pos);
                    pos = a[pos];
                }

                ans[i] = t;
                for(auto c: cycle)
                    ans[c] = t;
            }
        }
        
        for(int i=1; i<=n; i++)
            cout<<ans[i]<<" \n"[i==n];
    }
    return 0;
}