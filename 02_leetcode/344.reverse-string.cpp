/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (64.03%)
 * Likes:    874
 * Dislikes: 565
 * Total Accepted:    498.5K
 * Total Submissions: 777.8K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters char[].
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * You may assume all the characters consist of printable ascii
 * characters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * 
 * 
 */
#include "cpp.h"
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) return;
        int n = s.size()-1;
        int mid = n/2;
        int i = 0;
        while(i<=mid){
            swap(s[i], s[n-i]);
            i++;
        }
        for(char c: s) cout<<c;
        cout<<endl;
    }

};

int main(){
    Solution s;
    string st;
    while(getline(cin, st)){
        vector<char> v;
        for(char c: st){
            v.push_back(c);
        }
        s.reverseString(v);
    }

}
