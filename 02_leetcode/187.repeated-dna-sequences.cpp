/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 *
 * https://leetcode.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (37.70%)
 * Likes:    600
 * Dislikes: 230
 * Total Accepted:    146.6K
 * Total Submissions: 388.6K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and
 * T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
 * identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that
 * occur more than once in a DNA molecule.
 * 
 * Example:
 * 
 * 
 * Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 
 * Output: ["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 * 
 */

// @lc code=start
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Brute force
class Solution1 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        map<string, int> rep;
        vector<string> out;
        
        for(int i=0; i<n-10+1; i++){
            string seq = s.substr(i, 10);

            if(rep.count(seq)==0){
                rep[seq] = 1;
            }else if(rep[seq]==1){
                rep[seq] = 2;
                out.push_back(seq);
            }
        }

        return out;
    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<int, int> seen;
        vector<string> out;

        vector<char> m(26);
        // m['A'-'A'] = 0;
        m['C'-'A'] = 1;
        m['G'-'A'] = 2;
        m['T'-'A'] = 3;

        for(int i=0; i<n-10+1; i++){
            int dna = 0;
            for(int j=i; j<i+10; j++){
                dna |= m[s[j]-'A'];
                dna<<=2;
            }
            if(!seen[dna]){
                seen[dna] = 1;
            }else if(seen[dna]==1){
                out.push_back(s.substr(i, 10));
                seen[dna] = 2;
            }
        }

        return out;        
    }
};
// @lc code=end


int main(){
    Solution sol; string s; vs out;
    s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    // s = "AAgAAdAA";
    // s = "AAAAAAAAAAAA";
    out = sol.findRepeatedDnaSequences(s); print(out);
    return 0;
}
