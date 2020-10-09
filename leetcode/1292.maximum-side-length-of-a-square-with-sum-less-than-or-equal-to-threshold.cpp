#include <bits/stdc++.h>
using namespace std;

// O(n*m)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int X) {
        int n = mat.size(), m = mat[0].size();
        int mx = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                mat[i][j]+= (i ? mat[i-1][j] : 0) + (j ? mat[i][j-1] : 0) - 
                    (i && j ? mat[i-1][j-1] : 0);
                
                int len = mx+1;
                int st_x = i - len + 1, st_y = j - len + 1;
                if(st_x<0 || st_y<0) continue;
                int sum = mat[i][j] - 
                        (st_x>0 ? mat[st_x - 1][j] : 0) - 
                        (st_y>0 ? mat[i][st_y-1] : 0) + 
                        (st_x>0 && st_y>0 ? mat[st_x-1][st_y-1] : 0);
                if(sum<=X){
                    mx = len;
                }
            }
        }
        return mx;        
        
    }
};

// n*m + log(min(n,m))*m*n
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int X) {
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                mat[i][j]+= (i ? mat[i-1][j] : 0) + (j ? mat[i][j-1] : 0) - 
                    (i && j ? mat[i-1][j-1] : 0);
            }
        }
        
        auto sum = [&](int sx, int sy, int len){
            int ex = sx+len-1, ey = sy+len-1;
            return mat[ex][ey] - (sx ? mat[sx-1][ey] : 0) -  (sy ? mat[ex][sy-1] : 0)                      + (sx && sy ? mat[sx-1][sy-1] : 0);
        };
        
        auto can = [&](int len){
            for(int i=0; i+len<=n; ++i){
                for(int j=0; j+len<=m; ++j){
                    if(sum(i,j,len)<=X) 
                        return true;
                }
            }
            return false;
        };
        
        int lt = 0, rt = min(n, m) + 1;
        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(can(mid)){
                lt = mid;
            }else{
                rt = mid;
            }
        }
        
        return lt;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}