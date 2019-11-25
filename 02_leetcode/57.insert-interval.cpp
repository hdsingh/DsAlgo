/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (32.13%)
 * Likes:    1119
 * Dislikes: 138
 * Total Accepted:    206.2K
 * Total Submissions: 641.8K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
// Approach1: Find the left part, right part and intersection intervals
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ins, vector<int>& ni) {
        int start = ni[0];
        int end = ni[1];

        int n = ins.size();
        // pt = (a,b)
        vvi left; // to include strictly less i.e  b<start
        vvi right; // to include strictly greater i.e a>end;
        // the remaining intervals will be merged

        for(int i=0; i<n; i++){
            int a = ins[i][0];
            int b = ins[i][1];

            if(b<start) left.push_back(ins[i]);
            if(a>end) right.push_back(ins[i]);
        }

        if(left.size()+right.size() != ins.size()){
            start = min(ins[left.size()][0], start);
            end = max(ins[ins.size()-right.size()-1][1],end);
        }
        vi middle = {start, end};

        left.push_back(middle);
        left.insert(left.end(), right.begin(), right.end());

        return left;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vvi ins; vi ni; vvi res;

    ins = {{1,3},{6,9}}; ni={2,5};
    res =sol.insert(ins, ni);
    print_vv(res);

    ins = {{1,2},{3,5},{6,7},{8,10},{12,16}}; ni={4,8};
    res =sol.insert(ins, ni);
    print_vv(res);

    ins = {{1,2},{3,5}}; ni={7,8};
    res =sol.insert(ins, ni);
    print_vv(res);

    ins = {{1,2},{3,5}}; ni={0,3};
    res =sol.insert(ins, ni);
    print_vv(res);

    ins = {{1,5}}; ni={0,9};
    res =sol.insert(ins, ni);
    print_vv(res);

    ins = {{1,5}}; ni={6,8};
    res =sol.insert(ins, ni);
    print_vv(res);

}
