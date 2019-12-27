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

vi par(155000);
vvi kittens(155000);

int find(int x){
    if(x==par[x]) return x;
    return par[x] = find(par[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(kittens[a].size() < kittens[b].size()) swap(kittens[a], kittens[b]);
    par[b] = a;
    for(int x: kittens[b])
        kittens[a].push_back(x);
}

int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        par[i] = i;
        kittens[i].push_back(i);
    }

    int a,b;
    for(int i=1; i<n; i++){
        cin>>a>>b;
        unite(a,b);    
    }

    for(int x: kittens[find(1)]) cout<<x<<" ";

    return 0;
}