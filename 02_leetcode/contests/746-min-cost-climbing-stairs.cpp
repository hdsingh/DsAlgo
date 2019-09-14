// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

class Solution1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // From the end
        int out(0);
        for (int i=n-1; i>0; i--){
            if (cost[i-1]<=cost[i]) i = i-1;
            out += cost[i];
        }
        // From the beginning
        int out2(0);
        for (int i=0; i<n-1; i++){
            if (cost[i+1]<=cost[i]) i+=1;
            out2+=cost[i];
        }
        deb(out);
        deb(out2);

    return min(out, out2);
    }
};

class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int out(0);
        for (int i=-1; i<n-2; i++){
            if(cost[i+2]<=cost[i+1]){
                i=i+1;
                }
            out+=cost[i+1];
        }
        // int out2(0);
        // for (int i=0; i<n-2; i++){
        //     if(cost[i+2]<=cost[i+1]){
        //         i=i+1;
        //         }
        //     out2+=cost[i+1];
        // }
    return out;
    }
};

class Solution3 {
public:
    int minCostClimbingStairs(vector<int> cost) {
        int n = cost.size();
        if (n==0) return 0;
        else if (n==1) return cost[0];
        vector<int> cache (n, -1);
        return find(cost, cache, n, -1);
    }

    int find(vector<int> const &cost, vector<int> &cache, int n, int i){
        if (i==n-1 || i==n-2){
            cache[i] = cost[i];
            return cost[i];
        }
        
        int c = (i==-1) ? 0 : cost[i];
        int res = min(find(cost, cache, n, i+1) , find(cost, cache, n, i+2));

        return c + res;
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n==0) return 0;
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i =2; i<n; i++){
            dp[i] = cost[i] +min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};

void print_vec(vector<int> v){
    cout<<" : {";
    for(auto i=v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<"}";
}

int main(){
    set<vector<int>> sv = { 
                            { },
                            // {0,1,2,2}, //2
                            // {0,2,2,1}, //2
                            // {0,2,3,2}, // 3
                            // {1, 2, 2, 0}, 
                            // {10, 15, 20},
                            {1, 1, 100, 1, 1, 100, 1, 1, 100, 1}
                            };
    Solution s;
    // vector<int> b = { };
    // cout<<s.minCostClimbingStairs(b);

    for (auto i: sv){
        cout<<s.minCostClimbingStairs(i);
        print_vec(i);
        cout<<endl;
    }
        
}

