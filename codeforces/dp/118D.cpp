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
const int mod = 1e8;

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


int n1, n2, k1, k2;

long long memo[101][101][11][11];

int C(int f, int h, int kf, int kh){
    cout<<"f: "<<f<<" h:"<<h<<" kf:"<<kf<<" kh:"<<kh<<endl;
    if(h+f==0) return 1;

    if(memo[f][h][kf][kh]!=-1) return memo[f][h][kf][kh];

    long long ans = 0;
    if(f>0 && kf>0) ans+= C(f-1, h, kf-1, k2)%mod;
    if(h>0 && kh>0) ans+= C(f, h-1, k1, kh-1)%mod;

    return memo[f][h][kf][kh] = ans%mod;
}



// Refer: https://noi.ph/training/weekly/week3.pdf
int main(){
    cin>>n1>>n2>>k1>>k2;
    
    // Approach1
    // memset(memo, -1, sizeof memo);
    // cout<<C(n1, n2, k1, k2);

    // Approach 2:
    int DP[101][101][11][11];
    memset(DP, 0, sizeof DP);
    for(int f=0; f<=n1; f++){
        for(int h=0; h<=n2; h++){
            for(int kf=0; kf<=k1; kf++){
                for(int kh=0; kh<=k2; kh++){
                    long long ans;
                    if(f+h==0) ans=1;
                    else{
                        ans = 0;
                        if(f>0 && kf>0) ans = (ans + DP[f-1][h][kf-1][k2]) %mod;
                        if(h>0 && kh>0) ans = (ans + DP[f][h-1][k1][kh-1]) %mod;
                    }
                    DP[f][h][kf][kh] = ans % mod;
                }
            }
        }
    }
                
    
    cout<<DP[n1][n2][k1][k2];

    return 0;
}