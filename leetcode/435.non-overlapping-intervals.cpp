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

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ivals) {
        sort(ivals.begin(), ivals.end(), [&](vi &p1, vi &p2){
            if(p1[1]==p2[1])
                return p1[0]>p2[0]; // interval with smaller length
            return p1[1]<p2[1]; // earliest fininshing time
        });

        int ans = 0;
        vi prev = {-1,-1};
        for(auto ival: ivals){
            if(ival[0]>=prev[1] || prev[0]>=ival[1]){
                prev = ival;
            }else ++ans;
        }
        return ans;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ivals) {
        sort(all(ivals), [&](vi &p1, vi &p2){
            // if(p1[1]==p2[1]) // does not matter
            //     return p1[0]<p2[0];
            return p1[1]<p2[1]; // by earliest finishing time.
        });

        int res = 0;
        int prev =  INT_MIN;;
        for(auto x: ivals){
            if(x[0]<prev) // overlaps
                res++;
            else 
                prev = x[1];
        }
        return res;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}