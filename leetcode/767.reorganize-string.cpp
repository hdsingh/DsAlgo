/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 *
 * https://leetcode.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (46.49%)
 * Likes:    1018
 * Dislikes: 54
 * Total Accepted:    54.8K
 * Total Submissions: 117.9K
 * Testcase Example:  '"aab"'
 *
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same.
 * 
 * If possible, output any possible result.  If not possible, return the empty
 * string.
 * 
 * Example 1:
 * 
 * 
 * Input: S = "aab"
 * Output: "aba"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "aaab"
 * Output: ""
 * 
 * 
 * Note:
 * 
 * 
 * S will consist of lowercase letters and have length in range [1, 500].
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
// ref: https://leetcode.com/problems/reorganize-string/discuss/113425/C%2B%2B-priority_queue
// 1. Place the maxFreq char at even pos,
// 2. then iterate and place the remaining char tarting from 
// the pos+2 after max char;
// 3. if indx reaches end, bring it to 1 and start placing again
// 4. if the string is valid, idx will be reset to 1 only once, due to len of
// remaining chars
class Solution0 {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> cnt(26);

        int maxFreq=0; int maxpos;
        for(auto &c: s){
            cnt[c-'a']++;
            if(cnt[c-'a']>maxFreq){
                maxFreq = cnt[c-'a'];
                maxpos = c-'a';
            }
        }

        if(maxFreq > (n+1)/2) return "";

        // Place maxfreq char
        int idx = 0;
        while(cnt[maxpos]){
            s[idx] = maxpos+'a';
            --cnt[maxpos];
            idx+=2;
        }

        for(int i=0; i<26; ++i){
            while(cnt[i]){
                if(idx>=n) idx = 1;
                s[idx] = 'a'+i;
                --cnt[i];
                idx+=2;
            }
        }
        return s;
    }
};

// Priority Queue
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> cnt;
        for(auto &c: s)
            cnt[c]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto &p: cnt)
            pq.push({p.second, p.first});
        
        int maxFreq = pq.top().first;
        if(maxFreq>(n+1)/2) return "";

        s.clear();
        pair<int,char> top1, top2;
        while(pq.size()>=2){
            top1 = pq.top(); pq.pop();
            top2 = pq.top(); pq.pop();
            
            s.push_back(top1.second);
            s.push_back(top2.second);

            if(--top1.first > 0) pq.push(top1);
            if(--top2.first > 0) pq.push(top2);
        }
        if(pq.size()) s.push_back(pq.top().second);

        return s;
    }
};

// @lc code=end

int main(){
    Solution sol; 
    vs ss = {
        "aabbccc",
        "aaab",
        "vvvlo",
    };
    for(auto s: ss){
        s = sol.reorganizeString(s); deb(s);
    }
    return 0;
}
