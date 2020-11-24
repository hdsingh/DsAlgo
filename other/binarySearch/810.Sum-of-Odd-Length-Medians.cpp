#include <bits/stdc++.h>
using namespace std;

int find_sum(vector<int> &nums, int K){
        int sum = 0, n = nums.size();
        multiset<int> s;
        for(int i=0; i<K; ++i) s.insert(nums[i]);
        auto median = s.begin();
        for(int i=0; i<K/2; ++i) ++median;
        for(int i=K; i<=n; ++i){
            sum+=*median;
            if(i==n) break;
            
            s.insert(nums[i]);
            if(nums[i]<*median)
                --median;
            
            int rem = nums[i-K];
            if(rem<=*median)
                ++median;
            s.erase(s.lower_bound(rem));
        }
        return  sum;
    }  

int solve1(vector<int>& nums) {
    int n =  nums.size();
    int tot = 0;
    for(int len=1; len<=n; len+=2){
        tot+=find_sum(nums, len);
    }
    return tot;
}


int solve(vector<int>& nums) {
    int n =  nums.size();
    int tot = 0;
    
    for(int i=0; i<n; ++i){
        priority_queue<int> L;
        priority_queue<int, vector<int>, greater<int>> R;
        for(int j=i; j<n; ++j){
            L.push(nums[j]);
            R.push(L.top());
            L.pop();
            
            if(R.size()>L.size()){
               L.push(R.top());
               R.pop();
            }
            
            if(i%2==j%2){ // odd
                tot+=L.top();
            }
        }
    }
    return tot;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}