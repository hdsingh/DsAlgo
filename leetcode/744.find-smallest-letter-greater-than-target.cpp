/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 *
 * https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
 *
 * algorithms
 * Easy (44.45%)
 * Likes:    262
 * Dislikes: 386
 * Total Accepted:    49.1K
 * Total Submissions: 110.4K
 * Testcase Example:  '["c","f","j"]\n"a"'
 *
 * 
 * Given a list of sorted characters letters containing only lowercase letters,
 * and given a target letter target, find the smallest element in the list that
 * is larger than the given target.
 * 
 * Letters also wrap around.  For example, if the target is target = 'z' and
 * letters = ['a', 'b'], the answer is 'a'.
 * 
 * 
 * Examples:
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "a"
 * Output: "c"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "c"
 * Output: "f"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "d"
 * Output: "f"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "g"
 * Output: "j"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "j"
 * Output: "c"
 * 
 * Input:
 * letters = ["c", "f", "j"]
 * target = "k"
 * Output: "c"
 * 
 * 
 * 
 * Note:
 * 
 * letters has a length in range [2, 10000].
 * letters consists of lowercase letters, and contains at least 2 unique
 * letters.
 * target is a lowercase letter.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

class Solution {
public:
    char nextGreatestLetter(vector<char>& ls, char x) {
        int n = ls.size();
        int ans = -1;
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(ls[mid]>x){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if(ans==-1) ans = 0;
        return ls[ans];
    }
};

class Solution {
public:
    char nextGreatestLetter(vector<char>& ls, char x) {
        int n = ls.size();
        int l=0, r = n-1;

        if(x<ls.front() || x>=ls.back()) return ls.front();

        while(l<r){
            int mid = l + (r-l)/2;
            if(ls[mid]<=x){
                // It has to be on the other side
                l = mid + 1;
            }else{
                r = mid;
                // I cant ignore this element by doing r = mid-1
            }
            // deb(l,r,mid);
        }

        return ls[l];
    }
};


int main(){
    Solution sol; vector<char> letters; char target, out;
    letters = {'c', 'f', 'j'};
    target = 'a';
    out = sol.nextGreatestLetter(letters, target); deb(out);

    letters = {'c', 'f', 'j'};
    target = 'c';
    out = sol.nextGreatestLetter(letters, target); deb(out);

    letters = {'c', 'f', 'j'};
    target = 'd';
    out = sol.nextGreatestLetter(letters, target); deb(out);


    letters = {'c', 'f', 'j'};
    target = 'g';
    out = sol.nextGreatestLetter(letters, target); deb(out);

    letters = {'c', 'f', 'j'};
    target = 'j';
    out = sol.nextGreatestLetter(letters, target); deb(out);

    letters = {'c', 'f', 'j'};
    target = 'k';
    out = sol.nextGreatestLetter(letters, target); deb(out);
    

    return 0;
}
