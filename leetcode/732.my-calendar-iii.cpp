/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 *
 * https://leetcode.com/problems/my-calendar-iii/description/
 *
 * algorithms
 * Hard (58.79%)
 * Likes:    317
 * Dislikes: 95
 * Total Accepted:    18.9K
 * Total Submissions: 32.2K
 * Testcase Example:  '["MyCalendarThree","book","book","book","book","book","book"]\n[[],[10,20],[50,60],[10,40],[5,15],[5,10],[25,55]]'
 *
 * Implement a MyCalendarThree class to store your events. A new event can
 * always be added.
 * 
 * Your class will have one method, book(int start, int end). Formally, this
 * represents a booking on the half open interval [start, end), the range of
 * real numbers x such that start <= x < end.
 * 
 * A K-booking happens when K events have some non-empty intersection (ie.,
 * there is some time that is common to all K events.)
 * 
 * For each call to the method MyCalendar.book, return an integer K
 * representing the largest integer such that there exists a K-booking in the
 * calendar.
 * Your class will be called like this: MyCalendarThree cal = new
 * MyCalendarThree(); MyCalendarThree.book(start, end)
 * 
 * Example 1:
 * 
 * 
 * MyCalendarThree();
 * MyCalendarThree.book(10, 20); // returns 1
 * MyCalendarThree.book(50, 60); // returns 1
 * MyCalendarThree.book(10, 40); // returns 2
 * MyCalendarThree.book(5, 15); // returns 3
 * MyCalendarThree.book(5, 10); // returns 3
 * MyCalendarThree.book(25, 55); // returns 3
 * Explanation: 
 * The first two events can be booked and are disjoint, so the maximum
 * K-booking is a 1-booking.
 * The third event [10, 40) intersects the first event, and the maximum
 * K-booking is a 2-booking.
 * The remaining events cause the maximum K-booking to be only a 3-booking.
 * Note that the last event locally causes a 2-booking, but the answer is still
 * 3 because
 * eg. [10, 20), [10, 40), and [5, 15) are still triple booked.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of calls to MyCalendarThree.book per test case will be at most
 * 400.
 * In calls to MyCalendarThree.book(start, end), start and end are integers in
 * the range [0, 10^9].
 * 
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

// We need to find the max events occuring at any time
// This could be solved using prefix array, but since the 
// points are too sparse, map is better option
// Mark start of event by +1, and end by -1
class MyCalendarThree {
    map<int,int> timeLine;
public:
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        timeLine[start]++; // 
        timeLine[end]--;

        int ans = 0, active = 0;
        for(auto p: timeLine){
            active+=p.second;
            ans = max(ans, active);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end
int main(){
    MyCalendarThree m3; int out;
    vector<pii> in = {{24,40},{43,50},{27,43},{5,21},{30,40},{14,29},{3,19},{3,14},{25,39},{6,19}};
    for(auto p: in){
        out = m3.book(p.first, p.second); deb(out);
    }
    
    // [null,1,1,2,2,3,3,3,3,4,4]
    //       1,1,2,2,3,4,4,4,5,5
    
    return 0;
}

