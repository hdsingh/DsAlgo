/*
 * @lc app=leetcode id=745 lang=cpp
 *
 * [745] Prefix and Suffix Search
 *
 * https://leetcode.com/problems/prefix-and-suffix-search/description/
 *
 * algorithms
 * Hard (33.34%)
 * Likes:    296
 * Dislikes: 187
 * Total Accepted:    17.2K
 * Total Submissions: 51.5K
 * Testcase Example:  '["WordFilter","f"]\n[[["apple"]],["a","e"]]'
 *
 * Given many words, words[i] has weight i.
 * 
 * Design a class WordFilter that supports one function, WordFilter.f(String
 * prefix, String suffix). It will return the word with given prefix and suffix
 * with maximum weight. If no word exists, return -1.
 * 
 * Examples:
 * 
 * 
 * Input:
 * WordFilter(["apple"])
 * WordFilter.f("a", "e") // returns 0
 * WordFilter.f("b", "") // returns -1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * words has length in range [1, 15000].
 * For each test case, up to words.length queries WordFilter.f may be made.
 * words[i] has length in range [1, 10].
 * prefix, suffix have lengths in range [0, 10].
 * words[i] and prefix, suffix queries consist of lowercase letters only.
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
#define sz(a) int((a).size())
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

struct trie{
    trie* ch[27] = {};
    int wt = 0;
};

// '{' -'a' = 26
// suf + #  + pre
// apple ->  #apple, e#apple, le#apple
class WordFilter {
    trie* root;
public:
    WordFilter(vector<string>& words) {
        root = new trie();
        int wt = 0;
        for(auto word: words){
            int n = word.size();
            for(int i=n; i>=0; --i){
                string s = word.substr(i) + '{' + word;
                insert(s, wt);
            }
            ++wt;
        } 
    }

    void insert(string &s, int wt){
        auto cur = root;
        for(int i=0; i<(int)s.size(); ++i){
            if(!cur->ch[s[i]-'a'])  
                cur->ch[s[i]-'a'] = new trie();
            cur = cur->ch[s[i]-'a'];
            cur->wt = max(cur->wt,wt);
        }
    }

    int search(string &s){
        auto cur = root;
        for(int i=0; i<(int)s.size(); ++i){
            if(!cur->ch[s[i]-'a']) return -1;
            cur = cur->ch[s[i]-'a'];
        }
        return cur->wt;
    }
    
    int f(string pre, string suf) {
        string s = suf + '{' + pre;
        return search(s);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// @lc code=end

int main(){
    vs words = {
    "abbbababbb",
    "baaabbabbb",
    "abababbaaa",
    "abbbbbbbba",
    "bbbaabbbaa","ababbaabaa",
    "baaaaabbbb","babbabbabb","ababaababb",
    "bbabbababa"};
    WordFilter wf(words);
    vector<vs> presufs = {
        {"","abaa"},{"babbab",""},
        {"ab","baaa"},{"baaabba","b"},{"abab","abbaabaa"},
        {"","aa"},{"","bba"},{"","baaaaabbbb"},
        {"ba","aabbbb"},{"baaa","aabbabbb"}
    };

    for(auto ps: presufs){
        int out = wf.f(ps[0], ps[1]); deb(out);
    }

    return 0;
}