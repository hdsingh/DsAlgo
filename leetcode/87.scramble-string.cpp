#include <bits/stdc++.h>
using namespace std;

// s1: |_a_|_______b______|
// s2: |_a_|________b_____|
// or 
// s1: |_a_|_______b______|
// s2: |________b_____|_a_|
// then s1==s2;

class Solution0 {
    vector<vector<vector<int>>> can;
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        can.assign(n+1, vector<vector<int>>(n, vector<int>(n,-1)));
        return isScramble(n,0,0, s1, s2);
    }
    
    bool isScramble(int len, int sx, int sy, string &s1, string &s2){
        if(len==1){
            return s1[sx]==s2[sy];
        }
        int &ans = can[len][sx][sy];
        if(~ans) return ans;
        
        ans = false;
        for(int l=1; l<len; ++l){
            if(isScramble(l, sx, sy, s1, s2) && 
               isScramble(len-l, sx+l, sy+l, s1, s2)) 
                 return ans = true;
            
            if(isScramble(l, sx, sy+len-l, s1, s2) && 
               isScramble(len-l, sx+l, sy, s1, s2))
                return ans = true;
        }
        
        return ans = false;
    }
};

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        bool can[n+1][n][n];
        memset(can, 0, sizeof(can));
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                can[1][i][j] = (s1[i] == s2[j]);
            }
        }
        
        for(int len=2; len<=n; ++len){
            for(int sx=0; sx+len<=n; ++sx){
                for(int sy=0; sy+len<=n; ++sy){
                    
                    for(int l=1; l<len; ++l){
                        if(can[l][sx][sy] && can[len-l][sx+l][sy+l])
                            can[len][sx][sy] = 1;
                        
                        if(can[l][sx][sy+len-l] && can[len-l][sx+l][sy])
                            can[len][sx][sy] = 1;
                    }
                }
            }
        }
        
        return can[n][0][0];
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}