#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int lim) {
        int n = nums.size();
        vector<int> cnt(2*lim+2);
        
        auto mark = [&](int lt, int rt, int val){
            lt = max(2,lt), rt = min(2*lim,rt);  
            if(lt>rt) return;
            cnt[lt]+=val; cnt[rt+1]-=val;
        };
        
        for(int i=0; i<n/2; ++i){
            int a = nums[i], b = nums[n-1-i];
            mark(2,min(a,b),2);
            mark(1+min(a,b),a+b-1,1);
            // mark(a+b,a+b,0);
            mark(a+b+1,lim+max(a,b),1);
            mark(lim+max(a,b)+1,2*lim,2);
        }
        
        partial_sum(cnt.begin(), cnt.end(), cnt.begin());
        int ans = n;
        for(int i=2; i<=2*lim; ++i){
            ans = min(ans, cnt[i]);
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}