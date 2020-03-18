/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 *
 * https://leetcode.com/problems/number-of-music-playlists/description/
 *
 * algorithms
 * Hard (45.47%)
 * Likes:    300
 * Dislikes: 35
 * Total Accepted:    8.3K
 * Total Submissions: 18.2K
 * Testcase Example:  '3\n3\n1'
 *
 * Your music player contains N different songs and she wants to listen to L
 * (not necessarily different) songs during your trip.  You create a playlist
 * so that:
 * 
 * 
 * Every song is played at least once
 * A song can only be played again only if K other songs have been played
 * 
 * 
 * Return the number of possible playlists.  As the answer can be very large,
 * return it modulo 10^9 + 7.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: N = 3, L = 3, K = 1
 * Output: 6
 * Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1,
 * 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: N = 2, L = 3, K = 0
 * Output: 6
 * Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1,
 * 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: N = 2, L = 3, K = 1
 * Output: 2
 * Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= K < N <= L <= 100
 * 
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

// At each pos, either we can listen to old song again, or a new song
// 1. in case of old song, # of uniq songs will not inc,
// dp[pos][usongs] = dp[pos-1][usongs] * # of played old songs
// # of played old songs = usongs, however due to K, we will not able to listen most recent K
// hence usongs-K. (it may become -ve in case of large K, so max with 0)
// 2. in case of new song,
// we can listen to any on the remaing N-(usongs);
// So dp[pos][usongs] = dp[pos-1][usongs-1] * (N- (usongs-1))
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        vvl dp(L+1, vl(N+1));
        // Number of ways to listen to n unique songs till pos l

        dp[0][0] = 1;
        for(int pos=1; pos<=L; ++pos){
            for(int usongs=1; usongs<=N; ++usongs){
                ll using_old = dp[pos-1][usongs] * max(0, usongs-K) %mod;
                ll using_new = dp[pos-1][usongs-1] * max(0, (N - (usongs-1))) %mod;
                dp[pos][usongs] = (using_old + using_new + mod)%mod;
            }
        }

        // print_vv(dp);

        return dp[L][N];
    }
};
// @lc code=end

int main(){
    Solution sol; int N,L,K, out;
    N = 3, L = 3, K = 1;
    out = sol.numMusicPlaylists(N,L,K); deb(out);

    N = 2, L = 3, K = 0;
    out = sol.numMusicPlaylists(N,L,K); deb(out);

    N = 2, L = 3, K = 1;
    N = 100, L = 100, K = 50;
    out = sol.numMusicPlaylists(N,L,K); deb(out);

    return 0;
}
