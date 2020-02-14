/*
 * @lc app=leetcode id=1178 lang=cpp
 *
 * [1178] Number of Valid Words for Each Puzzle
 *
 * https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/description/
 *
 * algorithms
 * Hard (37.18%)
 * Likes:    151
 * Dislikes: 14
 * Total Accepted:    4.8K
 * Total Submissions: 12.8K
 * Testcase Example:  '["aaaa","asas","able","ability","actt","actor","access"]\n["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]'
 *
 * With respect to a given puzzle string, a word is valid if both the following
 * conditions are satisfied:
 * 
 * word contains the first letter of puzzle.
 * For each letter in word, that letter is in puzzle.
 * For example, if the puzzle is "abcdefg", then valid words are "faced",
 * "cabbage", and "baggage"; while invalid words are "beefed" (doesn't include
 * "a") and "based" (includes "s" which isn't in the puzzle).
 * 
 * Return an array answer, where answer[i] is the number of words in the given
 * word list words that are valid with respect to the puzzle puzzles[i].
 * 
 * Example :
 * 
 * 
 * Input: 
 * words = ["aaaa","asas","able","ability","actt","actor","access"], 
 * puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
 * Output: [1,1,3,2,4,0]
 * Explanation:
 * 1 valid word for "aboveyz" : "aaaa" 
 * 1 valid word for "abrodyz" : "aaaa"
 * 3 valid words for "abslute" : "aaaa", "asas", "able"
 * 2 valid words for "absoryz" : "aaaa", "asas"
 * 4 valid words for "actresz" : "aaaa", "asas", "actt", "access"
 * There're no valid words for "gaswxyz" cause none of the words in the list
 * contains letter 'g'.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 10^5
 * 4 <= words[i].length <= 50
 * 1 <= puzzles.length <= 10^4
 * puzzles[i].length == 7
 * words[i][j], puzzles[i][j] are English lowercase letters.
 * Each puzzles[i] doesn't contain repeated characters.
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// TLE
class Solution1 {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size();
        int m = puzzles.size();
        vi wm(n), pm(m); // word mask, puzzle mask

        // create a mask for all words
        for(int i=0; i<n; i++){
            int mask = 0;
            for(char c: words[i])
                mask |= (1<<(c-'a'));
            wm[i] = mask;
        }

        // create mask for all puzzles
        for(int j=0; j<m; j++){
            int mask = 0;
            for(char c: puzzles[j])
                mask |= (1<<(c-'a'));
            pm[j] = mask;
        }


        vi out(m);
        for(int j=0; j<m; j++){
            int pmask = pm[j];
            // int first_c = puzzles[j][0];
            int first_c_mask = (1<<(puzzles[j][0]-'a'));
            int cnt = 0;

            for(int i=0; i<n; i++){
                if( ( wm[i]& first_c_mask ) && ( !((wm[i]^pm[j])&wm[i]) ) )
                    ++cnt;
            }

            out[j] = cnt;
        }

        return out;
    }
};

// word is sub mask of puzzle
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size();
        int m = puzzles.size();
        // vi wm(n), pm(m); // word mask, puzzle mask
        unordered_map<int, int> wmasks; // mask, freq

        // create a mask for all words
        for(int i=0; i<n; i++){
            int mask = 0;
            for(char c: words[i])
                mask |= (1<<(c-'a'));

            wmasks[mask]++;
        }

        // create mask for all puzzles (max 7)
        // for each puzzle mask, create its submasks
        // and check if that sub mask is present in words,
        // if yes then add its freqency
        vi out(m); 
        for(int j=0; j<m; j++){
            int mask = 0;
            for(char c: puzzles[j])
                mask |= (1<<(c-'a'));

            int first_c_pmask = (1<<(puzzles[j][0] - 'a'));

            int cnt = 0;
            for(int sub=mask; sub; sub = (sub-1)&mask){
                if( (sub & first_c_pmask) && wmasks.count(sub))
                    cnt+=wmasks[sub];
            }

            out[j] = cnt;
        }   

        return out;
    }
};
// @lc code=end

int main(){
    Solution sol; vi out; vs words, puzzles;
    words = { "aaaa","asas","able","ability","actt","actor","access" };
    puzzles = { "aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz" };
    out = sol.findNumOfValidWords(words, puzzles); print(out);
    
    return 0;
}

