/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 *
 * https://leetcode.com/problems/k-closest-points-to-origin/description/
 *
 * algorithms
 * Medium (61.29%)
 * Likes:    713
 * Dislikes: 66
 * Total Accepted:    114.7K
 * Total Submissions: 187.6K
 * Testcase Example:  '[[1,3],[-2,2]]\n1'
 *
 * We have a list of points on the plane.  Find the K closest points to the
 * origin (0, 0).
 * 
 * (Here, the distance between two points on a plane is the Euclidean
 * distance.)
 * 
 * You may return the answer in any order.  The answer is guaranteed to be
 * unique (except for the order that it is in.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[1,3],[-2,2]], K = 1
 * Output: [[-2,2]]
 * Explanation: 
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest K = 1 points from the origin, so the answer is just
 * [[-2,2]].
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[3,3],[5,-1],[-2,4]], K = 2
 * Output: [[3,3],[-2,4]]
 * (The answer [[-2,4],[3,3]] would also be accepted.)
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= K <= points.length <= 10000
 * -10000 < points[i][0] < 10000
 * -10000 < points[i][1] < 10000
 * 
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    struct comp{
        bool operator()(vi &a, vi &b){
            int sq1 = a[0]*a[0] + a[1]*a[1];
            int sq2 = b[0]*b[0] + b[1]*b[1];
            return sq1>sq2;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& ps, int K) {
        partial_sort(ps.begin(), ps.begin() + K , ps.end(),
                            [](vector<int> &p, vector<int> &q){
                                return p[0]*p[0] + p[1]*p[1] < q[0]*q[0] + q[1]*q[1];
                            });
        return vector<vector<int>>(ps.begin(), ps.begin()+K);
    }

    vector<vector<int>> kClosest4(vector<vector<int>>& ps, int K) {
        nth_element(ps.begin(), ps.begin() + K - 1 , ps.end(),
                            [](vector<int> &p, vector<int> &q){
                                return p[0]*p[0] + p[1]*p[1] < q[0]*q[0] + q[1]*q[1];
                            });
        return vector<vector<int>>(ps.begin(), ps.begin()+K);
    }

    vector<vector<int>> kClosest3(vector<vector<int>>& ps, int K) {
        multimap<int, int> m;
        for(int i = 0; i<ps.size(); i++){
            m.insert({ps[i][0]*ps[i][0]+ps[i][1]*ps[i][1], i});
        }
        vector<vi> out;

        for(auto it = m.begin(); K>0; K--, it++){
            out.push_back(ps[it->second]);
        }
        return out;
    }    

    vector<vector<int>> kClosest2(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), comp());
        
        return vector<vector<int>>(points.begin(), points.begin()+K);
    }

};
// @lc code=end

int main(){
    Solution s;
    vector<vector<vi>> all_points = {
        {{1,3}, {-2,2}},
        {{3,3}, {5,-1}, {-2,4}},
    };

    vi ks = {1, 2};
    
    for(int i = 0; i<all_points.size(); i++){
        vector<vi> out = s.kClosest1(all_points[i], ks[i]);
        print_vvi(out);
        cout<<endl;
    }

}