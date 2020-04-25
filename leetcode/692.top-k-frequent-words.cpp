/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (47.02%)
 * Likes:    938
 * Dislikes: 91
 * Total Accepted:    86.1K
 * Total Submissions: 182.5K
 * Testcase Example:  '["i", "love", "leetcode", "i", "love", "coding"]\n2'
 *
 * Given a non-empty list of words, return the k most frequent elements.
 * Your answer should be sorted by frequency from highest to lowest. If two
 * words have the same frequency, then the word with the lower alphabetical
 * order comes first.
 * 
 * Example 1:
 * 
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * ⁠   Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is",
 * "is"], k = 4
 * Output: ["the", "is", "sunny", "day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words,
 * ⁠   with the number of occurrence being 4, 3, 2 and 1 respectively.
 * 
 * 
 * 
 * Note:
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Input words contain only lowercase letters.
 * 
 * 
 * 
 * Follow up:
 * 
 * Try to solve it in O(n log k) time and O(n) extra space.
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
typedef vector<string> vs;

class Solution {
    struct comp{
        bool operator()(pair<int, string> p1, pair<int, string>p2){
            if(p1.first!=p2.first) return p1.first<p2.first;
            return p1.second>p2.second;
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vs out;
        unordered_map<string, int> count;
        for(string w: words) count[w]++;

        vector<pair<string, int>> freq;
        for(auto x: count) freq.push_back({x.first, x.second});

        partial_sort(freq.begin(), freq.begin()+k, freq.end(), [](auto &p1, auto &p2){
            // if freq not equal return the greater freq
            if(p1.second!=p2.second) return p1.second > p2.second;
            // else if freq is equal, return the smaller(lexicographically) word
            return p1.first<p2.first;
        });

        for(int i=0; i<k; i++){
            out.push_back(freq[i].first);
        }
        return out;

    }

    // using hasing and pq
    vector<string> topKFrequent1(vector<string>& words, int k) {
        vs out;
        unordered_map<string, int> freq;
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;

        for(string w: words) freq[w]++;
        for(auto x: freq) pq.push({x.second, x.first});

        while(k--){
            out.push_back(pq.top().second); pq.pop();
        }

        return out;
    }
};
// @lc code=end

int main(){
    vs words; int k;
    // words = {"i", "love", "leetcode", "i", "love", "coding"}; k= 3;
    // words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, k=4;
    words = {"a","aa","aaa"}; k=2;
    Solution s;
    vs out = s.topKFrequent(words, k);
    print(out);
}

