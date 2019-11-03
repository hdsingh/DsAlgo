#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int gc = nums[0];
        for(int i=1; i<nums.size(); i++){
            gc = __gcd(gc, nums[i]);
        }
        return gc==1;
    }
};
// @lc code=end

int main(){
    Solution s;
    vi nums = {12,5,7,23};
    cout<<s.isGoodArray(nums)<<endl;
    nums = {29,6,10};
    cout<<s.isGoodArray(nums)<<endl;
    nums = {};
    cout<<s.isGoodArray(nums)<<endl;


}