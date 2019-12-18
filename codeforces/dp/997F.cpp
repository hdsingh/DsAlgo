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
    int n;
    cin>>n;

    map<int,int> dp;
    int mlen(0), lst(0);
    vi arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        
    }   

    for(auto a: arr){
        dp[a] = max(dp[a], dp[a-1] + 1);
        if(dp[a] > mlen){
            mlen = dp[a];
            lst = a;
        }
    }

    cout<<mlen<<endl;

    int beg = lst - mlen + 1;

    // deb(beg);

    for(int i=0; i<n; i++){
        if(arr[i]==beg){
            cout<<i+1<<" ";
            if(beg==lst) break;
            beg++;
        }
    }
    
    return 0;
}