#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        int sum = k-n;
        for(int i=n-1; i>=0 && sum>0; --i){
            int gain = min('z'-'a', sum);
            ans[i]+=gain;
            sum-=gain;
        }
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}