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
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();

        auto cmp = [&](pair<int,int> p1, pair<int,int> p2){
            if(p1.first==p2.first) return p1.second<p2.second;
            return p1.first>p2.first;
        };
        
        set<pair<int,int>, decltype(cmp)> s(cmp);
        int ans = INT_MIN;
        for(int i=0, j=1; i<n; ++i){
            while(j<n && points[j][0]-points[i][0]<=k){
                s.insert({points[j][0] + points[j][1], points[j][0]});
                ++j;
            }
            s.erase({points[i][0] + points[i][1], points[i][0]});
            while(s.size() && s.begin()->second-points[i][0]>k){
                s.erase(s.begin());
            }
            if(s.size()){
                auto top = *s.begin();
                int cur = points[i][1] - points[i][0] + top.first;
                ans = max(ans,cur);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol; vvi points; int k, out;
    points = {{1,3},{2,0},{5,10},{6,-10}}, k = 1;
    out = sol.findMaxValueOfEquation(points,k); deb(out);
    points = {{0,0},{3,0},{9,2}}, k = 3; 
    out = sol.findMaxValueOfEquation(points,k); deb(out);
    points = {{-19,-12},{-13,-18},{-12,18},
                {-11,-8},{-8,2},{-7,12},{-5,16},{-3,9},
                {1,-7},{5,-4},{6,-20},{10,4},{16,4},
                {19,-9},{20,19}}, k = 6;

    out = sol.findMaxValueOfEquation(points,k); deb(out);
    return 0;
}