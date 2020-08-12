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

class Solution0 {
public:
    ll maxSum(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size(),  i = 0, j = 0;
        vi twice;
        map<int,int> cnt;
        for(auto x: a) cnt[x]++;
        for(auto x: b) cnt[x]++;
        for(auto p: cnt)
            if(p.second==2)
                twice.push_back(p.first);
        twice.push_back(1e9);

        ll tot = 0;
        for(auto x: twice){
            ll sum1 = 0, sum2 = 0;
            while(i<n && a[i]<x) sum1+=a[i++];
            while(j<m && b[j]<x) sum2+=b[j++];
            tot+=max(sum1, sum2);
            if(x!=1e9)
                tot+=x;
            ++i, ++j;
        }
        return tot%mod;
    }
};

class Solution {
public:
    ll maxSum(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size(), i = 0, j = 0;
        ll sum1 = 0, sum2 = 0, tot = 0;
        while(i<n && j<m){
            if(a[i]<b[j])
                sum1+=a[i++];
            else if(b[j]<a[i])
                sum2+=b[j++];
            else{
                tot+= a[i] + max(sum1, sum2);
                tot%=mod;
                sum1 = sum2 = 0;
                i++, j++;
            }
        }
        while(i<n) sum1+=a[i++];
        while(j<m) sum2+=b[j++];
        tot+=max(sum1, sum2);
        tot%=mod;

        return tot;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;
    vi a, b; int out;
    a = {2,4,5,8,10}, b = {4,6,8,9};
    out = sol.maxSum(a,b); deb(out);
    a = { 1,3,5,7,9 }, b = { 3,5,100 };
    out = sol.maxSum(a,b); deb(out);

    return 0;
}