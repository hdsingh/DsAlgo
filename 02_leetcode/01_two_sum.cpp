#include <bits/stdc++.h>
using namespace std;

// O(n^2): 532ms
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a, b, result;
        auto it= nums.begin();
        vector<int>::iterator jt;

        for(; it!=nums.end(); it++)
        {
            for(jt = it+1; jt!=nums.end(); jt++)
            {
                result = *it+*jt;
                if (result==target)
                {
                    a = distance(nums.begin(), it);
                    b = distance(nums.begin(), jt); 
                    break;
                };
            }
        }
        return {a, b};
    }
};

// O(n): 8ms
class Solution{
    public:
    vector<int> twoSum(vector<int> nums, int target){
        unordered_map<int, int> um;
        int j=0;
        vector<int> out;
        int a,b, req;

        for(auto i = nums.begin(); i!=nums.end(); i++){
            int req = target-*i;
            auto f = um.find(req);
            if (f==um.end()){
                um.insert({*i, j});
                j++;
            }else
            {   
                out =  {f->second, j};
            }
        }
        return out;
    };
};

int main(){
    // cout<<"Hello";
    vector<int> nums {2, 3, 7, 8};
    int target = 15;

    Solution s;
    vector<int> out = s.twoSum(nums, target);
    for(int x: out) cout<<x<<" ";
}