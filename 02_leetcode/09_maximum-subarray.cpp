// https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int max_sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            sum = max(nums[i], sum+nums[i]);
            max_sum = sum>max_sum ? sum : max_sum;
        }
        return max_sum;
    }
};

int main(){
    vector<int> nums = {-2, 4, -5, 2, 2, 3};
    Solution s;
    cout<<s.maxSubArray(nums);
}