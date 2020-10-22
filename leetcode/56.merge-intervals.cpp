/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (37.25%)
 * Likes:    2824
 * Dislikes: 222
 * Total Accepted:    449.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& as) {
        vvi out;
        sort(all(as));
        for(auto a: as){
            if(out.empty()){
                out.push_back(a);
                continue;
            }
            if(a[0]<=out.back()[1]){
                vi bk = out.back(); out.pop_back();
                bk[1] = max(bk[1], a[1]);
                out.push_back(bk);
            }else{
                out.push_back(a);
            }
        }
        return out;
    }
};

int main(){
    vvi pts;
    Solution sol;

    pts = {{2,6},{8,10},{1,3},{15,18}};
    vvi ans = sol.merge(pts);
    print_vv(ans);

    pts = {{1,4},{4,5}};
    ans = sol.merge(pts);
    print_vv(ans);

    pts = {{1,4}};
    ans = sol.merge(pts);
    print_vv(ans);
    // vi a = {12,45,657};
    // int c = *(a.rbegin()+2);
    // deb(c);
}