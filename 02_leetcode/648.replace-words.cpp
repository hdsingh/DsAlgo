/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 *
 * https://leetcode.com/problems/replace-words/description/
 *
 * algorithms
 * Medium (55.33%)
 * Likes:    609
 * Dislikes: 126
 * Total Accepted:    49.4K
 * Total Submissions: 89.2K
 * Testcase Example:  '["cat", "bat", "rat"]\n"the cattle was rattled by the battery"'
 *
 * In English, we have a concept called root, which can be followed by some
 * other words to form another longer word - let's call this word successor.
 * For example, the root an, followed by other, which can form another word
 * another.
 * 
 * Now, given a dictionary consisting of many roots and a sentence. You need to
 * replace all the successor in the sentence with the root forming it. If a
 * successor has many roots can form it, replace it with the root with the
 * shortest length.
 * 
 * You need to output the sentence after the replacement.
 * 
 * Example 1:
 * 
 * 
 * Input: dict = ["cat", "bat", "rat"]
 * sentence = "the cattle was rattled by the battery"
 * Output: "the cat was rat by the bat"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input will only have lower-case letters.
 * 1 <= dict words number <= 1000
 * 1 <= sentence words number <= 1000
 * 1 <= root length <= 100
 * 1 <= sentence words length <= 1000
 * 
 * 
 * 
 * 
 */
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

// @lc code=start

struct TrieNode{
    bool eow; // end of word
    TrieNode* children[26];
    TrieNode(){
        eow = false;
        memset(children, NULL, sizeof(children));
    }
};

class Trie {
    TrieNode* root;    
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* cur = root;
        for(auto x: word){
            if(!cur->children[x-'a'])
                cur->children[x-'a'] = new TrieNode();
            cur = cur->children[x-'a'];
            if(cur->eow) return; // stop early
        }
        cur->eow = true;
    }

    string find_perfix(const string &word){
        string out;
        TrieNode* cur = root;
        for(auto x: word){
            if(!cur->children[x-'a']) return word;
            out+=x;
            cur = cur->children[x-'a'];
            if(cur->eow){
                return out;
            }
        }

        return word;
    }

    ~Trie(){
        clear(root);
    }
    
    void clear(TrieNode* cur){
        for(int i=0; i<26; ++i){
            if(cur->children[i]) clear(cur->children[i]);
        }
        delete cur;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sen) {
        string out;
        Trie trie;
        for(auto w: dict)
            trie.insert(w);
        int n = sen.size();
        int i = 0;
        while(i<n){
            string word;
            while(i<n && sen[i]!=' '){
                word+=sen[i++];
                if(i==n) break;
            }
            ++i;
            string cur = trie.find_perfix(word);
            out+=cur;
            if(i<n) out+=" "; 
        }
        return out;
    }
};
// @lc code=end

int main(){
    Solution sol; vs dict; string sentence,out;;
    dict = { "cat", "bat", "rat" };
    sentence = "the cattle was rattled by the battery";
    out = sol.replaceWords(dict,sentence); deb(out);
    return 0;
}
