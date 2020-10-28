#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int n = row.size(), m = col.size();
        vector<vector<int>> out(n, vector<int>(m));

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int here = min(row[i], col[j]);
                out[i][j] = here;
                row[i]-=here; col[j]-=here;
            }
        }
        
        return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}