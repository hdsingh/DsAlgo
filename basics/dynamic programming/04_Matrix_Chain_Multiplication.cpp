// Refer: https://www.youtube.com/watch?v=_WncuhSJZyA :Abdul_Bari
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
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


// dp(i,j) = min( dp(i,k) + dp(k+1,j) + d_(i-1) * d_k * d_j)  where  i<=k<j
// Returns the minimum products required
class MatrixChain{
public:
    int solve(vi &dims){
        int n = dims.size();
        vvi dp(n, vi(n, 0));

        // initialize for d=0 (along the diagonal): already done
        // for(int i=0; i<n; i++) dp[i][i] = 0;

        for(int len=1; len<n; len++){
            for(int i=1; i<n-len; i++){
                int j = i+len;
                int min_cost = INT_MAX;

                for(int k=i; k<j; k++){
                    int cost = dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j];
                    min_cost = min(min_cost, cost);
                }
                dp[i][j] = min_cost;
            }
        }

        print_vv(dp);

        return dp[1][n-1];
    }
};

int main(){
    MatrixChain mat;
    vi dims = {3,2,4,2,5};
    cout<<mat.solve(dims)<<endl;
    return 0;
}

