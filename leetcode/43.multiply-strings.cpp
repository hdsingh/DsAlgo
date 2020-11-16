#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size()<num2.size()) swap(num1, num2);
        int n = num1.size(), m = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        vector<int> out(n+m);
        for(int i=0; i<n; ++i){
            int carry = 0;
            for(int j=0; j<m; ++j){
                int prod = (num1[i]-'0')*(num2[j]-'0');
                carry +=out[i+j] + prod;
                out[i+j] = carry%10;
                carry/=10;
            }
            
            if(carry){
                out[i+m] = carry;
            }
        }

        while(out.size() && out.back()==0)
            out.pop_back();
        reverse(out.begin(), out.end());
        string ans;
        for(auto x: out)
            ans+=('0'+x);
        if(ans.empty()) return "0";
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}