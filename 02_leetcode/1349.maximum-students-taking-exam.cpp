/*
 * @lc app=leetcode id=1349 lang=cpp
 *
 * [1349] Maximum Students Taking Exam
 *
 * https://leetcode.com/problems/maximum-students-taking-exam/description/
 *
 * algorithms
 * Hard (36.33%)
 * Likes:    177
 * Dislikes: 6
 * Total Accepted:    3.3K
 * Total Submissions: 9K
 * Testcase Example:  '[["#",".","#","#",".","#"],[".","#","#","#","#","."],["#",".","#","#",".","#"]]'
 *
 * Given a m * n matrix seats  that represent seats distributions in a
 * classroom. If a seat is broken, it is denoted by '#' character otherwise it
 * is denoted by a '.' character.
 * 
 * Students can see the answers of those sitting next to the left, right, upper
 * left and upper right, but he cannot see the answers of the student sitting
 * directly in front or behind him. Return the maximum number of students that
 * can take the exam together without any cheating being possible..
 * 
 * Students must be placed in seats in good condition.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: seats = [["#",".","#","#",".","#"],
 * [".","#","#","#","#","."],
 * ["#",".","#","#",".","#"]]
 * Output: 4
 * Explanation: Teacher can place 4 students in available seats so they don't
 * cheat on the exam. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: seats = [[".","#"],
 * ["#","#"],
 * ["#","."],
 * ["#","#"],
 * [".","#"]]
 * Output: 3
 * Explanation: Place all students in available seats. 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: seats = [["#",".",".",".","#"],
 * [".","#",".","#","."],
 * [".",".","#",".","."],
 * [".","#",".","#","."],
 * ["#",".",".",".","#"]]
 * Output: 10
 * Explanation: Place students in available seats in column 1, 3 and 5.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * seats contains only characters '.' and'#'.
 * m == seats.length
 * n == seats[i].length
 * 1 <= m <= 8
 * 1 <= n <= 8
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

// TLE
// Backtrack
class Solution0 {
    int n,m;
    int mx_val;
    vector<vector<char>> seats;
    vvi dirs = {{0,-1},{-1,-1},{-1,1}};
public:
    int maxStudents(vector<vector<char>>& seats) {
        mx_val = 0;
        this->seats = seats;
        n = seats.size();
        m = seats[0].size();
        // deb2(n,m);
        int res = 0;
        dfs(0, 0, res);
        // solveBoard(0, 0);
        // deb2(mx_val, res);
        return res;
    }

    void dfs(int cur, int seated, int &res){
        if(cur==n*m){
            res = max(res, seated);
            this->mx_val = max(this->mx_val, seated);
            return;
        }

        int row = cur/m;
        int col = cur%m;
        // deb3(cur, row, col);

        // Fill the seat
        if(possible(row, col)){
            // seat student
            seats[row][col] = 'S';
            dfs(cur+1, seated+1, res);
            seats[row][col] = '.';
        }

        // Continue without filling
        dfs(cur+1, seated, res);
    }

    bool possible(int x, int y){
        // broken seat
        if(seats[x][y]=='#')
            return false;

        // if already seated in adj seats return false;
        for(auto dir: dirs){
            int nx = x+dir[0];
            int ny = y+dir[1];
            if(nx>=0 && nx<n && ny>=0 && ny<m && seats[nx][ny]=='S')
                return false;
        } 
        return true;
    }
};

// Bitmasking: in a mask 1 represents seated,
// in validity mask 1 represents available seat(not broken)
class Solution {
public:
    int maxStudents(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vi validity; // Positions with chairs not broken
        for(int i=0; i<n; ++i){
            int mask = 0;
            for(int j=m-1; j>=0; --j){
                mask<<=1;
                mask|=(grid[i][j]=='.' ? 1 : 0);
            }
            validity.push_back(mask);
        }

        vvi dp(n+1, vi(1<<m, -1));
        // dp represents the maximum possible sittings till
        // ith row, if the arrangement of students is mask
        // -1, represents invalid mask
        dp[0][0] = 0; //intialisation
        // just imagine a virtual row in the beginning, which will 
        // always be valid since no one is sitting there

        for(int row=1; row<=n; row++){
            int valid = validity[row-1];
            
            // try setting the students
            for(int mask=0; mask<(1<<m); ++mask){
                // mask must be a subset of valid
                // check adjacent seats
                if( ((mask|valid)!=valid) || (mask & (mask>>1)) ) continue;

                for(int prev_mask=0; prev_mask<(1<<m); ++prev_mask){
                    // If prev_mask is invalid or
                    // a student is already sitting on upper right or
                    // a student is already sitting on upper left,
                    // then continue
                    if(dp[row-1][prev_mask]==-1 || (mask & (prev_mask<<1)) || (mask & (prev_mask>>1)) )
                        continue;
                    // students sitting in prev row mask + the new ones
                    dp[row][mask] = max(dp[row][mask], dp[row-1][prev_mask] + __builtin_popcount(mask));
                }
            }
        }

        return *max_element(all(dp[n]));
    }
};

// Optimised: instead of iterating over entire mask, just iterate on exact subsets
// Hence using submask enumeration for validity check
// Bitmasking: in a mask 1 represents seated,
// in validity mask 1 represents available seat(not broken)
class Solution2 {
public:
    int maxStudents(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vi validity; // Positions with chairs not broken
        for(int i=0; i<n; ++i){
            int mask = 0;
            for(int j=m-1; j>=0; --j){
                mask<<=1;
                mask|=(grid[i][j]=='.' ? 1 : 0);
            }
            validity.push_back(mask);
        }

        vvi dp(n+1, vi(1<<m, -1));
        // dp represents the maximum possible sittings till
        // ith row, if the arrangement of students is mask
        // -1, represents invalid mask
        dp[0][0] = 0; //intialisation
        // just imagine a virtual row in the beginning, which will 
        // always be valid since no one is sitting there

        for(int row=1; row<=n; ++row){
            int valid = validity[row-1];
            
            for(int mask=valid; ; mask=(mask-1)&valid){
                if(mask & (mask>>1)) continue;
            
                for(int prev=0; prev<(1<<m); ++prev){
                    if(dp[row-1][prev]==-1 || (mask & (prev>>1)) || (mask & (prev<<1)) )
                        continue;
                    dp[row][mask] = max(dp[row][mask], dp[row-1][prev] + __builtin_popcount(mask));
                }
                if(!mask) break;
            }
        }

        return *max_element(all(dp[n]));
    }
};


// @lc code=end
int main(){
    Solution sol; vector<vector<char>> seats; int out;
    seats ={{'#','.','#','#','.','#'},
            {'.','#','#','#','#','.'},
            {'#','.','#','#','.','#'}};
    out = sol.maxStudents(seats); deb(out);

    seats ={{'.','#'},
            {'#','#'},
            {'#','.'},
            {'#','#'},
            {'.','#'}};
    out = sol.maxStudents(seats); deb(out);

    seats ={{'#','.','.','.','#'},
            {'.','#','.','#','.'},
            {'.','.','#','.','.'},
            {'.','#','.','#','.'},
            {'#','.','.','.','#'}};
    out = sol.maxStudents(seats); deb(out);

    seats = {{'.','.','.','.','#','.','.','.'},
             {'.','.','.','.','.','.','.','.'},
             {'.','.','.','.','.','.','.','.'},
             {'.','.','.','.','.','.','#','.'},
             {'.','.','.','.','.','.','.','.'},
             {'.','.','#','.','.','.','.','.'},
             {'.','.','.','.','.','.','.','.'},
             {'.','.','.','#','.','.','#','.'}};
    out = sol.maxStudents(seats); deb(out);

    return 0;
}

