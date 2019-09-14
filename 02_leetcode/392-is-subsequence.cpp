// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

class Solution {
public:
    bool isSubsequence(string t, string s) {
        int i(0), j(0);
        int n = s.length();
        int m = t.length();
        
        while(i<n && j<m){
            if(s[i++]==t[j]) j++;
        }
        return j==m;
    }
};

int main(){
    string a = "abc";
    string b = "ahbgdc";

    Solution s;
    cout<<s.isSubsequence(a , b);
}