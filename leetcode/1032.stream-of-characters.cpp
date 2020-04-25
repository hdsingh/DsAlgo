/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 *
 * https://leetcode.com/problems/stream-of-characters/description/
 *
 * algorithms
 * Hard (46.78%)
 * Likes:    294
 * Dislikes: 56
 * Total Accepted:    17.2K
 * Total Submissions: 36.6K
 * Testcase Example:  '["StreamChecker","query","query","query","query","query","query","query","query","query","query","query","query"]\n[[["cd","f","kl"]],["a"],["b"],["c"],["d"],["e"],["f"],["g"],["h"],["i"],["j"],["k"],["l"]]'
 *
 * Implement the StreamChecker class as follows:
 * 
 * 
 * StreamChecker(words): Constructor, init the data structure with the given
 * words.
 * query(letter): returns true if and only if for some k >= 1, the last k
 * characters queried (in order from oldest to newest, including this letter
 * just queried) spell one of the words in the given list.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init
 * the dictionary.
 * streamChecker.query('a');          // return false
 * streamChecker.query('b');          // return false
 * streamChecker.query('c');          // return false
 * streamChecker.query('d');          // return true, because 'cd' is in the
 * wordlist
 * streamChecker.query('e');          // return false
 * streamChecker.query('f');          // return true, because 'f' is in the
 * wordlist
 * streamChecker.query('g');          // return false
 * streamChecker.query('h');          // return false
 * streamChecker.query('i');          // return false
 * streamChecker.query('j');          // return false
 * streamChecker.query('k');          // return false
 * streamChecker.query('l');          // return true, because 'kl' is in the
 * wordlist
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 2000
 * Words will only consist of lowercase English letters.
 * Queries will only consist of lowercase English letters.
 * The number of queries is at most 40000.
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

struct trie{
    bool eow = false;
    trie* ch[26] = {};
};

// for each query either start from root
// or extend the previous pointers to next pos if the letter is found
class StreamChecker0 {
    trie* root;
    vector<trie*> saved;
public:
    StreamChecker0(vector<string>& words) {
        root = new trie();
        saved = {root};
        for(auto &word: words)
            insert(word);
    }

    void insert(string &word){
        trie* cur = root;
        for(auto x: word){
            if(!cur->ch[x-'a'])
                cur->ch[x -'a'] = new trie();
            cur = cur->ch[x-'a'];
        }
        cur->eow = true;
    }
    
    bool query(char l) {
        vector<trie*> new_saved = {root};
        bool out = false;
        
        // Not needed by just initialising in saved and new_saved
        // 1. start from root
        // if(root->ch[l-'a']){
        //     if(root->ch[l-'a']->eow)
        //         out = true;
        //     new_saved.push_back(root->ch[l-'a']);
        // }
        
        // 2. check by continuing prev saved
        for(auto cur: saved){
            if(cur->ch[l-'a']){
                if(cur->ch[l-'a']->eow)
                    out = true;
                new_saved.push_back(cur->ch[l-'a']);
            }
        }        

        saved = new_saved;
        return out;
    }
};

// 1. Insert the words in reverse
// 2. Accumulate the stream and start searching from the end
class StreamChecker {
    trie* root;
    string saved; // accumulated stream
    int n; // size of saved;
public:
    StreamChecker(vector<string>& words) {
        root = new trie();
        saved.clear(); n = 0;
        for(auto &word: words){
            reverse(word.begin(), word.end());
            insert(word);
        }
    }

    void insert(string &word){
        trie* cur = root;
        for(auto x: word){
            if(!cur->ch[x-'a'])
                cur->ch[x -'a'] = new trie();
            cur = cur->ch[x-'a'];
        }
        cur->eow = true;
    }
    
    bool search(){
        trie* cur = root;
        for(int i=n-1; i>=0; --i){
            int x = saved[i]-'a';
            if(!cur->ch[x]) return false;
            if(cur->ch[x]->eow) return true;
            cur = cur->ch[x];
        }

        return false;
    }

    bool query(char l) {
        saved+=l; ++n;
        return search();
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end

int main(){
    bool out; vs words = { "cd","f","kl" };
    // words = {"baa"};
    StreamChecker streamChecker(words); // init
    out = streamChecker.query('a'); deb(out);          // return false
    out = streamChecker.query('b'); deb(out);          // return false
    out = streamChecker.query('c'); deb(out);          // return false
    out = streamChecker.query('d'); deb(out);          // return true, because 'cd' is in the
    out = streamChecker.query('e'); deb(out);          // return false
    out = streamChecker.query('f'); deb(out);          // return true, because 'f' is in the
    out = streamChecker.query('g'); deb(out);          // return false
    out = streamChecker.query('h'); deb(out);          // return false
    out = streamChecker.query('i'); deb(out);          // return false
    out = streamChecker.query('j'); deb(out);          // return false
    out = streamChecker.query('k'); deb(out);          // return false
    out = streamChecker.query('l'); deb(out);          // return true, because 'kl' is in the    
    return 0;
}
