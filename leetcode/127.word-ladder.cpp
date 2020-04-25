/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (27.73%)
 * Likes:    2491
 * Dislikes: 1015
 * Total Accepted:    367.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(unordered_map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Simple BFS: 108ms
class Solution0 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vs> genericList; // genric to word
        unordered_map<string, vs> wordToGeneric;
        unordered_map<string, bool> visited;
        queue<string> q;
        wordList.push_back(beginWord); // to create generics for beginword

        string nword, word;
        for(auto &word: wordList){
            for(int i=0; i<(int)word.size(); ++i){
                nword = word;
                nword[i] = '*';
                genericList[nword].push_back(word);
                wordToGeneric[word].push_back(nword);
            }
        }

        // for(auto p: wordToGeneric){
        //     cout<<p.first<< " : "<<endl;
        //     print(p.second);
        //     cout<<endl;
        // }

        if(wordToGeneric.find(endWord)==wordToGeneric.end()) return 0;

        visited[beginWord] = true;
        q.push(beginWord);
        
        int depth = 0;
        while(q.size()){
            ++depth;
            int breadth = q.size();
            for(int i=0; i<breadth; ++i){
                word = q.front(); q.pop();
                // deb(word);
                if(word==endWord) return depth;
                for(auto nword: wordToGeneric[word]){
                    for(auto otherword: genericList[nword])
                        if(!visited[otherword]){
                            visited[otherword] = true;
                            q.push(otherword);
                        }
                }
            }
        }

        return 0;
    }
};

// Bidirectional BFS : 24 ms
// Ref: https://leetcode.com/problems/word-ladder/discuss/40708/Share-my-two-end-BFS-in-C++-80ms./38545
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict;
        for(auto word: wordList)
            wordDict.insert(word);
        if(wordDict.find(endWord)==wordDict.end()) return 0;
        wordDict.erase(beginWord); 
        wordDict.erase(endWord);

        unordered_set<string>nextWords, prevWords;
        nextWords.insert(beginWord); prevWords.insert(endWord);
        int depth = 2, len = beginWord.length();

        while(!nextWords.empty() && !prevWords.empty()){
            if(nextWords.size()>prevWords.size())
                swap(nextWords, prevWords);
            auto it = nextWords.begin();

            unordered_set<string> temp;
            for(; it!=nextWords.end(); ++it){
                string word = *it;
                for(int p=0; p<len; ++p){
                    char letter = word[p];
                    for(int i=0; i<26; ++i){
                        word[p] = 'a' + i;
                        if(prevWords.find(word)!=prevWords.end())
                            return depth;
                        if(wordDict.find(word)!=wordDict.end()){
                            wordDict.erase(word);
                            temp.insert(word);
                        }
                    }
                    word[p] = letter;
                }
            }

            swap(nextWords,temp);
            ++depth;
        }

        return 0;
    }
};
// @lc code=end

int main(){
    Solution sol;
    string beginWord, endWord; vs wordList; int out;
    beginWord = "hit",
    endWord = "cog",
    wordList = { "hot","dot","dog","lot","log","cog" };
    out = sol.ladderLength(beginWord,endWord,wordList); deb(out);

    beginWord = "hit";
    endWord = "cog";
    wordList = { "hot","dot","dog","lot","log" };
    out = sol.ladderLength(beginWord,endWord,wordList); deb(out);

    return 0;
}
