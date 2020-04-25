#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()

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

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vvi matrix(n, vi(m,0));
        // print_vv(matrix);
        for(auto &index: indices){
            int ri = index[0];
            int ci = index[1];
            deb(ri);
            deb(ci);

            // inc for all cols in a row
            for(int i=0; i<m; i++){
                matrix[ri][i]+=1;
            }

            // for all row in a col
            for(int i=0; i<n; i++){
                matrix[i][ci]+=1;
            }

        // print_vv(matrix);
        }


        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]%2==1) count++;
            }
        }

        return count;
    }
};

int main(){
    Solution sol;
    vvi indices = {{0,1},{1,1}};
    int out = sol.oddCells(2,3,indices);
    deb(out);
    return 0;
}