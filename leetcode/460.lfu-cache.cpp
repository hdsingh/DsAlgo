#include <bits/stdc++.h>
using namespace std;

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)

// push at front, so LRU at back
// Idea smilar to LRU, just enclosing cache for each freq separately 
// push at front, so LRU at back
// Also lfu will keep on increasing until it is set to 1
// increment lfu only is the cache emptied is lfu
class LFUCache {
    int cap, lfu;
    unordered_map<int, list<pair<int,int>>> freq_cache; // acc to freq {freq: {key, val}}; (lru)
    unordered_map<int, pair<int, list<pair<int,int>>::iterator> > locs; // {key, {freq, loc}}
public:
    LFUCache(int _cap) {
        cap = _cap;
        lfu = 0;
    }
    
    int get(int key) {
        if(!locs.count(key)){
            return -1;
        }
        auto [freq, iter] = locs[key];
        int val = iter->second;
        update(key, val); // update with same val
        return val;
    }
    
    void put(int key, int val) {
        if(!cap) return;
        if(locs.count(key)){
           update(key, val); 
            return;
        }
    
        if((int)locs.size()==cap){ // erase lfu + lru
            auto [prev_key, prev_val] = freq_cache[lfu].back();
            freq_cache[lfu].pop_back();
            locs.erase(prev_key);
        }

        freq_cache[1].push_front({key,val});
        locs[key] = {1, freq_cache[1].begin()};
        lfu = 1;

    }

private:
    // already existing key
    void update(int key, int val){
        auto [freq, iter] = locs[key];
        freq_cache[freq+1].push_front({key, val});
        locs[key] = {freq+1, freq_cache[freq+1].begin()};
        
        // delete it from prev
        freq_cache[freq].erase(iter);
        // Update lfu only is the cache delete is lfu
        if(freq_cache[freq].empty() && freq==lfu){
            ++lfu;
        }
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int out;
    LFUCache lFUCache(2);
    lFUCache.put(1, 1);
    lFUCache.put(2, 2);
    out = lFUCache.get(1); deb(out);      // return 1
    lFUCache.put(3, 3);   // evicts key 2
    out = lFUCache.get(2); deb(out);      // return -1 (not found)
    out = lFUCache.get(3); deb(out);      // return 3
    lFUCache.put(4, 4);   // evicts key 1.
    out = lFUCache.get(1); deb(out);      // return -1 (not found)
    out = lFUCache.get(3); deb(out);      // return 3
    out = lFUCache.get(4); deb(out);      // return 4 
    return 0;
}