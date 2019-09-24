/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (38.36%)
 * Likes:    1834
 * Dislikes: 141
 * Total Accepted:    146.7K
 * Total Submissions: 381.2K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */
#include "cpp.h"
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int p_size = p.size();
        if(s.size()<p_size) return res;
        vector<int> sv(26, 0);
        vector<int> pv(26, 0);

        for(int i = 0; i<p_size; i++){
            pv[p[i]-'a']++;
            sv[s[i]-'a']++;
        }
        
        if(pv == sv)
           res.push_back(0);

        for(int i = p_size; i<s.size(); i++){
            sv[s[i]-'a']++;
            sv[s[i-p_size] -'a']--;

            if(pv == sv)
            res.push_back(i-p_size+1);
        }

        return res;
        
    }

    bool isanagram(string s, string p){
        unordered_map<char, int> um;
        
        for(int i = 0; i<s.size(); i++){
            um[s[i]]++;
            um[p[i]]--;
        }
        for(auto it =um.begin(); it!=um.end(); it++){
            if(it->second!=0) return false;
        }
        return true;
    }

    // O(sp)
    vector<int> findAnagrams2(string s, string p) {
        vector<int> res;
        if(s.size()<p.size()) return res;
        unordered_map<char, int> um;
        unordered_map<char, int> um_p;
        for(char c: p) um_p[c]++;
        for(int i=0,j=p.size()-1; i<=s.size()-p.size(); i++, j++){
            if(i==0){
                for(int k = 0; k<=j; k++)
                    um[s[k]]++;
            }else{
                um[s[i-1]]--;
                um[s[j]]++;
                if(um[s[i-1]]==0) um.erase(s[i-1]);
            }

            bool is_ana = true;
            for(char c: p){
                if(um[c]!=um_p[c]){
                    is_ana = false;
                    break;
                }
            }
            if(is_ana) res.push_back(i);
        }
        return res;
    }
    
    // O(sp)
    vector<int> findAnagrams1(string s, string p) {
        vector<int> res;
        if(s.size()<p.size()) return res;
        for(int i=0,j=p.size()-1; i<=s.size()-p.size(); i++, j++){
            string s1 = s.substr(i, p.size());
    
            if(isanagram(s1, p)) res.push_back(i);
        } 
        return res;
    }

};

int main(){
    Solution sol;
    int times;
    string s, p;
    scanf("%d\n", &times);
    while(times--){
        getline(cin, s);
        getline(cin, p);
        vi res = sol.findAnagrams(s, p);
        print(res);
    }
}
