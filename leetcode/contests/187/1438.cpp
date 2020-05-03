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
    int longestSubarray(vector<int>& a, int lim) {
        map<int, int> m;
        deque<int> d;
        int mn = a[0], mx =a[0];
        // m[a[0]]++;
        // d.push_back(a[0]);
        int n = a.size();

        bool empty = false;
        int ans = 0, cnt = 0;
        for(int i=0; i<n; ){
            if(cnt==0 || (abs(a[i]-mn)<=lim && abs(a[i]-mx)<=lim)){
                m[a[i]]++;
                d.push_back(a[i]);
                ++cnt;
                // deb2(a[i], cnt);
                mn = m.begin()->first;
                auto ed = m.end(); --ed;
                mx = ed->first;
                ans = max(ans, cnt);
                ++i;
            }else{
                while(cnt>0){
                    if(abs(a[i]-mn)>lim || abs(a[i]-mx)>lim){
                        int fr = d.front(); d.pop_front();
                        --cnt;
                        m[fr]--;
                        if(m[fr]==0)
                            m.erase(fr);
                        if(cnt==0) break;
                        mn = m.begin()->first;
                        auto ed = m.end(); --ed;
                        mx = ed->first;
                    }else break;
                }
            }
        }
        // cout<<endl;
        return ans;
    }
};

int main(){
    Solution sol; vi a; int lim; int out;
    a = {8,2,4,7}, lim = 4;
    out = sol.longestSubarray(a, lim); deb(out);

    a = {10,1,2,4,7,2}, lim = 5;
    out = sol.longestSubarray(a, lim); deb(out);

    a = {4,2,2,2,4,4,2,2}, lim = 0;
    out = sol.longestSubarray(a, lim); deb(out);
    a = {4,8,5,1,7,9}, lim= 6;
    out = sol.longestSubarray(a, lim); deb(out);

    return 0;
}