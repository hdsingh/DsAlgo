/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 *
 * https://leetcode.com/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (25.20%)
 * Likes:    489
 * Dislikes: 49
 * Total Accepted:    10.3K
 * Total Submissions: 40.1K
 * Testcase Example:  '1\n2'
 *
 * You are given K eggs, and you have access to a building with N floors from 1
 * to N. 
 * 
 * Each egg is identical in function, and if an egg breaks, you cannot drop it
 * again.
 * 
 * You know that there exists a floor F with 0 <= F <= N such that any egg
 * dropped at a floor higher than F will break, and any egg dropped at or below
 * floor F will not break.
 * 
 * Each move, you may take an egg (if you have an unbroken one) and drop it
 * from any floor X (with 1 <= X <= N). 
 * 
 * Your goal is to know with certainty what the value of F is.
 * 
 * What is the minimum number of moves that you need to know with certainty
 * what F is, regardless of the initial value of F?
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: K = 1, N = 2
 * Output: 2
 * Explanation: 
 * Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
 * Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty
 * that F = 1.
 * If it didn't break, then we know with certainty F = 2.
 * Hence, we needed 2 moves in the worst case to know what F is with
 * certainty.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: K = 2, N = 6
 * Output: 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: K = 3, N = 14
 * Output: 4
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= K <= 100
 * 1 <= N <= 10000
 * 
 * 
 * 
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
// Recursive solution //TLE

// To know with certainiity: worst case: max_cost
// For (egg, floor) we will test it from all the cur_floors
// if egg beaks (egg-1), we will move 1 floor down( remaining floors = cur_floor-1)
// if it does not break,  we will have to check the reamining floors, i.e floors above
// the cur_floor (egg, floor - cur_floor)
// Since the we need to be certain, we will take the worst case of break and not_break
//  i.e move required to be certain will be max of two
// then we will take min_of all these moves
class Solution1 {
public:
    int superEggDrop(int eggs, int floors) {
        if(floors==0 || floors==1)
            return floors;

        // we will have to start from 1 and check for each floor
        if(eggs==1) return floors;

        int min_moves = floors;
        for(int cur_floor=1; cur_floor<=floors; cur_floor++){

            int does_not_breaks = superEggDrop(eggs, floors-cur_floor);
            int breaks = superEggDrop(eggs-1, cur_floor-1);
            int moves = 1 + max(breaks, does_not_breaks);

            min_moves = min(min_moves, moves);
        }

        return min_moves;
    }
};

// Recursive with dp table
class Solution2{
public:
    int superEggDrop(int eggs, int floors){
        vvi dp(eggs+1, vi(floors+1, 0));
        int out = EggDrop(eggs, floors, dp);
        print_vv(dp);
        return out;
    }

    int EggDrop(int eggs, int floors, vvi &dp) {
        if(floors==0 || floors==1)
            return floors;

        // we will have to start from 1 and check for each floor
        if(eggs==1) return floors;

        if(dp[eggs][floors]) return dp[eggs][floors];

        int min_moves = floors;
        for(int cur_floor=1; cur_floor<=floors; cur_floor++){

            int does_not_breaks = EggDrop(eggs, floors-cur_floor, dp);
            int breaks = EggDrop(eggs-1, cur_floor-1, dp);
            int cost = 1 + max(breaks, does_not_breaks);

            min_moves = min(min_moves, cost);
        }

        dp[eggs][floors] = min_moves;

        return min_moves;
    }
};

// dp(K,N)=  1≤X≤N min(max(dp(K−1,X−1),dp(K,N−X)))
// i.e.
// dp(eggs,floors) =  1 ≤ cur_f ≤ floors min(max(dp(eggs-1, cur_f-1), dp(eggs, floors - cur_f)))
class Solution3{
public:
    int superEggDrop(int eggs, int floors){
        vvi dp(eggs+1, vi(floors+1, 0));

        // at floor 1 only 1 move is possible regarless of the number of eggs
        for(int e=1; e<=eggs; e++) dp[e][1] = 1;
        
        // when only 1 egg is available, we have to drop it from all the floors
        for(int f=1; f<=floors; f++) dp[1][f] = f;

        for(int f=2; f<=floors; f++){
            for(int e=2; e<=eggs; e++){
                int min_moves = floors;
                for(int cur_floor=1; cur_floor<f; cur_floor++){
                    int does_not_breaks = dp[e][f-cur_floor];
                    int breaks = dp[e-1][cur_floor-1];
                    int moves = 1 + max(breaks, does_not_breaks); //cost

                    min_moves = min(moves, min_moves);
                }
                dp[e][f] = min_moves;
            }
        }
        // print_vv(dp);
        return dp[eggs][floors];
    }
};

class Solution {
public:
    int superEggDrop(int eggs, int floors) {
        vector<vector<int>> dp(floors + 1, vector<int>(eggs + 1, 0));
        int m = 0;
        while (dp[m][eggs] < floors) {
            m++;
            for (int e = 1; e <= eggs; ++e)
                dp[m][e] = dp[m - 1][e - 1] + dp[m - 1][e] + 1;
            
            // print_vv(dp);
            // deb(m);
        }
        return m;
    }
};

// @lc code=end
int main(){
    Solution s;
    vvi tests = {{1,2},{2,6},{4,1000}};
    for(auto test: tests){
        cout<<s.superEggDrop(test[0], test[1])<<endl;
    }
    cout<<s.superEggDrop(2,100)<<endl;
    return 0;
}