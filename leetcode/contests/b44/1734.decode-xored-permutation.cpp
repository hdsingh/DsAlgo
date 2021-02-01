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
typedef pair<ll, ll> pll;
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

// 0 1 2 3 4
// a b c d e
// ab bc cd de -> enc
// since numbers are from a to e , we know comp = abcde
// xorsum of all nums in enc, X = a^e
// now if we xor comp and X, we will eliminate ae, ie. abcde ^ (a^e) = (bcd)
// we know Xsum[1..3] = b^d
// so comp ^ X = (bcd)^(bd) = c.
// ie. keep on eliminating nums till we reach center and only one is remaining.
// after finding center expand it
class Solution0 {
public:
    vector<int> decode(vector<int>& enc) {
        int n = enc.size();
        int comp = 0;
        for(int i=1; i<=n+1; ++i) comp^=i;
        
        vi pre(n);
        pre[0] = enc[0];
        for(int i=1; i<n; ++i){
            pre[i] = pre[i-1]^enc[i];
        }
        
        for(int lt=0, rt=n-1; lt<rt; ++lt, --rt){
            int cur = pre[rt]^(lt-1>=0 ? pre[lt-1] : 0);
            comp^=cur;
        }
        
        vi out(n+1);
        out[n/2] = comp;
        for(int i=n/2-1; i>=0; --i){
            out[i] = out[i+1]^enc[i];
        }
        
        for(int i=n/2+1; i<=n; ++i){
            out[i] = out[i-1]^enc[i-1];
        }
        return out;
    }
};


// a   b   c   d   e -> orig
// ab bc cd de   -> enc
// ab ac ad ae   -> pre
// Xorsum of pre -> bcde
// tot Xorsum ->   abcde
// Xoring both ->  a
class Solution {
public:
    vector<int> decode(vector<int>& enc) {
        int n = enc.size();
        int comp = 0;
        for(int i=1; i<=n+1; ++i){
            comp^=i;
        }

        int pre = enc[0];
        int tot = pre;
        for(int i=1; i<n; ++i){
            pre = pre^enc[i];
            tot^=pre;
        }
        int a = tot^comp;
        deb(a);
        vi out(n+1); 
        out[0] = a;
        forn(i,n){
            out[i+1] = out[i]^enc[i];
        }
        return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vi a = {3,1}; Solution sol; vi out;
    out = sol.decode(a); print(out);
    return 0;
}