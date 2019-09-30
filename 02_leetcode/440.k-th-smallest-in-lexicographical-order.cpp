/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 *
 * https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (27.14%)
 * Likes:    217
 * Dislikes: 38
 * Total Accepted:    9.5K
 * Total Submissions: 34.9K
 * Testcase Example:  '13\n2'
 *
 * Given integers n and k, find the lexicographically k-th smallest integer in
 * the range from 1 to n.
 * 
 * Note: 1 ≤ k ≤ n ≤ 10^9.
 * 
 * Example:
 * 
 * Input:
 * n: 13   k: 2
 * 
 * Output:
 * 10
 * 
 * Explanation:
 * The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so
 * the second smallest number is 10.
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
    int findKthNumber(int n, int k) {
        priority_queue<string> pq;

        for(int i=1; i<=n; i++){
           pq.push(to_string(i));
           if(pq.size()>k) pq.pop();
        }

        string s  = pq.top();
        return stoi(s);
    }
};
// @lc code=end

int main(){
    int t;
    int n,k;
    Solution s;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        scanf("%d\n", &k);
        int out = s.findKthNumber(n, k);
        cout<<out<<endl;
    }
}

