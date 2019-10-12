/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 *
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
 *
 * algorithms
 * Easy (70.08%)
 * Likes:    348
 * Dislikes: 766
 * Total Accepted:    96.1K
 * Total Submissions: 137.1K
 * Testcase Example:  '[0,1,0]'
 *
 * Let's call an array A a mountain if the following properties hold:
 * 
 * 
 * A.length >= 3
 * There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] <
 * A[i] > A[i+1] > ... > A[A.length - 1]
 * 
 * 
 * Given an array that is definitely a mountain, return any i such that A[0] <
 * A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
 * 
 * Example 1:
 * 
 * 
 * Input: [0,1,0]
 * Output: 1
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,2,1,0]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 10000
 * 0 <= A[i] <= 10^6
 * A is a mountain, as defined above.
 * 
 * 
 */
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int cmax(INT_MIN), imax(0);
        for(int i=1; i<n-1; i++){
            if (A[i-1]<A[i] && A[i]>A[i+1]){
                if(A[i]>cmax){
                    cmax=A[i];
                    imax = i;
                }
            }
        }
        return imax;
    }
};
