#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;

        int max_so_far = INT_MIN;
        int max_here = 1;
        int min_here = 1;
        

        for(int num: nums){
            int prod1 = max_here*num;
            int prod2 = min_here*num;

            max_here = max(max(prod1, prod2), num);
            min_here = min(min(prod1, prod2), num);
            max_so_far = max(max_so_far, max_here);
        }

        return max_so_far;

    }
};

// Use kadane on 2 dp arrays
// dp: to keep track of maximum product taking in consideration negative
// dp_all_pos: assume all numbers as positive(by abs) and use kadane
// if count of neg integers is odd then return dp,
// else dp_all_pos since product of even number of neg integers is pos (-1,-2,-3,-1) = 6
// kadane: whether to ignore the computation till this point and start afresh, or use this number with
// earlier computation 
// Do two pass
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        vi nums2 = nums;
        reverse(nums2.begin(), nums2.end());
        return max(Product(nums), Product(nums2));
        // return Product(nums);
    }

    int Product(vector<int>& nums) {
        int n = nums.size();
        vi dp(n+1,1);
        vi dp2(n+1,1);

        int neg_count = 0;
        for(int i=1; i<=n; i++){
            dp[i]  = max(dp[i-1]*nums[i-1], nums[i-1]  );
            dp2[i] = dp2[i-1] ? dp2[i-1]*nums[i-1] : nums[i-1];
            if(dp2[i]>dp[i]) dp[i] = dp2[i];
        }


        int max_of_dp = *max_element(dp.begin()+1, dp.end());

        return max_of_dp;
    }
};

// Due to negative numbers and property of multiply
// Keep track of the max and min number
// new max number could be formed by using pre max, prev min, m=number itself
// new min number could be formed by using pre max, prev min, m=number itself
// max_so_far keeps track of the max num till now
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;

        int max_so_far = nums[0];
        int max_here_pre =nums[0]; 
        int min_here_pre = nums[0];
        int max_here, min_here;

        for(int i=1; i<n; i++){
            max_here = max( max(max_here_pre * nums[i], min_here_pre * nums[i]) , nums[i]);
            min_here = min( min(max_here_pre * nums[i], min_here_pre * nums[i]), nums[i]);
            max_so_far = max(max_here, max_so_far);
            max_here_pre = max_here;
            min_here_pre = min_here;
        }

        return max_so_far;

    }
};

// with_missing always contains the best possible product,
// it could be derieved from max{x, x*prev_missing, x*prev_wo_missing} (all combinations possible)
// Similary wo_missing aims to get as negative prod as possible, so that it
// could b converted into positive, when a new neg appears
// So it in min of {x, prev_missing*x, prev_wo_missing*x} (all combs possible)
// 0 is a special case, since it disconnect the contiguity of a subarray,
// so we just reset it to 1, so that it doesnot have any affect on upcoming subarrays
class Solution3 {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int mxp = a[0];
        vi with_missing(n), wo_missing(n); // with, without

        with_missing[0] = a[0];
        wo_missing[0]  = a[0];
        for(int i=1; i<n; i++){
            int x = a[i];
            mxp = max(mxp, x);
            if(x==0){
                with_missing[i] = 1;
                wo_missing[i]  = 1;
            }else{
                with_missing[i] = max({x, x*wo_missing[i-1], x*with_missing[i-1]});
                wo_missing[i]  = min({x, wo_missing[i-1]*x, with_missing[i-1]*x});
                mxp = max(mxp, with_missing[i]);
            }
        }
        // print(a,1);
        // print(wo);
        // print(w);

        return mxp;
        
    }
};


class Solution4 {
public:
    int maxProduct(vi &a){
        int n = a.size();
        int mp = a[0]; int l=0; int r =0;

        for(int i=0; i<n; i++){
            l = (l ? l : 1) * a[i];
            r = (r ? r : 1) * a[n-i-1];
            mp = max(mp, max(l,r));
            // deb3(i, l, r);
        }
        return mp;
    }
};

int main(){
    Solution sol;
    vi nums = {2,3,-2,4}; //6
    cout<<sol.maxProduct(nums)<<endl;

    // nums = {-2,0,-1}; // 2
    // cout<<sol.maxProduct(nums)<<endl;

    // nums = {-1,2}; //2
    // cout<<sol.maxProduct(nums)<<endl;

    // nums = {-1}; //-1
    // cout<<sol.maxProduct(nums)<<endl;

    // nums = {-2,3,-4}; //24
    // cout<<sol.maxProduct(nums)<<endl;

    // nums = {-2,3,-4, -1}; //24
    // cout<<sol.maxProduct(nums)<<endl;

    // nums = {-2,-3,-4, -5}; //120
    // cout<<sol.maxProduct(nums)<<endl;

    // nums = {-4,5,-3,10,-2}; //45
    // cout<<sol.maxProduct(nums)<<endl;

    // nums = {-2,-3,5,-4}; //60
    // cout<<sol.maxProduct(nums)<<endl;

    

    return 0;
}