/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (57.22%)
 * Likes:    843
 * Dislikes: 75
 * Total Accepted:    109.5K
 * Total Submissions: 190.9K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 * 
 * Example 1:
 * 
 * Input:
 * "tree"
 * 
 * Output:
 * "eert"
 * 
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * "cccaaa"
 * 
 * Output:
 * "cccaaa"
 * 
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * "Aabb"
 * 
 * Output:
 * "bbAa"
 * 
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for(char c: s) count[c]++;

        vector<pair<char, int>> v;
        
        // to be done using  bucket sort
    }

    string frequencySort1(string s) {
        unordered_map<char, int> count;
        for(char c: s) count[c]++;

        priority_queue<pair<int, char>> pq;

        for(auto x: count) pq.push({x.second, x.first});

        string out;
        while(pq.size()){
            pair<int, char> temp = pq.top(); pq.pop();

            for(int i=0; i<temp.first; i++){
                out+=temp.second;
            }
            
        }
        return out;
    }
};
// @lc code=end

