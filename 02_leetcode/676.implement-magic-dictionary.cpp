/*
 * @lc app=leetcode id=676 lang=cpp
 *
 * [676] Implement Magic Dictionary
 *
 * https://leetcode.com/problems/implement-magic-dictionary/description/
 *
 * algorithms
 * Medium (53.33%)
 * Likes:    508
 * Dislikes: 120
 * Total Accepted:    35.3K
 * Total Submissions: 66K
 * Testcase Example:  '["MagicDictionary", "buildDict", "search", "search", "search", "search"]\n[[], [["hello","leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]'
 *
 * 
 * Implement a magic directory with buildDict, and search methods.
 * 
 * 
 * 
 * For the method buildDict, you'll be given a list of non-repetitive words to
 * build a dictionary.
 * 
 * 
 * 
 * For the method search, you'll be given a word, and judge whether if you
 * modify exactly one character into another character in this word, the
 * modified word is in the dictionary you just built.
 * 
 * 
 * Example 1:
 * 
 * Input: buildDict(["hello", "leetcode"]), Output: Null
 * Input: search("hello"), Output: False
 * Input: search("hhllo"), Output: True
 * Input: search("hell"), Output: False
 * Input: search("leetcoded"), Output: False
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that all the inputs are consist of lowercase letters a-z.
 * For contest purpose, the test data is rather small by now. You could think
 * about highly efficient algorithm after the contest.
 * Please remember to RESET your class variables declared in class
 * MagicDictionary, as static/class variables are persisted across multiple
 * test cases. Please see here for more details.
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
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

struct TrieNode{
    bool eow; // end of word
    TrieNode* children[26];
    TrieNode(){
        eow = false;
        memset(children, NULL, sizeof(children));
    }
};

class MagicDictionary {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode(); 
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto word: dict){
            TrieNode* cur = root;
            for(auto x: word){
                if(!cur->children[x-'a'])
                    cur->children[x-'a'] = new TrieNode();
                cur = cur->children[x-'a'];
            }
            cur->eow = true;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int n = word.size();
        return search(word, 0, false, root, n);
    }

    bool search(string &word, int pos, bool changed, TrieNode* cur, const int &n){
        if(pos==n){
            if(changed && cur->eow) return true;
            return false;
        }

        int here = word[pos]-'a';
        for(int i=0; i<26; ++i){
            if(cur->children[i]){
                if(here!=i && !changed){
                    if(search(word,pos+1,true,cur->children[i],n)) return true;
                }
                else{
                    if(i==here && search(word,pos+1,changed,cur->children[i],n)) return true;
                }
            }
        }

        return false;
    }

    ~MagicDictionary(){
        clear(root);
    }
    
    void clear(TrieNode* cur){
        for(int i=0; i<26; ++i){
            if(cur->children[i]) clear(cur->children[i]);
        }
        delete cur;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

int main(){
    MagicDictionary magic; bool out;
    magic.buildDict({"hello", "leetcode"});
    out = magic.search("hello"); deb(out);
    out = magic.search("hhllo"); deb(out);
    out = magic.search("hell"); deb(out);
    out = magic.search("leetcoded"); deb(out);
    return 0;
}

