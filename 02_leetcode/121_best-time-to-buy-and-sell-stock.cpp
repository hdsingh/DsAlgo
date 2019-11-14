// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;


// Whenever we find a new min, reset the min. Also reset the max to 0
class Solution1 {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if (n==0) return 0;
        int profit(0), max_profit(0);
        int min_v(a[0]), max_v(a[0]);

        for(int i=1; i<n; i++){
            if (a[i]<min_v){
                profit = max_v - min_v;
                if (profit>max_profit) max_profit = profit;
                min_v = a[i];
                max_v = 0;
            }else if (a[i]>max_v) max_v = a[i];
        }
        profit = max_v - min_v;
        return max(profit,max_profit);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        
        int min_price = prices[0];
        int max_profit = 0;
        
        for(int i=1; i<prices.size(); i++){
            min_price = min(prices[i], min_price);
            max_profit = max(max_profit, prices[i]-min_price);
        }
        
        return max_profit;
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& a) {
//         int min_v = 10000, max_v = 0;
//         for (int c: a) {
//             min_v = min(c, min_v);
//             max_v = max(max_v, c - min_v);
//         }
//         return max_v;
//     }
// };

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution s;
    cout<<s.maxProfit(prices);
}