#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}

int main(){
    int n, m;
    cin>>n;
    cin>>m;
    vi arr(n+1);
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    

    vi count(n+1);
    set<int> s;
    for(int i=n; i>0; i--){
        s.insert(arr[i]);
        count[i] = s.size();
    }

    // print(count);

    int t;
    for(int i=0; i<m; i++){
        cin>>t;
        cout<<count[t]<<endl;
    }

    

    return 0;
}