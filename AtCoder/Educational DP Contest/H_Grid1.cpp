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
const int inf = 1e9 + 7;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

void add_self(ll &a, ll b){
    a+=b;
    if(a>=inf)
        a-=inf;
}

int main(){
    int h,w;
    while(cin>>h>>w){
        vector<string> grid(h);

        for(int i=0; i<h; i++)
            cin>>grid[i];
        
        vector<vector<ll>> dp(h, vector<ll>(w));

        dp[0][0] = 1;
        // for(int i=0; i<h; i++){
        //     for(int j=0; j<w; j++){
        //         if(grid[i][j]=='#')
        //             dp[i][j] = 0;
        //         else{
        //             int a = i-1>=0 ? dp[i-1][j] : 0;
        //             int b = j-1>=0 ? dp[i][j-1] : 0;
        //             dp[i][j] = (dp[i][j] + a + b+inf)%inf;
        //         }
        //     }
        // }

        for(int row=0; row<h; row++){
            for(int col=0; col<w; col++){
                for(int r: {row, row+1}){
                    int c = col;
                    if(r==row){
                        c = col+1;
                    }

                    if(r<h && c<w && grid[r][c]=='.'){
                        add_self(dp[r][c], dp[row][col]);
                    }
                }
            }
        }

        cout<<(dp[h-1][w-1])<<endl;
    }
    
}