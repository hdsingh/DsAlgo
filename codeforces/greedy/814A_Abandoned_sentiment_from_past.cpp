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

    vi a(n);
    vi b(k);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<k; i++)
        cin>>b[i];

    sort(all(b), greater<int>());

    int j=0;
    for(int i=0; i<n; i++)
        if(a[i]==0)
            a[i] = b[j++];

    bool dec = false;
    for(int i=1; i<n; i++)
        if(a[i-1] > a[i]){
            dec = true; break;
        }
    
    if(n==1) dec = true;

    string ans = dec ? "Yes" : "No";
    cout<<ans<<endl;
}