/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (32.87%)
 * Likes:    1046
 * Dislikes: 1498
 * Total Accepted:    495.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
// #include "cpp.h"
// using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return KMPSearch(haystack, needle);
    }
    vector<int> kmpProcess(string st) {
            int n = st.size();
            vector<int> lps(n, 0);
            for (int i = 1, len = 0; i < n;) {
                // deb(i);
                // deb(len);
                if (st[i] == st[len]) {
                    lps[i++] = ++len;
                    // cout<<"eq, lps: ";print(lps);
                } else if (len) {
                    len = lps[len - 1];
                    // cout<<"len final: "<<len<<endl;

                } else {
                    // cout<<"else: lps ["<<i<<"] == 0"<<endl;
                    lps[i++] = 0;
                }
            }
            return lps;
        }

    int KMPSearch(string s, string p){
        int n = s.size();
        int m = p.size();
        if(m==0) return 0;

        vector<int> lps = kmpProcess(p);


        int i = 0;
        int j = 0;
        while(i<n){

            if(s[i]==p[j]){
                i++; j++;
            }

            if(j==m) return i-j;

            else{
                if(j) j = lps[j-1];
                else i = i+1;
            }
        }
        return -1;
    }
};

