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
typedef unsigned long long ll;
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

const int mod = 1e9+7;

int main(){
    int t, x;
    string s;
    cin>>t;
    while(t--){
        ll x;
        string s;
        cin>>x>>s;

        ll cur_size = s.size();

        for(ll j=0; j<x; j++){
            ll rep = s[j] - '0' -1;
            if(s.size()<x){
                string sub = s.substr(j+1, s.size());
                while(rep--){
                    s+=sub;
                    (cur_size+=sub.size())%=mod;
                    // cur_size%=mod;
                }
            }else{
                // (a-b+mod)%mod
                (cur_size+= rep * (cur_size-j-1 + mod))%=mod;
                // cur_size%=mod;
            }
        }

        cout<<cur_size<<endl;
    }


    return 0;
}
