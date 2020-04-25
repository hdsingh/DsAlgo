/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (32.86%)
 * Likes:    1183
 * Dislikes: 111
 * Total Accepted:    66.2K
 * Total Submissions: 201.1K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Frequently Used (LFU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reaches its capacity, it should invalidate the least
 * frequently used item before inserting a new item. For the purpose of this
 * problem, when there is a tie (i.e., two or more keys that have the same
 * frequency), the least recently used key would be evicted.
 * 
 * Note that the number of times an item is used is the number of calls to the
 * get and put functions for that item since it was inserted. This number is
 * set to zero when the item is removed.
 * 
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * 
 * 
 * Example:
 * 
 * 
 * LFUCache cache = new LFUCache( 2 );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.get(3);       // returns 3.
 * cache.put(4, 4);    // evicts key 1.
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
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

// @lc code=start
// order all keys having same freq by LRU
// since we are pushing the elements as they appear at the end of a list
// the lru will be present at the front
class LFUCache {
    int cap, size, lfu;
    unordered_map<int, list<int>> keys; // freq, {keys}
    unordered_map<int, pair<int,int>> values; // key : {val, freq}
    unordered_map<int, list<int>::iterator> iters; // key to iterator in list by freq

    void update(int key){
        int freq = values[key].second;
        auto iter = iters[key];
        values[key].second++;
        keys[freq].erase(iter);
        keys[freq+1].push_back(key);

        iters[key] = --keys[freq+1].end();
        if(keys[lfu].empty()){
            lfu++;
        }
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0, lfu = 0;
    }
    
    int get(int key) {
        if(!values.count(key)) return -1;

        update(key);
        return values[key].first;
    }
    
    void put(int key, int value) {
        if(!cap) return;
        if(values.count(key)){
            values[key].first = value;
            update(key);
        }else{
            if(size==cap){
                // evict the lru, present in lfu list
                int evict = keys[lfu].front();
                keys[lfu].pop_front();
                values.erase(evict);
                iters.erase(evict);
            }else{
                ++size;
            }
            values[key] = {value, 1};
            keys[1].push_back(key);
            iters[key] = --keys[1].end();
            lfu = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(){
    LFUCache cache(2);
    int out;
    cache.put(1, 1);
    cache.put(2, 2);
    out = cache.get(1); deb(out);    // returns 1
    cache.put(3, 3);                 // evicts key 2
    out = cache.get(2); deb(out);    // returns -1 (not found)
    out = cache.get(3); deb(out);    // returns 3
    cache.put(4, 4);    // evicts key 1
    out = cache.get(1); deb(out);    // returns -1 (not found)
    out = cache.get(3); deb(out);    // returns 3
    out = cache.get(4); deb(out);    // returns 4

    return 0;
}
