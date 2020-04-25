#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<vector<string>> vvs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}


class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vvs possible_words;
        vs sub;
        int beg = 0;
        unordered_map<char, int> lc; //letterCount
        for(char c: letters){
            lc[c]++;
        }
        unordered_map<char, int> scorer;
        for(int i=0; i<26; i++){
            char c = int('a') + i;
            scorer[c] = score[i];
        }

        formWords(beg, sub, possible_words, words, lc);

        int max_score = 0;
        for(vs formed: possible_words){
            int cur_score = 0;
            for(string s: formed)
                for(char c: s)
                    cur_score+=scorer[c];
            max_score = max(cur_score, max_score);
        }
        

        return max_score;
    }

    void formWords(int beg, vs sub, vvs &possible_words, vs &words, unordered_map<char, int> lc){
        int n = words.size();
        if(sub.size())
                possible_words.push_back(sub);

        if(beg>=n){
            if(sub.size())
                return;            
            
        }

        for(int i=beg; i<n; i++){
            if(can_be_formed(words[i], lc)){
                sub.push_back(words[i]);
                unordered_map<char, int> new_lc = dec_lc(words[i], lc);
            formWords(i+1, sub, possible_words, words, new_lc);
            sub.pop_back();
            }
        }
    }

    bool can_be_formed( string word, unordered_map<char, int> lc){
        bool formed = true;
        for(int c: word){
            if(lc.find(c)!=lc.end()){
                if(lc[c])
                    lc[c]--;
                else{
                    formed = false;
                    break;
                }
            }else{
                formed=false;
                break;
            }
        }

        return formed;
    }

    unordered_map<char, int> dec_lc( string word, unordered_map<char, int> lc){
        for(int c: word){
            lc[c]--;
        }

        return lc;
    }


};

int main(){
    Solution sol;
    vs words; vector<char> letters; vi score;
    words = {"dog","cat","dad","good"};
    letters = {'a','a','c','d','d','d','g','o','o'};
    score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    cout<<sol.maxScoreWords(words, letters,score)<<endl;

    words = {"xxxz","ax","bx","cx"};
    letters = {'z','a','b','c','x','x','x'};
    score = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
    cout<<sol.maxScoreWords(words, letters,score)<<endl;

    words = {"leetcode"};
    letters = {'l','e','t','c','o','d'};
    score = {0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0};
    cout<<sol.maxScoreWords(words, letters,score)<<endl;


    return 0;
}