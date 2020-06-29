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
typedef vector<string> vs;

struct TrieNode{
    bool eow = false;
    TrieNode* ch[26] = {};
};

class Trie {
    TrieNode* root;    
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
        TrieNode* cur = root;
        for(auto x: word){
            if(!cur->ch[x-'a'])
                cur->ch[x-'a'] = new TrieNode();
            cur = cur->ch[x-'a'];
        }
        cur->eow = true;
    }

    bool search(string &word){
        TrieNode* cur = root;
        for(auto x: word){
            if(!cur->ch[x-'a']) return false;
            cur = cur->ch[x-'a'];
        }
        return cur->eow;
    }

    void remove(string &word){
        remove(word, root, 0);
    }

    // is_childless
    bool is_empty(TrieNode* cur){
        for(int i=0; i<26; ++i)
            if(cur->ch[i])
                return false;
        return true;
    }

    TrieNode* remove(string &word, TrieNode* cur, int depth){
        if(!cur) return NULL;
        
        if(depth==(int)word.size()){
            if(cur->eow) cur->eow = false;
            
            if(is_empty(cur)){
                delete(cur);
                cur = NULL;
            }
            return cur;
        }

        int index = word[depth]-'a';
        cur->ch[index] = remove(word, cur->ch[index], depth+1);
        
        if(is_empty(cur) && !cur->eow){
            delete(cur);
            cur = NULL;
        }
        return cur;
    }

    ~Trie(){
        clear(root);
    }
    
    void clear(TrieNode* cur){
        for(int i=0; i<26; ++i){
            if(cur->ch[i]) clear(cur->ch[i]);
        }
        delete cur;
    }
};

// 3 Cases for removal: 
// 1. word has no prefix and no other word having this word as prefix -> remove all
// 2. word has a prefix -> remove till the longest prefix
// 3. word is a prefix -> just unmark it
// Observation:
// If the node is_childless and is not eow -> just delete it.

int main(){
    
    return 0;
}

// https://codeforces.com/problemset/problem/271/D
// https://codeforces.com/contest/455/problem/B