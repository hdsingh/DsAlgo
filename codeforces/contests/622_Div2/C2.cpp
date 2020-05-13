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

int n;
const int nax = 5e5+10;
// const int nax = 10;
vl a(nax);

void go(vl &sum){
    stack<int> stk;
    stk.push(0);
    // 1 5 6 2
    fore(i,1,n+1){
        while(a[stk.top()]>=a[i])
            stk.pop();
    
        int top = stk.top(); // this is index of  prev min, less than a[i]
        sum[i] = sum[top] + (i-top)*a[i];
        stk.push(i);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    fore(i,1,n+1) cin>>a[i];

    vl lsum(nax), rsum(nax);

    go(lsum);
    reverse(a.begin()+1, a.begin()+1+n);
    go(rsum);
    reverse(a.begin()+1, a.begin()+1+n);
    reverse(rsum.begin()+1, rsum.begin()+1+n); 
    // since rsum stored in reverse manner , due to same function


    // print(a,1);
    // print(lsum);
    // print(rsum);

    // find the pos, where max sum can be obtained
    pll mx({0,1});
    fore(i,1,n+1){
        // deb(i, lsum[i] +  rsum[i] - a[i]);
        mx = max(mx, {lsum[i] + rsum[i] - a[i],i});
    }

    ll min_val = a[mx.second];
    for(int i=mx.second-1; i>=1; --i){
        min_val = min(min_val, a[i]);
        a[i] = min_val;
    }

    min_val = a[mx.second];
    // deb(min_val, mx.second);
    for(int i=mx.second+1; i<=n; ++i){
        min_val = min(min_val, a[i]);
        a[i] = min_val;
    }

    fore(i,1,n+1) cout<<a[i]<<" ";
    cout<<"\n";

    return 0;
}