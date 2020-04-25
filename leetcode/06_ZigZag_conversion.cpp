// https://leetcode.com/problems/zigzag-conversion/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout<< #x << ": "<< x << endl;

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};
int main(){
    Solution s;
    set<string> ss = {
                    "0123456789",
                    };

    for(string x : ss){
        cout<<s.convert(x, 4)<<endl;
    }

}