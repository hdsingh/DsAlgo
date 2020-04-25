/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (49.11%)
 * Likes:    2034
 * Dislikes: 147
 * Total Accepted:    350.3K
 * Total Submissions: 702.5K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 7, n = 3
 * Output: 28
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution1 { // bottom up rec
public:
    int uniquePaths(int m, int n) {
        return find(1, 1, m,n);
    }

    int find(int r, int d, int m, int n){
        if(r==m && d==n) return 1;
        if(r>m || d>n) return 0;

        return find(r+1, d, m, n) + find(r, d+1, m, n);
    }
};

class Solution2 { // top down rec
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1;
        if(m<1 || n<1) return 0;

        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }

};

class Solution3 { // 2d dp
public:
    int uniquePaths(int m, int n) {
        vvi dp(m+1, vi(n+1, 1));

        for(int i=1; i<=m; i++) dp[i][1] = 1;

        for(int j=1; j<=n; j++) dp[1][j] = 1;
        
        for(int i=2; i<=m; i++){
            for(int j=2; j<=n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m][n];
    }
};

class Solution4 { // 1d dp
public:
    int uniquePaths(int m, int n) {
        vector<unsigned long long> dp(n+1, 1);
        
        for(int i=2; i<=m; i++)
            for(int j=2; j<=n; j++)
                dp[j]+=dp[j-1];

        print(dp);
        return dp[n];
    }
};

// @lc code=end
int main(){
    Solution4 s;

    unsigned long long a = s.uniquePaths(18, 17);


    printf("%llu\n", a);

    return 0;
}
