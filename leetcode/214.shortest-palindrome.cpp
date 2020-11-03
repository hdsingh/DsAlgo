#include <bits/stdc++.h>
using namespace std;

// I want to find the longest pandrome in the begining.
// Length of longest proper prefix that is also a suf
// Since a palinfrome upon reversing will stay same.
// s:    cdcxy
// rev:  xycdc

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string r = s;
        reverse(r.begin(), r.end());
        int len = kmp(s + "#" + r);
        return r.substr(0,n-len) + s;  
    }

    int kmp(string s){
        int n = s.size();
        vector<int> pi(n);
        int i = 1, len = 0;
        while(i<n){
            if(s[i]==s[len]) pi[i++] = ++len;
            else if(len) len = pi[len-1];
            else ++i;
        }
        return pi.back();
    }
};

class Solution1 {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        for(int i=0; i<n; ++i){
            if(s.substr(0,n-i)==rev.substr(i))
                return rev.substr(0,i) + s;
        }
        
        return "";
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}