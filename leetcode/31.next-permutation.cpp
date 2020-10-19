/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.04%)
 * Likes:    2252
 * Dislikes: 728
 * Total Accepted:    279.2K
 * Total Submissions: 896K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        int n = nums.size();
        if(n==1) return;
        // Step1:
        // start from right and find the loc where strictly dec seq starts
        for(i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]) break;
        }
        // loc before strictly dec starts
        // int loc = i; 
        // deb(loc);
        if(i<0) {reverse(nums.begin(), nums.end()); return;}

        // Step2:
        // find the loc of element next to nums[loc] (in sorted seq)
        int n_i;
        for(n_i=n-1; n_i>i; n_i--){
            if(nums[n_i] > nums[i]) break;
        }

        // deb(loc_next_element);
        // print(nums);
        swap(nums[i], nums[n_i]);
        // print(nums);
        
        reverse(nums.begin()+i+1, nums.end());

    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(!n) return;
        int pos = n-1;
        while(pos-1>=0 && nums[pos-1]>=nums[pos])
            --pos;
        if(pos==0){
            reverse(nums.begin(), nums.end());
            return;
        }
        --pos;
        int next_gr = n-1;
        while(next_gr>pos && nums[next_gr]<=nums[pos])
            --next_gr;
        
        // assert(nums[pos]<nums[next_gr]);
        swap(nums[pos], nums[next_gr]);
        
        reverse(nums.begin()+pos+1, nums.end());
    }
};

bool next_permutation1(vi &a){
    int n = a.size();
    if(n==1) return false;
    // find the location of decreasing seq starts
    int i = n-1;
    while(i && a[i-1]>=a[i]) --i;
    
    if(i==0){
        reverse(all(a));
        return false;
    }
    --i;

    // find the element next to i from end, greater than a[i]
    int j = n-1;
    while(a[j]<=a[i]) --j;
    swap(a[i], a[j]);    

    reverse(a.begin()+i+1, a.end());
    return true;
}
// @lc code=end

int main(){
    Solution s;
    vi a;
    a = {6,2,1,5,4,3,0};
    a = {1,1,5};
    a = {1,5,1};
    s.nextPermutation(a);
    print(a);
}