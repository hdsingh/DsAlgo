#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a = find_count(word1);
        vector<int> b = find_count(word2);
        set<char> s1(word1.begin(), word1.end());
        set<char> s2(word2.begin(), word2.end());
        return (a==b && s1==s2);
    }
    
    vector<int> find_count(string &s){
        vector<int> cnt(26);
        for(auto x: s) cnt[x-'a']++;
        vector<int> out;
        for(int i=0; i<26; ++i)
            if(cnt[i])
                out.push_back(cnt[i]);
        sort(out.begin(), out.end());
        return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}