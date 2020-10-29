#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        return isMatch(n-1,m-1,s,p);
    }
    
    bool isMatch(int x, int y, string &s, string &p){
        if(x<0 && y<0) return true;
        if(y<0) return false;
        if(x<0){
            while(y>0 && p[y]=='*') y-=2; // to skip prev char
            return (y<0);
        }
        
        if(p[y]=='*'){
            // 0 or  more
           return (isMatch(x,y-2,s,p) || 
                  ((s[x]==p[y-1] || p[y-1]=='.') && isMatch(x-1,y,s,p)) ); 
        }else if(p[y]=='.' || p[y]==s[x]){
            return isMatch(x-1,y-1,s,p);
        }
        
        return false;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}