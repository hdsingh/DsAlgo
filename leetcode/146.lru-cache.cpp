/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (30.64%)
 * Likes:    5063
 * Dislikes: 227
 * Total Accepted:    476.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
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

// keep most recently used in the beginning of double linked list
// remove LRU from end
class LRUCache0 {
    int cap;
    unordered_map<int, list<pii>::iterator> m_map; // key, iterator
    list<pii> m_list;
public:
    LRUCache0(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m_map.count(key)==0) return -1;
        auto it = m_map[key];

        // transfer to m_list.begin(), elements from m_list, 
        m_list.splice(m_list.begin(),m_list,it);
        return it->second;
        
    }
    
    void put(int key, int val) {
        // already present
        if(m_map.count(key)){
            auto it = m_map[key];
            it->second = val;
            m_list.splice(m_list.begin(), m_list, it);
            return;
        }

        // reached capacity, then erase the LRU
        if(m_map.size()==cap){
            int key_to_del = m_list.back().first;
            m_list.pop_back();
            m_map.erase(key_to_del);  
        }
        m_list.push_front({key,val}); // insert at beg
        m_map[key] = m_list.begin();  // save its pos      
    }
};


class LRUCache {
    int cap;
    list<pii> cache;
    unordered_map<int,list<pii>::iterator> m;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    void update(int key, int val){
        auto it = m[key];
        cache.erase(it);
        cache.push_front({key, val});
        m[key] = cache.begin();        
    }
    
    int get(int key) {
        if(m.count(key)==0){
            return -1;
        }
        int val = m[key]->second;
        update(key,val); // with same val to bring it to front
        return val;
    }
    
    void put(int key, int val) {
        if(m.count(key)){
            update(key,val);
            return;
        }

        if(m.size()==cap){
            auto bk = cache.back().first;
            cache.pop_back();
            m.erase(bk);
        }
        cache.push_front({key, val});
        m[key] = cache.begin();
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(){
    LRUCache cache(2);
    int out;
    cache.put(1, 1);
    cache.put(2, 2);
    out = cache.get(1); deb(out);    // returns 1
    cache.put(3, 3);                 // evicts key 2
    out = cache.get(2); deb(out);    // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    out = cache.get(1); deb(out);    // returns -1 (not found)
    out = cache.get(3); deb(out);    // returns 3
    out = cache.get(4); deb(out);    // returns 4

    return 0;
}
