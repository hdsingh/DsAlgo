#include <bits/stdc++.h>
using namespace std;

// Since elements are already sorted by indexes, so we can use multiset to 
// keep remove the element at i-k-1 and keep sliding the window.
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        k = min(n,k);
        multiset<int> s;
        for(int i=0; i<n; ++i){
            if(i-k-1>=0) s.erase(s.find(nums[i-k-1]));
            
            auto pos = s.lower_bound(nums[i]);
            if(pos!=s.end()){
                if((long long)*pos - nums[i]<=t) return true;
            }
            if(pos!=s.begin()){
                --pos;
                if((long long)nums[i]-*pos<=t) return true;
            }
            s.insert(nums[i]);
        }
        
        return false;
    }
};

class Solution1 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        k = min(n,k);
        multiset<long long> s;
        for(int i=0; i<n; ++i){
            if(i-k-1>=0) s.erase(s.find(nums[i-k-1]));
            
            auto pos = s.lower_bound((long long)nums[i]-t);
            if(pos!=s.end()){
                if((long long)*pos - nums[i]<=t) return true;
            }
    
            s.insert(nums[i]);
        }
        
        return false;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}