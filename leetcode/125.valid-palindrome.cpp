/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (32.29%)
 * Likes:    693
 * Dislikes: 2055
 * Total Accepted:    410.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
#include "cpp.h"
using namespace std;

class Solution {
public:
    bool isPalindrome(string s){
        for(int i=0, j=s.size()-1; i<j; i++,j--){
            while(!isalnum(s[i]) && i<j) i++;
            while(!isalnum(s[j]) && i<j) j--;
            if(tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }

    bool isPalindrome1(string s) {
        if(s.size()<=1) return true;
        s = validate(s);
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }

    string validate(string s){
        string out;
        for(char &ch: s){
            if(isalnum(ch)){
                out += tolower(ch);
            }
        }
        return out;
    }

};

// for integer, only base speacific, here for 10
// for other bases pass base coverted number
bool isPal(int x){
    int n = 0, m =x;
    while(x){
        n = n*10 + x%10;
        x/=10;
    }
    return n==m;
}

int main(){
    Solution sol;
    int times;
    string st;
    scanf("%d\n", &times);
    while(times--){
        getline(cin, st);
        bool out = sol.isPalindrome(st);
        cout<<out<<endl;
    }
}
