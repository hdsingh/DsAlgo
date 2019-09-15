// https://leetcode.com/contest/biweekly-contest-8/problems/count-substrings-with-only-one-distinct-letter/

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

class Solution {
public:
    int countLetters(string S) {
        int l = S.length();
        int out(l);

        for(int i=0; i<l; i++){
            int j = i+1;
            while(S[i]==S[j]){
                out++;
                j++;
            }
        }
        return out;
    }
};

int main(){
    Solution s;
    cout<<s.countLetters("aaaaaaaaaa");
}