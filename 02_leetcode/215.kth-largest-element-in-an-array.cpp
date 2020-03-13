/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (49.71%)
 * Likes:    2426
 * Dislikes: 192
 * Total Accepted:    440.1K
 * Total Submissions: 881K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

class Solution {
public:
    // using multiset as min_heap
    int findKthLargest(vector<int>& nums, int k){
        multiset<int> ms;
        for(int x: nums){
            ms.insert(x);
            if(ms.size()>k) ms.erase(ms.begin());
        }
        return *ms.begin();
    }
    
    // using pq as min_heap
    int findKthLargest3(vector<int>& nums, int k){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<k; i++) pq.push(nums[i]);

        for(int i=k; i<nums.size(); i++){
            if(nums[i]>pq.top()){
                pq.push(nums[i]);
                if(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }

    // using pq as max_heap
    int findKthLargest2(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i=0; i<k-1; i++) pq.pop();
        return pq.top();
    }


    int findKthLargest1(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        // print(nums);
        for(int i=0; i<k-1; i++){
            pop_heap(nums.begin(), nums.end()-i);
            // print(nums);
        }
        
        return nums[0];
    }
};

// min PQ
class Solution1 {
public:
    int findKthLargest(vector<int>& a, int k) {
        // min pq
        priority_queue<int, vector<int>, greater<int>> pq; 
        for(auto &x: a){
            pq.push(x);
            if((int)pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};

// nth_element
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        print(nums);
        return *(nums.begin()+k-1);
    }
};


int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().findKthLargest(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
