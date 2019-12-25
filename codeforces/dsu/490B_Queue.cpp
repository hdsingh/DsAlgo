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
    int n,a,b;
    cin>>n;
    set<int> as,bs;
    map<int,int> m;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        as.insert(a); bs.insert(b);
        m[a] = b;
    }
    
    // Find the starting number(it does not appears in b's elements)
    int start = -1;
    for(auto a: as){
        if(bs.find(a)==bs.end()){
            start= a;
            break;
        }
    }

    vi ans;
    ans.push_back(0);
    ans.push_back(start);

    int i = 0;
    while(ans.size()<=n){
        ans.push_back(m[ans[i]]);
        i++;
    }

    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" \n"[i==n];
    
    

    return 0;
}