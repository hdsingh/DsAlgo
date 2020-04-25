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

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int th) {
        int n = mat.size();
        int m = mat[0].size();

        vvi ps(n+1, vi(m+1)); //prefix sum i.e ps[i][j] = sum of matrix 0..i, 0..j

        for(int i=1; i<=n; i++){
            for(int j=1;j<=m; j++){
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + mat[i-1][j-1];
            }
        }

        // print_vv(ps);
        int max_side = 0;

        for(int k=1; k<=min(n,m); k++){

            for(int i=k; i<=n; i++){

                for(int j=k; j<=m; j++){
                    // cout<<i<<" "<<" "<<j<<" "<<k<<endl;
                    int val = ps[i][j] - ps[i-k][j] - ps[i][j-k] + ps[i-k][j-k];
                    if(val<=th && k>max_side){
                        max_side = k;
                    }
                }
            }
        }

        return max_side;

    }
};

int main(){
    Solution sol;
    vvi mat; int th;

    mat=  { { 1,1,3,2,4,3,2 },{ 1,1,3,2,4,3,2 },{ 1,1,3,2,4,3,2 } };
    // mat = {{1,2,3,11},{4,5,6,12},{7,8,9,13},{14,15,16,17}};
    cout<<sol.maxSideLength(mat, 4)<<endl;

    mat = { { 2,2,2,2,2 },{ 2,2,2,2,2 },{ 2,2,2,2,2 },{ 2,2,2,2,2 },{ 2,2,2,2,2 } };
    cout<<sol.maxSideLength(mat, 1)<<endl;

    mat = { { 1,1,1,1 },{ 1,0,0,0 },{ 1,0,0,0 },{ 1,0,0,0 } };
    cout<<sol.maxSideLength(mat, 6)<<endl;

    mat = { { 18,70 },{ 61,1 },{ 25,85 },{ 14,40 },{ 11,96 },{ 97,96 },{ 63,45 } };
    cout<<sol.maxSideLength(mat, 40184)<<endl;

    
    
    return 0;
}