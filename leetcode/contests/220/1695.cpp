#include <bits/stdc++.h>
using namespace std;
class Solution {
    const int nax = 1e4+10;
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(nax);
        int l = 0;
        int sum = 0, ans = 0;
        for(int r=0; r<n; ++r){
            while(l<r && seen[nums[r]]){
                sum-=nums[l];
                seen[nums[l++]] = 0;
                
            }
            seen[nums[r]] = 1;
            sum+=nums[r];
            ans = max(ans, sum);
            
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}