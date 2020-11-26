#include <bits/stdc++.h>
using namespace std;

// Assume the pointed are dispersed in 3D space, we need to find a 
// box including K points placed at origin having sidez len X+Y+Z minimum possible.
// In order to solve for 2D
// we can sort the points by X, and do line sweep from left to right along X axis
// and keeping track of smallest Y values. (using PQ)
// Repeat the same step for 3D

class Solution0{
public:
    int solve(vector<vector<int>>& nums, int K){
        int n = nums.size(); if(n<K) return 0;
        if(!K) return 0;
        sort(nums.begin(), nums.end());
        int maxY = 0, maxZ = 0;
        vector<pair<int,int>> yz;
        for(int i=0; i<K; ++i){
            maxY = max(maxY, nums[i][1]);
            maxZ = max(maxZ, nums[i][2]);
            yz.push_back({nums[i][1], nums[i][2]});
        }
        
        int ans = nums[K-1][0] + maxY + maxZ;
        for(int i=K; i<n; ++i){
            yz.push_back({nums[i][1], nums[i][2]});
            ans = min(ans, nums[i][0] + solve2D(yz, K));
        }
        return ans;
    }
    
    int solve2D(vector<pair<int,int>> &nums, int K){
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // [x, y], sorted by x
        // perform line sweep
        priority_queue<int> ys; // max heap
        for(int i=0; i<K; ++i) 
            ys.push(nums[i].second);
        
        int ans = nums[K-1].first + ys.top();
        
        for(int i=K; i<n; ++i){
            ys.push(nums[i].second);
            ys.pop();
            ans = min(ans, nums[i].first + ys.top());
        }
        return ans;
    }
};

class Solution{
public:
    int solve(vector<vector<int>> &nums, int K){
        int n = nums.size();
        if(!n || !K) return 0;
        int ans = 1e9;
        sort(nums.begin(), nums.end());
        
        for(int i=K-1; i<n; ++i){
            vector<pair<int,int>> yz;
            for(int j=0; j<=i; ++j){
                yz.push_back({nums[j][1], nums[j][2]});
            }
            
            sort(yz.begin(), yz.end());

            priority_queue<int> pq; // holds z
            for(int j=0; j<=i; ++j){
                pq.push(yz[j].second);
                if(pq.size()>K) pq.pop();
                if(pq.size()==K){
                    ans = min(ans, nums[i][0] + yz[j].first + pq.top());
                }
            }
        }
        return ans;
    }
};


int solve(vector<vector<int>>& tasks, int k) {
    Solution0 sol; return sol.solve(tasks, k);        
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}