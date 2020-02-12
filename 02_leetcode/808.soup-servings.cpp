/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 *
 * https://leetcode.com/problems/soup-servings/description/
 *
 * algorithms
 * Medium (38.80%)
 * Likes:    127
 * Dislikes: 435
 * Total Accepted:    8.2K
 * Total Submissions: 21K
 * Testcase Example:  '50'
 *
 * There are two types of soup: type A and type B. Initially we have N ml of
 * each type of soup. There are four kinds of operations:
 * 
 * 
 * Serve 100 ml of soup A and 0 ml of soup B
 * Serve 75 ml of soup A and 25 ml of soup B
 * Serve 50 ml of soup A and 50 ml of soup B
 * Serve 25 ml of soup A and 75 ml of soup B
 * 
 * 
 * When we serve some soup, we give it to someone and we no longer have it.
 * Each turn, we will choose from the four operations with equal probability
 * 0.25. If the remaining volume of soup is not enough to complete the
 * operation, we will serve as much as we can.  We stop once we no longer have
 * some quantity of both types of soup.
 * 
 * Note that we do not have the operation where all 100 ml's of soup B are used
 * first.  
 * 
 * Return the probability that soup A will be empty first, plus half the
 * probability that A and B become empty at the same time.
 * 
 * 
 * 
 * 
 * Example:
 * Input: N = 50
 * Output: 0.625
 * Explanation: 
 * If we choose the first two operations, A will become empty first. For the
 * third operation, A and B will become empty at the same time. For the fourth
 * operation, B will become empty first. So the total probability of A becoming
 * empty first plus half the probability that A and B become empty at the same
 * time, is 0.25 * (1 + 1 + 0.5 + 0) = 0.625.
 * 
 * 
 * 
 * Notes: 
 * 
 * 
 * 0 <= N <= 10^9. 
 * Answers within 10^-6 of the true value will be accepted as correct.
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
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Refrenced
class Solution {
    vvd memo;
public:
    double soupServings(int N) {
        if(N>4800) return 1;
        memo.resize(N+1, vd(N+1, -1.));
        // deb(N);
        N = ceil(N/25.0);
        return f(N, N);
    }

    double f(int a, int b){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0) return 1;
        if(b<=0) return 0;
        if(memo[a][b]!=-1) return memo[a][b];
        return memo[a][b] = 0.25 * (f(a-4, b) + f(a-3, b-1) + f(a-2, b-2) + f(a-1, b-3));
    }
};
// @lc code=end


int main(){
    Solution sol; double out;
    int N;
    N = 1;
    out = sol.soupServings(N); deb(out);
    return 0;
}