/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (42.07%)
 * Likes:    2249
 * Dislikes: 43
 * Total Accepted:    182.5K
 * Total Submissions: 430.4K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * For example,
 * 
 * [2,3,4], the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * If all integer numbers from the stream are between 0 and 100, how would you
 * optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how
 * would you optimize it?
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

// Amazing explanation: https://leetcode.com/problems/find-median-from-data-stream/solution/
// Balancing max and min heaps
// we need both heaps to have eq size (in case of even)
// however in case of odd size of nums, lo will hold the median
class MedianFinder0 {
    priority_queue<int> lo; // max for 1st half
    priority_queue<int,vector<int>, greater<int>> hi; // for 2nd sorted half
public:
    /** initialize your data structure here. */
    MedianFinder0() {

    }
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();

        if(hi.size()>lo.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size()==hi.size() ? (double)(lo.top() + hi.top())/2 : lo.top();
    }
};

// multiset and 2 pointers
// in case of odd n, both lo and hi will point to same pos
// Imp point to note: in multiset, in case of an element to be inserted 
// is already present in the set, the insertion will happen after the equal elements, 
// i.e just before a greater element (or end in case no greater is present)
// Hence in the last else , lo = --hi; , to check the insertion in bw
// ex s = {5,  7}, lo =  (5) 0th pos, hi = (7)1st pos
// after inserting 5, s = {5, 5, 7} , lo = 0th, hi = 2nd
// So now after decrementing hi, we need to make lo equal to it

class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator lo, hi;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        data.clear();
    }
    
    void addNum(int num) {
        int n = data.size();
        data.insert(num);
        if(!n){
            lo = hi = data.begin();
        }
        // odd size before, even now
        // so separate lo, hi
        else if(n&1){
            if(num<*lo) 
                --lo;
            else  // num>=*lo
                ++hi;
        }else{
            if(*lo<num && num<*hi)
                ++lo, --hi;
            else if(num>=*hi)
                ++lo;
            else
                lo = --hi;
        }
    }
    
    double findMedian() {
        return (double)(*lo + *hi)/2;
    }
};

// @lc code=end

int main(){
    
    return 0;
}
