/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (46.02%)
 * Likes:    280
 * Dislikes: 863
 * Total Accepted:    67.2K
 * Total Submissions: 145.8K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 * 
 * 
 * Example:
 * 
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 * 
 * 
 * 
 * Restrictions: 
 * 
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 * 
 */
#include "cpp.h"
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        if(!n) return s;
        if(!k) return s;
        for(int left = 0; left<n; left+=2*k){
            for(int i = left, j = min(left+k-1, n-1); i<j; i++,j--){
                swap(s[i], s[j]);
            }
        }
        return s;
    }
    string reverseStr2(string s, int k) {
        int n = s.size();
        if(!n) return s;
        if(!k) return s;
        for(int i=0; i<n; i+=k){
            if(i%(2*k)==0){
                int end = i+k-1<n-1 ? i+k-1: n-1;
                reverse(s, i, end);
            }
        }
        return s;
    }

    void reverse(string &s, int beg, int end){
        // deb(beg);
        // deb(end);
        int n = end - beg;
        if(!n) return;
        int mid = beg + (end-beg)/2;
        for(int i = beg; i<=mid; i++){
            // deb(i);
            // deb(end-(i-beg));
            mswap(s[i], s[end-(i-beg)]);
        }
    }

    void mswap(char &a, char &b){
        char temp = a;
        a = b;
        b = temp;
    }
};

int main(){
    Solution s;
    string st;
    int t, k;
    scanf("%d\n", &t);
    while(t--){
        getline(cin, st);
        scanf("%d\n", &k);
        // cout<<k;
        string out = s.reverseStr(st, k);
        cout<<out<<endl;
    }
}

