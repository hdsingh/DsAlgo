/*
 * @lc app=leetcode id=1320 lang=cpp
 *
 * [1320] Minimum Distance to Type a Word Using Two Fingers
 *
 * https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/
 *
 * algorithms
 * Hard (55.46%)
 * Likes:    184
 * Dislikes: 6
 * Total Accepted:    5.3K
 * Total Submissions: 9.5K
 * Testcase Example:  '"CAKE"'
 *
 * 
 * 
 * You have a keyboard layout as shown above in the XY plane, where each
 * English uppercase letter is located at some coordinate, for example, the
 * letter A is located at coordinate (0,0), the letter B is located at
 * coordinate (0,1), the letter P is located at coordinate (2,3) and the letter
 * Z is located at coordinate (4,1).
 * 
 * Given the string word, return the minimum total distance to type such string
 * using only two fingers. The distance between coordinates (x1,y1) and (x2,y2)
 * is |x1 - x2| + |y1 - y2|. 
 * 
 * Note that the initial positions of your two fingers are considered free so
 * don't count towards your total distance, also your two fingers do not have
 * to start at the first letter or the first two letters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word = "CAKE"
 * Output: 3
 * Explanation: 
 * Using two fingers, one optimal way to type "CAKE" is: 
 * Finger 1 on letter 'C' -> cost = 0 
 * Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
 * Finger 2 on letter 'K' -> cost = 0 
 * Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
 * Total distance = 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word = "HAPPY"
 * Output: 6
 * Explanation: 
 * Using two fingers, one optimal way to type "HAPPY" is:
 * Finger 1 on letter 'H' -> cost = 0
 * Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
 * Finger 2 on letter 'P' -> cost = 0
 * Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
 * Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
 * Total distance = 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word = "NEW"
 * Output: 3
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: word = "YEAR"
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= word.length <= 300
 * Each word[i] is an English uppercase letter.
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

// Space optimisation
class Solution {
    const int inf = 1000;
public:
    int minimumDistance(string s) {
        const int alp = 26;
        int n = s.length();
        vvi locs(alp);
        for(int i=0; i<alp; ++i){
            locs[i] = {i/6, i%6};
        }

        auto dif = [&](int a, int b){
            return abs(locs[a][0]-locs[b][0]) + abs(locs[a][1] - locs[b][1]);
        };
        
        // vector<vvi> dp(alp+1, vvi(alp+1, vi(n,inf)));
        vvi dp(alp+1, vi(alp+1, inf));
        // +1 for empty space, minimum distance to cover s till i,
        // having first finger at f1, 2nd at f2
        const int space = alp;

        dp[s[0]-'A'][space] = 0;
        // print_vv(dp[0]);

        for(int pos=1; pos<n; ++pos){
            vvi ndp(alp+1, vi(alp+1, inf));
            for(int f1 = 0; f1<=alp; ++f1){
                for(int f2=0; f2<=alp; ++f2){
                    int c = s[pos] - 'A';
                    // put first finger on c from f1 and f2 will be same
                    min_self(ndp[c][f2], dp[f1][f2] + (f1==space ? 0 : dif(c,f1)));

                    // put second finger on c from f2 and f1 will be same
                    min_self(ndp[f1][c], dp[f1][f2] + (f2==space ? 0 : dif(c, f2)));
                }
            }
            dp = ndp;
        }

        // Find min of different combinations of 2 fingers
        int mn = inf;
        for(int f1=0; f1<=alp; ++f1){
            for(int f2=0; f2<=alp; ++f2){
                min_self(mn, dp[f1][f2]);
            }
        }

        return mn;
    }
};

int main(){
    
    return 0;
}
// @lc code=end

