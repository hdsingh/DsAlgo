#include <bits/stdc++.h>
using namespace std;
#define pb push_back

struct Trie{
    Trie* bit[2] = {nullptr};
    // int cnt = 0;
};

class Solution {
    Trie* root;
public:
    int findMaximumXOR(vector<int>& nums) {
        if(nums.empty()) return 0;
        root = new Trie();
        int mx = INT_MIN;

        for(auto num: nums)
            insert(num);
        
        for(auto num: nums)
            mx = max(mx, maxxor(num));
        
        return mx;
    }

    void insert(int x){
        Trie* cur = root;
        for(int i=31; i>=0; --i){
            int b = (x>>i)&1;
            if(!cur->bit[b])
                cur->bit[b] = new Trie();
            cur = cur->bit[b];
        }
        // cur->cnt++;
    }

    int maxxor(int x){
        Trie* cur = root;
        int ans = 0;
        for(int i=31; i>=0; --i){
            int b = (x>>i)&1;
            // !b since we need b to be diff for xor to be max
            if(cur->bit[!b]){
                ans|=(1LL<<i);
                cur = cur->bit[!b];
            }else
                cur = cur->bit[b];
        }
        return ans;
    }
};