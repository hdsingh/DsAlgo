/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (34.01%)
 * Likes:    600
 * Dislikes: 149
 * Total Accepted:    85.8K
 * Total Submissions: 246.7K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 * defined by its upper left corner (row1, col1) and lower right corner (row2,
 * col2).
 * 
 * 
 * 
 * The above rectangle (with the red border) is defined by (row1, col1) = (2,
 * 1) and (row2, col2) = (4, 3), which contains sum = 8.
 * 
 * 
 * Example:
 * 
 * Given matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 * 
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the matrix does not change.
 * There are many calls to sumRegion function.
 * You may assume that row1 ≤ row2 and col1 ≤ col2.
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class NumMatrix {
    vvi m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(!matrix.size()) return;

        int rows = matrix.size();
        int cols = matrix[0].size();
        m.resize(rows+1, vi(cols+1, 0));

        for(int i=1; i<=rows; i++){
            for(int j=1; j<=cols; j++)
                m[i][j] = m[i-1][j] + m[i][j-1] -m[i-1][j-1] + matrix[i-1][j-1];
        }

        print_vv(m);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return m[row2+1][col2+1] - m[row1][col2+1] - m[row2+1][col1] + m[row1][col1];
    }
};



// @lc code=end
int main(){
    vvi matrix = {
                    {3, 0, 1, 4, 2},
                    {5, 6, 3, 2, 1},
                    {1, 2, 0, 1, 5},
                    {4, 1, 0, 1, 7},
                    {1, 0, 3, 0, 5}
                 };
    // matrix = {{}};
    NumMatrix* obj = new NumMatrix(matrix);
    cout<<obj->sumRegion(0,0, 1,1)<<endl;
    cout<<obj->sumRegion(1,1, 1,1)<<endl;

    // cout<<obj->sumRegion(2, 1, 4, 3)<<endl;
    // cout<<obj->sumRegion(1, 1, 2, 2)<<endl;
    // cout<<obj->sumRegion(1, 2, 2, 4)<<endl;

}
