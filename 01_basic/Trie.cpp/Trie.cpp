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

// better simple implementation
struct TrieNode{
    bool eow = false;
    TrieNode* children[26] = {};
};

// struct TrieNode{
//     bool eow; // end of word
//     TrieNode* children[26];
//     TrieNode(){
//         eow = false;
//         memset(children, NULL, sizeof(children));
//     }
// };

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
        }
        cur->eow = true;
    }

    bool search(string word){
        TrieNode* cur = root;
        for(auto x: word){
            if(!cur->children[x-'a']) return false;
            cur = cur->children[x-'a'];
        }
        return cur->eow;
    }

    void remove(string word){
        
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

int main(){
    
    return 0;
}