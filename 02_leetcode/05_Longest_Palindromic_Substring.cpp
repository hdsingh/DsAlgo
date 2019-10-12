// https://leetcode.com/problems/longest-palindromic-substring/

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ": " << x << endl;

template<typename... T>
void write(T&&... args) { //rvalue reference is new to C++ 
	((cout << args << " "), ...);
}


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start(0), end(0);
        for(int i=0; i<n; i++){
            int len1 = findPalAroundCenter(s, i, i); // cbbc
            int len2 = findPalAroundCenter(s, i, i+1);  // cbc
            int len = max(len1, len2);

            if(len>end-start){
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end-start+1);
    }

    int findPalAroundCenter(string s, int l, int r){
        int L(l), R(r);
        while(L>=0 && R<s.length() && s[L]==s[R]){
            L--;
            R++;
        }
        return R-L-1;
    }
};


int main(){
    // Solution *s = new Solution();
    Solution s;
    set<string> ss = {
                       "fggh",
                    //   "skokolghk",
                      };
    for(string x : ss)
        cout<<s.longestPalindrome(x)<<endl;

}