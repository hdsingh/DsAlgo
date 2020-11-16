#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> to_num = {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        
        int ans = 0, n = s.size();
        for(int i=0; i<n; ++i){
            if(i+1<n && to_num[s[i]]<to_num[s[i+1]])
                ans-=to_num[s[i]];
            else 
                ans+=to_num[s[i]];
        }
    
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}