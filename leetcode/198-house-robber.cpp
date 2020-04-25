// https://leetcode.com/problems/house-robber/
// https://leetcode.com/problems/house-robber-ii/
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

void print_vec(vector<int> v){
    cout<<" : {";
    for(auto i=v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<"}";
}


class Solution {
public:
    // Iterative+Memo
    int rob1(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        else if (n==1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }

    // Recursive
    int rob2(vector<int>& nums) {
        // To convert this funtion to rec and pass len
        return rob2a(nums, nums.size()-1);
    }

    int rob2a(vector<int>& nums, int i) {
        if (i<0)
            return 0;
        return max(nums[i]+ rob2a(nums, i-2), rob2a(nums, i-1));
    }

    // Recursive + Memo
    int rob3(vector<int>& nums) {
        // To convert this funtion to rec and pass len
        int n = nums.size();
        if (n==0) return 0;
        vector<int> memo(n, -1);
        memo[0] = nums[0];
        return rob3a(nums, n-1, memo);
    }

    int rob3a(vector<int>& nums, int i, vector<int> & memo) {
        if (i<0)
            return 0;
        if (memo[i]>=0)
            return memo[i];
        int out = max(nums[i]+ rob3a(nums, i-2, memo), rob3a(nums, i-1, memo));
        memo[i] = out;
        return out; 

    }

    // Iterative+Optimized (using two variables instead of memo, bec we need only last 2 values)
    int rob4(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        else if (n==1) return nums[0];
        int prev1 = 0;
        int prev2 = 0;

        for(int num: nums){
            int temp = prev1;
            prev1 = max(num+prev2, prev1);
            prev2 = temp;
        }
        return prev1;
    }

    


    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        else if (n==1) return nums[0];
        auto nums1 = nums;
        nums1.erase(nums1.begin());
        nums.pop_back();
        
        return max(rob1(nums1), rob1(nums));
    }

};

int main(){
    Solution s;
    set<vector<int>> sv ={
                    {},
                    {1},
                    {2,1,1,2},
                    {1,2,3,1},
                    {2,7,9,3,1},
                    {0},
                    {1,2,3,1},
                    {2,3,2, 4}
                    };

    for (auto i: sv){
        cout<<s.rob4(i);
        print_vec(i);
        cout<<endl;
    }

}