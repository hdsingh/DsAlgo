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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

class Solution {
    const int fw = 0, bw = 1;
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int X) {
        unordered_set<int> invalid;
        queue<int> q; // loc, back_jump_done
        int last = X + max(a,b);
        unordered_set<int> vis;
        q.push(0);
        vis.insert(fw);
        vis.insert(bw);
        
        
        for(auto f: forbidden){
            if(f<=last){
                vis.insert((f<<1)+fw);
                vis.insert((f<<1)+bw);
            }
        }
        
        int jumps = 0;
        while(!q.empty()){
            ++jumps;
            queue<int> nq;
            while(!q.empty()){
                int loc = q.front(); q.pop();
                int cur = (loc>>1), prev_done = (loc&1);

                int now = 2*(cur+a);
                if(cur+a<=last && !vis.count(now)){
                    vis.insert(now);
                    if(cur+a==X) return jumps;
                    nq.push(now);
                }
                
                now = 2*(cur-b) + 1;
                if(!prev_done && cur-b>=0 && !vis.count(now)){
                    vis.insert(now);
                    if(cur-b==X) return jumps;
                    nq.push(now);
                }
            }
            q = nq;
        }
        return -1;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;
    vi fb; int a, b, x; 
    fb = {};  a =  200, b = 4, x = 3; int out;
    out=  sol.minimumJumps(fb,a,b,x); deb(out);
    // vi d(4e6);
    return 0;
}