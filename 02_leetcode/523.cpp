#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " : " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

void p_vec(vi v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        if(k == 0)
        {
            for(int i = 1; i < nums.size(); i++)
            {
                if(nums[i] == 0 && nums[i - 1] == 0) return true;
            }
            return false;
        }else{
            int i = 0;
            map<int, int> res;
            while(true)
            {   
                if(i != 0 && nums[i] % k == 0)
                {
                    return true;
                }else{
                    if(res.find(nums[i] % k) == res.end())
                    {   
                        res[nums[i] % k] = i;
                    }else{
                         if(i - res[nums[i] % k] > 1) return true;
                    }
                }
                i++;
                if(i == nums.size()) return false;
                nums[i] += nums[i - 1];
            }
        }
    }
};

int main(){
    Solution s;
    vi nums = { 2, 5, 3, 7, };
    cout<<s.checkSubarraySum(nums, 6);

}