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

const int inf = 1e9;
class Solution {
public:
    int minDifficulty(vector<int>& jd, int D) {
        int n = jd.size();
        if(D>n) return -1;

        vvi dp(D+1, vi(n+1));
        for(int i=1; i<=n; ++i){
            dp[1][i] = max(dp[1][i-1], jd[i-1]);
        }

        for(int d=2; d<=D; ++d){
            for(int j=d; j<=n; ++j){
                dp[d][j] = inf;
                int curmax = 0;
                for(int beg=j; beg>=d; --beg){
                    curmax = max(curmax, jd[beg-1]);
                    min_self(dp[d][j], dp[d-1][beg-1] + curmax);
                }
            }
        }

        return dp[D][n];
    }
};


int main(){
    Solution sol; vi jobDifficulty; int d, out; 
    jobDifficulty = {6,5,4,3,2,1}, d = 2;
    out =  sol.minDifficulty(jobDifficulty, d); deb(out);

    jobDifficulty = {9,9,9}, d = 4;
    out =  sol.minDifficulty(jobDifficulty, d); deb(out);

    jobDifficulty = {1,1,1}, d = 3;
    out =  sol.minDifficulty(jobDifficulty, d); deb(out);

    jobDifficulty = {7,1,7,1,7,1}, d = 3;
    out =  sol.minDifficulty(jobDifficulty, d); deb(out);

    jobDifficulty = {11,111,22,222,33,333,44,444}, d = 6;
    out =  sol.minDifficulty(jobDifficulty, d); deb(out);
    return 0;
}

