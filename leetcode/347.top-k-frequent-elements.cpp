/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (56.54%)
 * Likes:    1866
 * Dislikes: 116
 * Total Accepted:    249.3K
 * Total Submissions: 439.3K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> out;
        unordered_map<int, int> um; // num, freq
        priority_queue<pair<int, int>> pq; // freq, num

        for(int x: nums) um[x]++;
        for(auto it: um) pq.push({it.second, it.first});

        for(int i =0; i<k; i++){
            auto p = pq.top(); pq.pop();
            out.push_back(p.second);
        }

        return out;

    }

    vector<int> topKFrequent1(vector<int>& nums, int k) {
        map<int, int> m;
        vector<int> out;
        
        for(int x: nums)
            m[x]++;
        
        // cout<<"map : "; print1(m);
        
        multimap<int, int, greater<int>> rev;
        for(auto it = m.begin(); it!=m.end(); it++){
            rev.insert({it->second,it->first});
        }

        // cout<<"rev: "; print1(rev);


        int i = 0;
        for(auto it = rev.begin(); it!=rev.end(); it++){
            if(i==k) break;
            out.push_back(it->second);
            i++;
        }
        

        return out;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for(auto &x: nums)
            cnt[x]++;
        
        // Min heap
        auto compare = [](pii &a, pii &b){
            return a.second > b.second;
        };

        priority_queue<pii, vector<pii>, decltype(compare)> pq(compare);
        for(auto &p: cnt){
            pq.push(p);
            if((int)pq.size()>k) pq.pop();
        }

        vi out;
        while(pq.size()){
            out.push_back(pq.top().first);
            pq.pop();
        }
        return out;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().topKFrequent(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}



// vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         auto it = nums.begin();
//         for (int n : nums) if (!freq[n]++) *it++ = n;
//         nums.resize(freq.size());
//         nth_element(
//             nums.begin(), nums.begin() + (k - 1), nums.end(),
//             [&](int a, int b) { return freq[a] > freq[b]; });
//         nums.resize(k);
//         return move(nums);
//     }