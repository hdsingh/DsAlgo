#include <bits/stdc++.h>
using namespace std;

// O(n*n)
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
    
    int len = s.length();
    if (len==0) return 0;
    unordered_set<char> us;
    int max_len = 1;

    for(int i=0; i<len; i++){
        int j = i;
        int temp_len = 0;
        for(; j<len; j++){
            char temp = s[j];
            if( us.find(temp) == us.end() ){
                // cout<<i<<" inserting: "<<temp<<endl;
                us.insert(temp);
                temp_len++;
            }else{
                us.clear();
                break;
            }
            max_len = temp_len>max_len ? temp_len: max_len;
        }
    }
    return max_len;
    }
};


class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l(0), r(0), res(0);
        if (n==0) return 0;
        if (n==1) return 1;

        unordered_map<char, int> dict;

        while(r<n){
            if(dict.find(s[r]) == dict.end()){ //Not found
                dict[s[r]] = r;                // Insert in dict
                r++;                           // Slide the right window
                res = max(res, r-l);
            }else{
                dict.erase(s[l]);
                l++;
            }
        }
        return res;
    }
};
// "" : 0
// " ": 1

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l(0), r(0), res(0);
        if (n==0) return 0;
        if (n==1) return 1;

        unordered_set<char> dict;

        while(r<n){
            if(dict.find(s[r]) == dict.end()){ //Not found
                dict.insert(s[r++]);  // Insert in dict  and Slide the right window                   
                res = max(res, r-l);
            }else{
                dict.erase(s[l++]);
            }
        }
        return res;
    }
};

int main(){
    Solution *sol = new Solution;

    set<string> ss = {"", " ", "hharmn", "aab"};
    
    for(string s: ss)
        cout<<s<<" : "<<sol->lengthOfLongestSubstring(s)<<endl;

    // set<string> ss = {"au"};
    // for(string s: ss)
    //     cout<<sol->lengthOfLongestSubstring(s)<<endl;

    
}