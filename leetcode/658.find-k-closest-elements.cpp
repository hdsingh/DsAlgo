/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (39.14%)
 * Likes:    862
 * Dislikes: 176
 * Total Accepted:    70.7K
 * Total Submissions: 180.6K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 
 * Given a sorted array, two integers k and x, find the k closest elements to x
 * in the array.  The result should also be sorted in ascending order.
 * If there is a tie,  the smaller elements are always preferred.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,3,4,5], k=4, x=3
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4,5], k=4, x=-1
 * Output: [1,2,3,4]
 * 
 * 
 * 
 * Note:
 * 
 * The value k is positive and will always be smaller than the length of the
 * sorted array.
 * ⁠Length of the given array is positive and will not exceed 10^4
 * ⁠Absolute value of elements in the array and x will not exceed 10^4
 * 
 * 
 * 
 * 
 * 
 * 
 * UPDATE (2017/9/19):
 * The arr parameter had been changed to an array of integers (instead of a
 * list of integers). Please reload the code definition to get the latest
 * changes.
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution1 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;

            if(arr[mid]==x){
                low = mid; // save the index of middle element in low
                break;
            }
            else if(arr[mid]>x)
                high = mid - 1;
            else
                low = mid + 1;
        }
        // deb(low);
        vi out = {};
        int l = low-1;
        int r = low;
        while(k--){
            if(l<0) out.push_back(arr[r++]);
            else if(r>=n) out.push_back(arr[l--]);
            else if(abs(arr[l]-x) <= abs(arr[r]-x))
                out.push_back(arr[l--]);
            else
                out.push_back(arr[r++]);
        }

        sort(out.begin(), out.end());
        return out;
    }
};


// if arr[mid] is farther from target than arr[mid+k] which is k places ahead of mid then we need to pull lo
// to mid with 1 offset; otherwise we can pull hi at mid.
// at the end we'll end up with a value contained by lo's index which can be the starting index of our solution
class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int left = 0, right = A.size() - k;

        while (left < right) {
            int mid = (left + right) / 2;

            // deb(mid);
            // deb(mid+k);

            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
            // deb(left);
            // deb(right);
            // cout<<endl;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
    }
};


class Solution0 {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int X) {
        int n = arr.size();
        int lt = -1, rt = n;
        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(arr[mid]<=X)
                lt = mid;
            else
                rt = mid;
        }
        if(lt==-1) lt = 0;
        
        int idx = lt;
        if(idx+1<n && arr[idx+1]-X<X-arr[idx]) ++idx;
        lt = idx-1, rt = idx+1;
        
        for(int i=0; i<k-1; ++i){
            if( (lt>=0 && X-arr[lt]<=arr[rt]-X) || (rt>=n)){
                 --lt;
            }else ++rt;
        }
        
        vector<int> out;
        for(int i=lt+1; i<=rt-1; ++i){
            out.push_back(arr[i]);
        }
        
        return out;        
    }
};
// @lc code=end
int main(){
    Solution sol;
    vi nums = {0,1,2,3,4,5,6};
    print(sol.findClosestElements(nums,4,3));

    nums = {1,2,3,4,5};
    // print(sol.findClosestElements(nums,4,3));

    nums = {0,1,1,1,2,3,6,7,8,9};
    // print(sol.findClosestElements(nums,9,4));

}