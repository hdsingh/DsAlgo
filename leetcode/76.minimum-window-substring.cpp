#include <bits/stdc++.h>
using namespace std;

// keep on adding letters till all are not covered
// only if count of char in substr s less than actually req, it increases the cover
// once coevr is created don't let it decrease, 
// by removing only if we have extra
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> req(128), has(128);
        for(auto x: t) req[x]++;
        
        int min_len = n+1, at = -1, covered = 0;
        for(int lt=0, rt=0; rt<n; ++rt){
            has[s[rt]]++;
            if(has[s[rt]]<=req[s[rt]] && covered<m)
                ++covered;

            if(covered==m && req[s[rt]]>0){
                while(lt<rt && has[s[lt]]>req[s[lt]])
                    --has[s[lt++]];

                int len = rt-lt+1;
                if(len<min_len){
                    min_len = len;
                    at = lt;
                }
            }
        }
        
        if(min_len>n) return "";
        return s.substr(at,min_len);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}