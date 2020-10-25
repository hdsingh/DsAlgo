/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (28.74%)
 * Likes:    773
 * Dislikes: 26
 * Total Accepted:    115.5K
 * Total Submissions: 401.8K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output: 1
 * Explanation: The palindrome partitioning ["aa","b"] could be produced using
 * 1 cut.
 * 
 * 
 */
#include "cpp.h"
using namespace std;
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
// Refer: https://www.youtube.com/watch?v=WPr1jDh3bUQ
class Solution0 {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n));

        // Single Letter are Palindromes
        for(int i=0; i<n; i++){
            isPal[i][i] = true;
        }

        // Two letters
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1])
                isPal[i][i+1] = true;
        }

        // for length 3 and more
        for(int l=2; l<n; l++){
            for(int i=0; i<n-l; i++){
                int j = i+l;
                // cout<<i<<" "<<j<<endl;
                // if char at both locs eq and the inbetween string is pal
                // then the entire string from i to j would be Pal
                if(s[i]==s[j] && isPal[i+1][j-1])
                    isPal[i][j] = true;
            }
        }

        vector<int> cuts(n, INT_MAX);
        for(int i=0; i<n; i++){
            if(isPal[0][i])
                cuts[i] = 0;
            else{
                int temp = INT_MAX;
                for(int j=0; j<i; j++){
                    if(isPal[j+1][i] && cuts[j] + 1 < temp)
                        temp = cuts[j] + 1;
                }
                cuts[i] = temp;
            }
        }


        // print_vv(isPal);
        // print(cuts);

        return cuts[n-1];

    }

    
};

// O(n^3)
class Solution1 {
public:
    int minCut(string s) {
        int n = s.size();

        vvi dp(n, vi(n));


        for(int l=0; l<n; l++){
            for(int i=0; i<n-l; i++){
                int j = i+l;

                if(isPal(s, i, j)){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j] = INT_MAX;
                    for(int k=i; k<j; k++){
                        int cur = 1 + dp[i][k] + dp[k+1][j]; 
                        dp[i][j] = min(dp[i][j], cur);
                    }
                }


            }
        }

        // print_vv(dp);
        
        return dp[0][n-1];        
    }

    bool isPal(string &s, int l, int r){
        while(l<=r){
            if(s[l++]!=s[r--])
                return false;
        }
        return true;
    }    
};

class Solution {
    int n;
    vector<vector<bool>> isPal;
    vector<int> dp;
public:
    int minCut(string s) {
        n = s.size();
        isPal.assign(n, vector<bool>(n, true));
        dp.assign(n+1,n+1);
        
        for(int l=n-1; l>=0; --l){
            for(int r=l+1; r<n; ++r){
                isPal[l][r] = false;
                if(s[l]==s[r] && isPal[l+1][r-1])
                    isPal[l][r] = true;
            }
        }
        
        dp[n] = 0;
        for(int l=n-1; l>=0; --l){
            for(int r=l; r<n; ++r){
                if(isPal[l][r])
                    dp[l] = min(dp[l], 1 + dp[r+1]);
            }
        }
        
        return dp[0] - 1;
        // return parts(0,s)-1;
        
    }
    
    int parts(int l,string &s){
        if(l>=n) return 0;
        if(isPal[l][n-1]) return 1;
        int &ans = dp[l];
        if(~ans) return ans;
        ans = n-l;
        
        for(int pos=l; pos<n; ++pos){
            if(isPal[l][pos]){
                ans = min(ans, 1 + parts(pos+1, s));
            }
        }
        
        return ans;
    }
};

// @lc code=end
int main(){
	Solution sol; string s; int out;
	vs ss = {
		"a",
		"abb",
		"cabababcbc",
        "banana",
	};
	for(auto &s: ss)
		out = sol.minCut(s), deb(out);

	return 0;
}
