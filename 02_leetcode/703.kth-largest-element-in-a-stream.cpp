/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 *
 * https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
 *
 * algorithms
 * Easy (46.91%)
 * Likes:    385
 * Dislikes: 193
 * Total Accepted:    44K
 * Total Submissions: 93.8K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * Design a class to find the kth largest element in a stream. Note that it is
 * the kth largest element in the sorted order, not the kth distinct element.
 * 
 * Your KthLargest class will have a constructor which accepts an integer k and
 * an integer array nums, which contains initial elements from the stream. For
 * each call to the method KthLargest.add, return the element representing the
 * kth largest element in the stream.
 * 
 * Example:
 * 
 * 
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 * 
 * 
 * Note: 
 * You may assume that nums' length ≥ k-1 and k ≥ 1.
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        int n = nums.size();

        for(int i=0; i<n && i<k; i++){
            pq.push(nums[i]);
        }

        for(int i=k; i<n; i++){
            if(pq.top()<nums[i]){
                pq.push(nums[i]);
                if(pq.size()>size) pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

