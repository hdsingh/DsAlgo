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
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ivals, vector<int>& nval) {
        vector<vector<int>> out;
        int i = 0, n = ivals.size();
        while(i<n && ivals[i][1]<nval[0])
            out.push_back(ivals[i++]);
        
        out.push_back(nval);
        
        while(i<n){
            int cur_size = out.size();
            if(ivals[i][0]<=out[cur_size-1][1]){
                out[cur_size-1][0] = min(out[cur_size-1][0], ivals[i][0]);
                out[cur_size-1][1] = max(out[cur_size-1][1], ivals[i][1]);
            }else{
                out.push_back(ivals[i]);
            }
            ++i;
        }
        return out;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ivals, vector<int>& nval) {
        vvi out;
        int n = ivals.size();
        if(!n) return {nval};
        int left = nval[0], right = nval[1];
        
        int i = 0;
        while(i<n && ivals[i][1]<left){
            out.push_back(ivals[i++]);
        }

        while(i<n && ivals[i][0]<=right){
            left = min(left, ivals[i][0]);
            right = max(right, ivals[i][1]);
            ++i;
        }
        out.push_back({left, right});

        while(i<n) out.push_back(ivals[i++]);

        return out;
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
