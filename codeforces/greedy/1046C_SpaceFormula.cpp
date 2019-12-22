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
typedef long long ll;
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
    int n, k;
    cin>>n>>k;

    vi s(n+1), p(n+1);

    for(int i=1; i<=n; i++) cin>>s[i];
    for(int i=1; i<=n; i++) cin>>p[i];

    int rank = 1;
    int np = s[k] + p[1];

    for(int i=1; i<=n; i++)
        if(s[i]>np) rank++;
    
    int pos = n;
    for(int i=1; i<=n; i++){
        if(s[i]<=np){
            if(s[i]+p[pos] > np)
                rank++;
            pos--;
        }
    }

    cout<<rank<<endl;

    return 0;
}