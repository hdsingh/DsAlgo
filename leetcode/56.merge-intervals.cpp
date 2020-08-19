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

int partition(vvi &A, int l, int r){
    int piviot = A[r][0]; // to place the piviot at its correct pos
    int i = l - 1;

    for(int j = l; j<r; j++){
        if(A[j][0]<piviot){
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i+1], A[r]);
    return i+1;
}

void quickSort(vvi &A, int left, int right){
    if(left<right){
        int partition_pt = partition(A, left, right);
        quickSort(A, left, partition_pt-1);
        quickSort(A, partition_pt+1, right);
    }    

}

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

// @lc code=start
class Solution {
public:
    static bool comp(const vi &v1, const vi &v2){
        return v1[0] < v2[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(!n) return {};
        vi out;

        // Approach1: Bubble sort
        // // Sort the ranges acc to a (for pt(a,b)) using quick sort
        // for(int k=0; k<n-1; k++)
        //     for(int i=0; i<n-k-1; i++)
        //         if(intervals[i][0] > intervals[i+1][0])
        //             swap(intervals[i], intervals[i+1]);

        // Approach2
        // quickSort(intervals, 0, n-1); 

        // Approach 3:
        sort(intervals.begin(), intervals.end(), comp);
           
        // print_vv(intervals);

        // merge ranges
        out.push_back(intervals[0][0]);
        out.push_back(intervals[0][1]);

        for(int i=1;i<n; i++){
            int a = *(out.rbegin() + 1);
            int b = *out.rbegin();

            int c = intervals[i][0];
            int d = intervals[i][1];

            // deb(a);deb(b);deb(c);
            if(c>=a && c<=b){
                // ignore for all other cases execept
                if(d>b){
                    out.pop_back();
                    out.push_back(d);
                    // deb(d);
                }
            }else{ // c doesnot lies in range
                out.push_back(c);
                out.push_back(d);
            }

        }
        vvi ans = {};
        int j=0;
        while(j<out.size()){
            ans.push_back({out[j++], out[j++]});
        }

        return ans;
    }
};
// @lc code=end
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