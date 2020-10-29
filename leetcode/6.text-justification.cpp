#include <bits/stdc++.h>
using namespace std;

// Place the first word at the beg,
// now count how many extra words can we place (len+1+word) (1+word.len = " " + word)
// now count the remlen (W-first word) and the len available for spaces
// distribute these spaces evenly. len/k + (len%k) for the mod.
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int W) {
        int n = words.size();
        vector<string> out;
        for(int i=0; i<n; ++i){
            int j = i; 
            string cur = words[i];
            int len = words[i].size();
            
            int extra_words_len = 0;
            while(j+1<n && len + 1 + words[j+1].size()<=W){
                len+= 1+words[j+1].size();
                extra_words_len+=words[j+1].size();
                ++j;
            }
            
            if(j==n-1){
                ++i; // ith word already included
                while(i<n){
                    cur+=" "+words[i++];
                }
                // fill the end with spaces
                while(cur.size()<W) cur+=" ";
            }else{
                if(j==i){ // single word
                    while(cur.size()<W) cur+=" ";
                }else{
                    int rem_len = W - words[i].size() - extra_words_len; // of spaces
                    // rem len equal split
                    int rem_word_cnt = j - i; 
                    
                    int extra_space = rem_len%rem_word_cnt; // per word
                    for(int k=1; k<=rem_word_cnt; ++k){
                        int space_here = rem_len/rem_word_cnt;
                        if(extra_space>0){
                            space_here++;
                            --extra_space;
                        }
                        
                        while(space_here > 0){
                            cur+=" ";
                            --space_here;
                        }
                        cur+=words[i+k];
                    }
                    
                }
                i = j;
            }
            
            out.push_back(cur);            
        }
        
        return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}