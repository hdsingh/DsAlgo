#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int lt = mat[0][0] - 1, rt = mat[n-1][n-1] + 1, ans = -1;
        
        // does it have leq>=k
        auto can = [&](int el){
            int leq = 0;
            
            int i=0, j = n-1;
            while(i<n && j>=0){
                if(mat[i][j]<=el){
                    leq+=(j+1);
                    ++i;
                }else
                    --j;
            }
            
            return leq>=k;
        };
        
        
        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(can(mid)){
                ans = mid, rt = mid;
            }else
                lt = mid;
        }
        
        return ans;
    }
};

int main(){
        
    return 0;
}