#include <bits/stdc++.h>
using namespace std;
#define pb push_back

struct trie{
    trie* bit[2] = {};
    int cnt = 0;
};

trie* root;

void insert(int x){
    auto cur = root;
    for(int i=31; i>=0; --i){
        int b = (x>>i)&1;
        if(!cur->bit[b])
            cur->bit[b] = new trie();
        cur = cur->bit[b];
        cur->cnt++;
    }
}

void remove(int x){
    auto cur = root;
    for(int i=31; i>=0; --i){
        int b = (x>>i)&1;
        cur = cur->bit[b];
        cur->cnt--;
    }
}

int maxxor(int x){
    trie* cur = root;
    int ans = 0;
    for(int i=31; i>=0; --i){
        int b = (x>>i)&1;
        if(cur->bit[!b] && cur->bit[!b]->cnt > 0){
            ans|=(1LL<<i);
            cur = cur->bit[!b];
        }else 
            cur = cur->bit[b];
    }
    return ans;
}

int main(){
    root = new trie();
    insert(0); // imp step in initialisation

}

// https://codeforces.com/problemset/problem/706/D