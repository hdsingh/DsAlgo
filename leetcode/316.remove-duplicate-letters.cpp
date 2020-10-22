#include <bits/stdc++.h>
using namespace std;

// I can replace a greater char only if it could be found later
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> last(26), used(26);
        for(int i=0; i<n; ++i)
            last[s[i]-'a'] = i;
        
        string out;
        for(int i=0; i<n; ++i){
            if(!used[s[i]-'a']){
                used[s[i]-'a'] = 1;
                while(out.size() && out.back()>s[i] && last[out.back()-'a']>i){
                    used[out.back()-'a'] = 0;
                    out.pop_back();
                }
                out+=s[i];
            }
        }
        return out;
    }
};

int main(){
        
    return 0;
}