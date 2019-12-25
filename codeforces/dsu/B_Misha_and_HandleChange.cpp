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
    int q;
    cin>>q;
    unordered_map<string, string> m;
    set<string> newHandle;
    set<string> oldHandle;
    string old, nw;

    for(int i=0; i<q; i++){
        cin>>old>>nw;

        if(newHandle.find(old)==newHandle.end()) // old not found
            oldHandle.insert(old);
        newHandle.insert(nw);

        m[old] = nw;
    }

    cout<<oldHandle.size()<<endl;
    for(auto old: oldHandle){
        cout<<old<<" ";
        string prev = old;
        while(m[old]!=""){
            prev = old;
            old = m[old];
        }
        cout<<old<<endl;
    }

    
    return 0;
}