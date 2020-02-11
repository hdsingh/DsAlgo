/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 *
 * https://leetcode.com/problems/knight-probability-in-chessboard/description/
 *
 * algorithms
 * Medium (47.03%)
 * Likes:    570
 * Dislikes: 127
 * Total Accepted:    32.4K
 * Total Submissions: 68.9K
 * Testcase Example:  '3\n2\n0\n0'
 *
 * On an NxN chessboard, a knight starts at the r-th row and c-th column and
 * attempts to make exactly K moves. The rows and columns are 0 indexed, so the
 * top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
 * 
 * A chess knight has 8 possible moves it can make, as illustrated below. Each
 * move is two squares in a cardinal direction, then one square in an
 * orthogonal direction.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Each time the knight is to move, it chooses one of eight possible moves
 * uniformly at random (even if the piece would go off the chessboard) and
 * moves there.
 * 
 * The knight continues moving until it has made exactly K moves or has moved
 * off the chessboard. Return the probability that the knight remains on the
 * board after it has stopped moving.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 3, 2, 0, 0
 * Output: 0.0625
 * Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight
 * on the board.
 * From each of those positions, there are also two moves that will keep the
 * knight on the board.
 * The total probability the knight stays on the board is 0.0625.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N will be between 1 and 25.
 * K will be between 0 and 100.
 * The knight always initially starts on the board.
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

// dp[i][j][k] = dp[old_i][old_j][k-1]
class Solution1 {
public:
    double knightProbability(int n, int K, int r, int c) {
        vvi dirs = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
        vector<vvd> dp(K+1, vvd(n, vd(n)));
        // prob of bieng at i,j in kth move

        dp[0][r][c] = 1;
        fore(k, 1, K+1){
            forn(i, n){
                forn(j, n){
                    forn(d, 8){
                        int old_i = i + dirs[d][0];
                        int old_j = j + dirs[d][1];
                        if(old_i>=0 && old_i<n && old_j>=0 && old_j<n)
                            dp[k][i][j] += (dp[k-1][old_i][old_j]/8);
                    }
                }
            }
        }

        double prob = 0;
        forn(i, n)
            forn(j, n)
                prob+=dp[K][i][j];
        return prob;
    }
};

// Forward style
class Solution2 {
public:
    double knightProbability(int n, int K, int r, int c) {
        vvi dirs = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
        vector<vvd> dp(K+1, vvd(n, vd(n)));
        // prob of bieng at i,j in kth move

        dp[0][r][c] = 1;
        fore(k, 0, K){
            forn(i, n){
                forn(j, n){
                    forn(d, 8){
                        int old_i = i + dirs[d][0];
                        int old_j = j + dirs[d][1];
                        if(old_i>=0 && old_i<n && old_j>=0 && old_j<n)
                            dp[k+1][i][j] += (dp[k][old_i][old_j]/8);
                    }
                }
            }
        }

        double prob = 0;
        forn(i, n)
            forn(j, n)
                prob+=dp[K][i][j];
        return prob;
    }
};

// delete k
class Solution {
public:
    double knightProbability(int n, int K, int r, int c) {
        vvi dirs = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
        vvd dp(n, vd(n));
        // prob of bieng at i,j in kth move

        dp[r][c] = 1;
        fore(k, 1, K+1){
            vvd ndp(n, vd(n));
            forn(i, n){
                forn(j, n){
                    forn(d, 8){
                        int old_i = i + dirs[d][0];
                        int old_j = j + dirs[d][1];
                        if(old_i>=0 && old_i<n && old_j>=0 && old_j<n)
                            ndp[i][j] += (dp[old_i][old_j]/8);
                    }
                }
            }
            dp = ndp;
        }

        double prob = 0;
        forn(i, n)
            forn(j, n)
                prob+=dp[i][j];
        return prob;
    }
};

// @lc code=end

int main(){
    Solution sol; double out;
    out = sol.knightProbability(3,2,0,0); deb(out);
    return 0;
}
