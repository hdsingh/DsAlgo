/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.12%)
 * Likes:    1625
 * Dislikes: 1480
 * Total Accepted:    548.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
#include "cpp.h"
#include "extra.h"
using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(!n) return "";
        
        string l_prefix;
        bool not_eq_f = false;
        for(int char_loc =0 ; char_loc<strs[0].size(); char_loc++){
            char c = strs[0][char_loc];
            
            int j = 1;
            if(not_eq_f) break;
            while(j<n){
                if(!strs[j][char_loc]) {not_eq_f = true; break;}
                if(strs[j][char_loc]!=c) {not_eq_f = true; break;}
                j++;
            }
            if(!not_eq_f) l_prefix += strs[0][char_loc];
            
        }
        
        return l_prefix;
            
        
    }
};

