/*
 * @lc app=leetcode id=900 lang=cpp
 *
 * [900] RLE Iterator
 *
 * https://leetcode.com/problems/rle-iterator/description/
 *
 * algorithms
 * Medium (52.52%)
 * Likes:    176
 * Dislikes: 69
 * Total Accepted:    19.2K
 * Total Submissions: 36.7K
 * Testcase Example:  '["RLEIterator","next","next","next","next"]\n[[[3,8,0,9,2,5]],[2],[1],[1],[2]]'
 *
 * Write an iterator that iterates through a run-length encoded sequence.
 * 
 * The iterator is initialized by RLEIterator(int[] A), where A is a run-length
 * encoding of some sequence.  More specifically, for all even i, A[i] tells us
 * the number of times that the non-negative integer value A[i+1] is repeated
 * in the sequence.
 * 
 * The iterator supports one function: next(int n), which exhausts the next n
 * elements (n >= 1) and returns the last element exhausted in this way.  If
 * there is no element left to exhaust, next returns -1 instead.
 * 
 * For example, we start with A = [3,8,0,9,2,5], which is a run-length encoding
 * of the sequence [8,8,8,5,5].  This is because the sequence can be read as
 * "three eights, zero nines, two fives".
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["RLEIterator","next","next","next","next"],
 * [[[3,8,0,9,2,5]],[2],[1],[1],[2]]
 * Output: [null,8,8,5,-1]
 * Explanation: 
 * RLEIterator is initialized with RLEIterator([3,8,0,9,2,5]).
 * This maps to the sequence [8,8,8,5,5].
 * RLEIterator.next is then called 4 times:
 * 
 * .next(2) exhausts 2 terms of the sequence, returning 8.  The remaining
 * sequence is now [8, 5, 5].
 * 
 * .next(1) exhausts 1 term of the sequence, returning 8.  The remaining
 * sequence is now [5, 5].
 * 
 * .next(1) exhausts 1 term of the sequence, returning 5.  The remaining
 * sequence is now [5].
 * 
 * .next(2) exhausts 2 terms, returning -1.  This is because the first term
 * exhausted was 5,
 * but the second term did not exist.  Since the last term exhausted does not
 * exist, we return -1.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 1000
 * A.length is an even integer.
 * 0 <= A[i] <= 10^9
 * There are at most 1000 calls to RLEIterator.next(int n) per test case.
 * Each call to RLEIterator.next(int n) will have 1 <= n <= 10^9.
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

class RLEIterator {
    vector<int> a;
    int n;
    int i=0; int pos = 0;
public:
    RLEIterator(vector<int>& a) {
       this->a = a; 
       n = a.size();
    }
    
    int next(int x) {
        while(i<n){
            if(x + pos <= a[i]){
                pos+=x;
                return a[i+1];
            }else{
                x-=(a[i] - pos);
                pos = 0;
                i+=2;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
// @lc code=end


int main(){
    vi a = {3,8,0,9,1,5,1,6};
    RLEIterator it(a);
    int out;
    out = it.next(2); deb(out);
    out = it.next(1); deb(out);
    out = it.next(1); deb(out);
    out = it.next(2); deb(out);

    return 0;
}