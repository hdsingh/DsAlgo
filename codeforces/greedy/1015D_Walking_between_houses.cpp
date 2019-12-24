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
    ll n, k, s;
    while(cin>>n>>k>>s){
        if(s<k || k*(n-1)<s){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            int h = 1;
            while(s){
                int d = min(n-1, s-k+1);
                s-=d; k--;
                int h1 = h+d;
                int h2 = h-d;
                h = h1<=n ? h1 : h2;
                cout<<h<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}