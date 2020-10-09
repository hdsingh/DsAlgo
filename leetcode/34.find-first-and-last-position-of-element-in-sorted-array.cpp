#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int X) {
        int n = nums.size();
        // lower_bound
        // loc of first element >=X
        int lt = -1, rt = n;
        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(nums[mid]>=X){
                rt = mid;
            }else
                lt = mid;
        }
        
        if(rt==n || nums[rt]!=X) return {-1,-1};
        vector<int> out = {rt};
        
        lt = -1, rt = n;
        //loc of last element <=X;
        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(nums[mid]<=X)
                lt = mid;
            else 
                rt = mid;
        }
        
        assert(lt!=-1);
        
        out.push_back(lt);
        return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}