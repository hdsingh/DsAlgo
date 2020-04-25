/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (53.45%)
 * Likes:    852
 * Dislikes: 117
 * Total Accepted:    397.4K
 * Total Submissions: 741.7K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
#include "cpp.h"
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> count(26, 0);
        for(int i = 0; i<s.size(); i++){
            int index_s = s[i] - 'a';
            count[index_s]++;

            int index_t = t[i] - 'a';
            count[index_t]--;
        }

        for(int i: count){
            if(i!=0) return false;
        }

        return true;
    }

    bool isAnagram2(string s, string t) {
        unordered_map<char, int> count;
        for(char c: s) count[c]++;
        for(char c: t) count[c]--;
        
        for(auto it = count.begin(); it!=count.end(); it++){
            if(it->second!=0) return false;
        }

        return true;
    }
};

int main(){
    Solution sol;
    int times;
    string s, t;
    scanf("%d\n", &times);
    while(times--){
        getline(cin, s);
        getline(cin, t);
        int res = sol.isAnagram(s,t);
        cout<<res<<endl;
    }
}

