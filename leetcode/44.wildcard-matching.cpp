#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;
public:
    bool isMatch(string s, string p) {
        dp.assign(s.size()+1, vector<int>(p.size()+1,-1));
        return isMatch(0,0,s,p);
    }
    
    bool isMatch(int x, int y, string &s, string &p){
        if(x==s.size() && y==p.size()) return true;
        if(y==p.size()) return false;
        int &ans = dp[x][y];
        if(~ans) return ans;
        
        ans = false;
        if(x==s.size()){
            // valid if all remining in p are *
            while(y<p.size() && p[y]=='*') ++y;
            return ans = (y==p.size());
        }
        
        if(p[y]=='*'){
            // 0 matches or more
            return ans = (isMatch(x,y+1,s,p) || isMatch(x+1,y,s,p));
        }else if(p[y]==s[x] || p[y]=='?'){
            return ans = isMatch(x+1,y+1,s,p);   
        }
        
        return ans = false;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}