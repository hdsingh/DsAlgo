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
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){

                int m = INT_MAX;
                for(int k=0; k<n; k++){
                    if(k!=j){
                        m = min(m, arr[i-1][k]);
                    }
                }
                arr[i][j]+=m;
            }
        }

        return *min_element(arr[n-1].begin(), arr[n-1].end());
    }
};

int main(){
    vvi arr = { { 1,2,3 },
                { 4,5,6 },
                { 7,8,9 } };
    Solution sol;
    arr = {{1,2, 1},{3,1,6}, {1,10,9}};
    arr = {{4}};
    cout<<sol.minFallingPathSum(arr);
    return 0;
}