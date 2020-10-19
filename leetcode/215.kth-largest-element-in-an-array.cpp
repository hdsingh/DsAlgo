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

class MinHeap{
	vector<int> harr;
  
  int left(int val){
  	return 2*val + 1;
  }
  
  int right(int val){
  	return 2*val+2;
  }
  
  int par(int val){
  	return (val-1)/2;
  }
public:
	MinHeap(){
  	harr.clear();
  }
  
  void push(int val){
  	int pos = harr.size();
    harr.push_back(val);
    // bubble up
    
    while(pos!=0 && harr[pos]<harr[par(pos)]){
    	swap(harr[par(pos)],harr[pos]);
      pos = par(pos);
    }
  }
  
  	void pop(){
        if(harr.size()==1){
        	harr.pop_back();
          return;
        }
        harr[0] = harr.back();
        harr.pop_back();
        
        // bubble down
        minheapify(0);
    }
    
  	void minheapify(int pos){
    		int lt = left(pos), rt = right(pos), smallest = pos;
        
        if(lt<harr.size() && harr[lt]<harr[smallest]) smallest = lt;
        if(rt<harr.size() && harr[rt]<harr[smallest]) smallest = rt;
        
        if(smallest!=pos){
        	swap(harr[pos], harr[smallest]);
          minheapify(smallest);
        }
    }
    
    int top(){
    		if(harr.empty()) return INT_MAX;
      	return harr[0];
    }
    
    int size(){
    	return harr.size();
    }
};	

class Solution1 {
public:
		int findKthLargest(vector<int> &nums, int K){
    		int n = nums.size();
        MinHeap pq;
        for(auto num: nums){
        		pq.push(num);
            if(pq.size()>K)
            		pq.pop();
        }
        
        return pq.top();
    }
};

class Solution2 {
public:
	int findKthLargest(vector<int> &nums, int K){
    	int n = nums.size();
        
        for(int i=(n-1)/2; i>=0; --i){
        	heapify(nums, i, n);
        }
        
        for(int i=n-1; i>=0 && K>1; --i){
        	swap(nums[0], nums[i]);
            heapify(nums,0,i);
            --K;
        }
        
        return nums[0];
    }
    
    void heapify(vector<int> &nums, int st, int end){
    	int lt = 2*st+1, rt = 2*st+2, largest = st;
        
        if(lt<end && nums[lt]>nums[largest]) largest = lt;
        if(rt<end && nums[rt]>nums[largest]) largest = rt;
        
        if(largest!=st){
        		swap(nums[largest], nums[st]);
            heapify(nums, largest, end);
        }
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
