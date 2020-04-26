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

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> out;
        int n = nums.size();
        vector<pair<ll,int>> place;
        
        for(int i=0; i<n; ++i){
            int m = nums[i].size();
            for(int j=0; j<m; ++j){
                ll pos = (ll)1e6*(ll)(i+j) + (n - i);
                place.push_back({pos, nums[i][j]});
            }
        }
        
        sort(place.begin(), place.end());
        for(auto p: place)
            out.push_back(p.second);
       

        return out;
    }
};

int main(){
    Solution sol; vvi nums;
    nums = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    vi out = sol.findDiagonalOrder(nums); print(out);
    nums = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
    out = sol.findDiagonalOrder(nums); print(out);


    nums = {{1,2,3},{4},{5,6,7},{8},{9,10,11}};
    out = sol.findDiagonalOrder(nums); print(out);

    nums = {{1,2,3,4,5,6}};
    out = sol.findDiagonalOrder(nums); print(out);
    return 0;
}