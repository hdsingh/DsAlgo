#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> seen;
        for(auto num: nums){
            if(num&1) seen.insert(2*num);
            else seen.insert(num);
        }
        
        int dif = *seen.rbegin() - *seen.begin();
        while((*seen.rbegin())%2==0){
            int top = *seen.rbegin();
            seen.erase(top);
            seen.insert(top/2);
            dif = min(dif, *seen.rbegin() - *seen.begin());
        }
        return dif;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}