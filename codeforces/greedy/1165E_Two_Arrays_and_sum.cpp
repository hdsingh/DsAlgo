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
        cout<<setw(2)<<*i<<" ";
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

const int MOD = 998244353;

int main(){
    int n; 
    while(cin>>n){
        vector<long long> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
            a[i] = a[i] * (i+1) * (n-i);
        }

        vi b(n);
        for(int i=0; i<n; i++)
            cin>>b[i];
        
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        int ans = 0;
        for(int i=0; i<n; i++){
            a[i] %=MOD;
            ans = (ans + a[i] * b[i])%MOD;
        }

        printf("%d\n", ans);

    }
    
    return 0;
}