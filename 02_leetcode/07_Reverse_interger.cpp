// https://leetcode.com/problems/reverse-integer/

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

class Solution {
public:
    int reverse(int x) {
        int t;
        long long out(0);
        long long neg = x<0 ? -1:1;
        x = x*neg;

        while(x>0){
            out = out*10 + x%10;
            x/=10;
        }
        return (out<INT_MIN || out>INT_MAX)? 0:neg*out;
    }
};

int main(){
    Solution s;
    cout<<s.reverse(1539);
    string a = "rklke";
    
}