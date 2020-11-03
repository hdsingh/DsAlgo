#include <bits/stdc++.h>
using namespace std;

struct Bucket{
    int val;
    unordered_set<string> keys;
};

class AllOne {
    list<Bucket> buckets;
    unordered_map<string,list<Bucket>::iterator> locs;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(!locs.count(key))
            locs[key] = buckets.insert(buckets.begin(),{0,{key}});
    
        auto pos = locs[key];
        int cnt = pos->val;
        // assure the next pos with cnt+1 exists
        if(next(pos)==buckets.end() || next(pos)->val>cnt+1){
            buckets.insert(next(pos), {cnt+1,{}});
        }
        
        next(pos)->keys.insert(key);
        locs[key] = next(pos);
        
        pos->keys.erase(key);
        if(pos->keys.empty()){
            buckets.erase(pos);
        }        
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!locs.count(key)) return;
        auto pos = locs[key];
        int cnt = pos->val;
        
        // if cnt-1 is valid, ensure prev pos exists
        if(pos==buckets.begin() || prev(pos)->val<cnt-1)
            if(cnt-1>0)
                buckets.insert(pos, {cnt-1,{}});
        
        if(cnt-1>0){
            prev(pos)->keys.insert(key);
            locs[key] = prev(pos);
        }
    
        pos->keys.erase(key);
        if(pos->keys.empty())
            buckets.erase(pos);
        
        // it cnt of a key becomes 0, it is removed so erase its iter.
        if(cnt-1==0){
            locs.erase(key);
        }
        
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(buckets.empty()) return "";
        return *(buckets.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(buckets.empty()) return "";
        return *(buckets.begin()->keys.begin());
    }
};

class AllOne1 {
    set<pair<int,string>> s;
    unordered_map<string,int> cnt;
public:
    /** Initialize your data structure here. */
    AllOne1() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
       if(cnt.count(key)){
           auto pos = s.find({cnt[key],key});
           s.erase(pos);
           s.insert({++cnt[key], key});
       }else{
           cnt[key] = 1;
           s.insert({1,key});
       }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!cnt.count(key)) return;
        auto pos = s.find({cnt[key], key});
        s.erase(pos);
        --cnt[key];
        if(cnt[key]==0){
            cnt.erase(key);
        }else{
            s.insert({cnt[key], key});
        }
        
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(s.empty()) return "";
        return s.rbegin()->second;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(s.empty()) return "";
        return s.begin()->second;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}