/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 *
 * https://leetcode.com/problems/last-stone-weight/description/
 *
 * algorithms
 * Easy (62.08%)
 * Likes:    201
 * Dislikes: 12
 * Total Accepted:    23.9K
 * Total Submissions: 38.3K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * We have a collection of rocks, each rock has a positive integer weight.
 * 
 * Each turn, we choose the two heaviest rocks and smash them together.
 * Suppose the stones have weights x and y with x <= y.  The result of this
 * smash is:
 * 
 * 
 * If x == y, both stones are totally destroyed;
 * If x != y, the stone of weight x is totally destroyed, and the stone of
 * weight y has new weight y-x.
 * 
 * 
 * At the end, there is at most 1 stone left.  Return the weight of this stone
 * (or 0 if there are no stones left.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [2,7,4,1,8,1]
 * Output: 1
 * Explanation: 
 * We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
 * we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
 * we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
 * we combine 1 and 1 to get 0 so the array converts to [1] then that's the
 * value of last stone.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 1000
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==0) return 0;
        if(stones.size()==1) return stones[0];
        priority_queue<int> pq;
        for(int s: stones){
            pq.push(s);
        }

        while(pq.size()>1){
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();

            if(y-x) pq.push(y-x);
            // print_pq(pq);
        }

        return pq.size() ? pq.top() : 0;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> stones = stringToIntegerVector(line);
        
        int ret = Solution().lastStoneWeight(stones);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
