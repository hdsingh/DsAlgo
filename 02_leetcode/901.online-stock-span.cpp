/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 *
 * https://leetcode.com/problems/online-stock-span/description/
 *
 * algorithms
 * Medium (53.04%)
 * Likes:    350
 * Dislikes: 61
 * Total Accepted:    17.3K
 * Total Submissions: 32.6K
 * Testcase Example:  '["StockSpanner","next","next","next","next","next","next","next"]\n[[],[100],[80],[60],[70],[60],[75],[85]]'
 *
 * Write a class StockSpanner which collects daily price quotes for some stock,
 * and returns the span of that stock's price for the current day.
 * 
 * The span of the stock's price today is defined as the maximum number of
 * consecutive days (starting from today and going backwards) for which the
 * price of the stock was less than or equal to today's price.
 * 
 * For example, if the price of a stock over the next 7 days were [100, 80, 60,
 * 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["StockSpanner","next","next","next","next","next","next","next"],
 * [[],[100],[80],[60],[70],[60],[75],[85]]
 * Output: [null,1,1,1,2,1,4,6]
 * Explanation: 
 * First, S = StockSpanner() is initialized.  Then:
 * S.next(100) is called and returns 1,
 * S.next(80) is called and returns 1,
 * S.next(60) is called and returns 1,
 * S.next(70) is called and returns 2,
 * S.next(60) is called and returns 1,
 * S.next(75) is called and returns 4,
 * S.next(85) is called and returns 6.
 * 
 * Note that (for example) S.next(75) returned 4, because the last 4 prices
 * (including today's price of 75) were less than or equal to today's
 * price.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
 * There will be at most 10000 calls to StockSpanner.next per test case.
 * There will be at most 150000 calls to StockSpanner.next across all test
 * cases.
 * The total time limit for this problem has been reduced by 75% for C++, and
 * 50% for all other languages.
 * 
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class StockSpanner1 {
public:
    stack<int> prices;
    stack<int> span; // weight
    StockSpanner1() {
        
    }

    int next(int price) {
        int weight = 1;
        while(prices.size() && prices.top()<=price){
            weight += span.top(); 
            prices.pop(), span.pop();
        }
        prices.push(price); 
        span.push(weight);
        
        return weight;
    }
};


class StockSpanner {
    stack<pii> stk; // price, weight
public:
    StockSpanner() {
        
    }

    int next(int price) {
        int weight = 1;
        while(stk.size() && stk.top().first<=price){
            weight+=stk.top().second;
            stk.pop();
        }
        stk.emplace(price, weight);
        return weight;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
int main(){
    StockSpanner S;
    cout<<S.next(100)<<endl;
    cout<<S.next(80)<<endl;
    cout<<S.next(60)<<endl;
    cout<<S.next(70)<<endl;
    cout<<S.next(60)<<endl;
    cout<<S.next(75)<<endl;
    cout<<S.next(85)<<endl;
    return 0;
}

