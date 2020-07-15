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

// Permutation of combination
// Choose the balls of each color for a set
// For each combination find the probability.
class Solution {
    vi a;
    int k, half;
    double tot, good;
    vvi C;
    const int N = 8;
public:
    double getProbability(vector<int>& balls) {
        C.assign(N, vi(N,0));
        C[0][0] = 1;
        for(int i=1; i<N; ++i){
            C[i][0] = C[i][i] = 1;
            for(int j=1; j<N; ++j)
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    
        a = balls;
        k = a.size();
        half = accumulate(a.begin(), a.end(),0)/2;
        tot = 0, good = 0;
        // vi used(k);
        dfs(0,0,0,0,1);
        return good/tot;
    }
    
    // sum = tot balls in first set,
    // A = distinct balls in part A;
    // B = distinct balls in part B
    void dfs(int pos, int sum, int A, int B, double p){
        if(pos==k){
            // print(used);
            // deb(A,B);
            if(sum==half){
                good+=(A==B)*p;
                tot+=p;
            }
            return;
        }

        for(int cnt=0; cnt<=a[pos] && cnt+sum<=half; ++cnt){
            int nxA = A + (cnt>0);
            int nxB = B + (a[pos] - cnt >0);
            dfs(pos+1,sum+cnt,nxA, nxB, p*C[a[pos]][cnt]);
        }
    }    
};

int main(){
    Solution sol; vi balls; double out;
    balls = {1,1};
    out = sol.getProbability(balls); printf("%.10f\n", out);

    balls = {2,1,1};
    out = sol.getProbability(balls); printf("%.10f\n", out);

    balls = {1,2,1,2};
    out = sol.getProbability(balls); printf("%.10f\n", out);

    balls = {3,2,1};
    out = sol.getProbability(balls); printf("%.10f\n", out);

    balls = {6,6,6,6,6,6};
    out = sol.getProbability(balls); printf("%.10f\n", out);

    return 0;
}