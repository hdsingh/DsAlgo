/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.64%)
 * Likes:    1196
 * Dislikes: 87
 * Total Accepted:    319.8K
 * Total Submissions: 631K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
#include "cpp.h"
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        if (!n) return -1;
        // vector<int> count(26, 0);
        int count[26] = {0};
        for(int i  = 0; i<n; i++){
            int index = s[i] - 'a';
            count[index]++;
        }


        for(int i=0; i<n; i++){
            int index = s[i] - 'a';
            if(count[index]==1) return i;            
        }
        return -1;
    }

    int firstUniqChar2(string s) {
        if (s.size()==0) return -1;
        // if (s.size()==1) return 0;
        unordered_map<char, pair<int, int>> m;
        //  char      times, index
        for(int i = 0; i<s.size(); i++){
            auto it = m.find(s[i]);
            if(it == m.end()){
                m.insert({s[i], {0, i}});
            }else{
                auto temp  = it->second;
                it->second = {temp.first+1, temp.second};
            }
        }

        int min_i = INT_MAX;
        for(auto i = m.begin(); i!=m.end(); i++){
            if(i->second.first==0){
                min_i = min(min_i, i->second.second);
            }
        }
        return min_i==INT_MAX ? -1 : min_i;
    }
};

int main(){
    Solution s;
    string st;
    int t;
    scanf("%d\n", &t);
    while(t--){
        getline(cin, st);
        int res = s.firstUniqChar(st);
        cout<<res<<endl;
    }
}
