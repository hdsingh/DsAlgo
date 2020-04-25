/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (57.22%)
 * Likes:    843
 * Dislikes: 75
 * Total Accepted:    109.5K
 * Total Submissions: 190.9K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 * 
 * Example 1:
 * 
 * Input:
 * "tree"
 * 
 * Output:
 * "eert"
 * 
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * "cccaaa"
 * 
 * Output:
 * "cccaaa"
 * 
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * "Aabb"
 * 
 * Output:
 * "bbAa"
 * 
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
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

class Solution0 {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for(auto &c: s)
            cnt[c]++;
        vector<pair<char,int>> a;
        for(auto &p: cnt)
            a.push_back(p);
        
        sort(all(a), [](pair<char,int> &p1, pair<char, int> &p2){
            return p1.second>p2.second;
        });

        s.clear();
        for(auto &p: a){
            int times = p.second;
            while(times--)
                s.push_back(p.first);
        }
        return s;
    }
};

class Solution1 {
public:
    string frequencySort(string s) {
        unordered_map<char,int> cnt;
        for(auto &c: s)
            cnt[c]++;

        // Max Heap
        auto compare = [](pair<char,int> &p1, pair<char,int> &p2){
            return p1.second<p2.second;
        };
        priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(compare)> pq(compare);
        for(auto &p: cnt)
            pq.push(p);

        s.clear();
        while((int)pq.size()){
            char c = pq.top().first; int t = pq.top().second; pq.pop();
            while(t--){
                s.push_back(c);
            }
        }
        return s;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> cnt;
        for(auto &c: s)
            cnt[c]++;

        // Max Heap
        priority_queue<pair<int,char>> pq;
        for(auto &p: cnt)
            pq.push({p.second, p.first});

        s.clear();
        while((int)pq.size()){
            int t = pq.top().first; char c = pq.top().second; pq.pop();
            while(t--){
                s.push_back(c);
            }
        }
        return s;
    }
};
int main(){
    Solution sol; vs ss; 
    ss = {
        "tree",
        "cccaaa",
        "Aabb",
    };
    for(auto s: ss){
        s = sol.frequencySort(s); deb(s);
    }
    return 0;
}

