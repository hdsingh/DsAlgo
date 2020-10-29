#include <bits/stdc++.h>
using namespace std;

// Idea same as prev
// instead of checking every substr, lets save what idx can be formed 
// at an idx for faster comparison.
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size(), len = words[0].size();
        unordered_map<string,int> word_to_idx;
        vector<int> word_cnt;
        
        for(auto &word: words){
            if(!word_to_idx.count(word)){
                int idx = word_to_idx.size();
                word_to_idx[word] = idx;
                word_cnt.push_back(1);
            }else{
                int idx = word_to_idx[word];
                word_cnt[idx]++;
            }
        }
 
        vector<int> word_here(n,-1);
        for(int i=0; i+len<=n; ++i){
            string cur = s.substr(i,len);
            if(word_to_idx.count(cur))
                word_here[i] = word_to_idx[cur];
        }

        vector<int> out;
        for(int i=0; i+m*len<=n; ++i){
            vector<int> ncnt(word_cnt.size());
            bool valid = true;
            for(int j=i; j<i+m*len; j+=len){
                int here = word_here[j];
                if(here==-1 || ++ncnt[here]>word_cnt[here]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                out.push_back(i);
            }
        }
        return out;
    }
};


// Main idea: by brute force check at each pos in s
// for a single check starting at j, check each cur word of size len
// If we have not seen this word then the substring can't be formed
// or if the count exceeds for some substr, it will be invalid
// else we reach the end and form the complete str.
class Solution1 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size(), len = words[0].size();
        unordered_map<string,int> word_cnt;
        for(auto &word: words) 
            word_cnt[word]++;
        
        vector<int> out;
        for(int i=0; i+m*len<=n; ++i){
            unordered_map<string,int> ncnt;
            bool valid = true;
            for(int j=i; j<i+m*len; j+=len){
                string cur = s.substr(j,len);
                if(!word_cnt.count(cur) || ++ncnt[cur]>word_cnt[cur]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                out.push_back(i);
            }
        }
        return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}