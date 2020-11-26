#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& nums, int K) {
    if(!K) return true;
    int n = nums.size();
    vector<vector<int>> dp(n+2, vector<int>(K+1));
    // dp: sums that can be obtained at cur pos;
    dp[0][0] = dp[1][0] = 1;
    
    for(int i=2; i<n+2; ++i){
        int num = nums[i-2];
        // don't include
        dp[i] = dp[i-1];
        
        for(int j=0; j<=K && j+num<=K; ++j){
            if(dp[i-2][j])
                dp[i][j+num] =  1;
        }
        
        if(dp[i][K]) 
            return true;
    }
    return false;
}

const int nax = 1e5+10;
bool solve1(vector<int>& nums, int k) {
    if(!k) return true;
    bitset<nax> cur, prev;
    prev[0] = 1;
    for(auto num: nums){
        bitset<nax> ncur, nprev;
        ncur = prev<<num;
        if(ncur[k]) return true;
        nprev = (cur | prev);
        cur = ncur, prev = nprev;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}