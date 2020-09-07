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
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<ll,ll> m1, m2;
        for(auto x: nums1) m1[x]++;
        for(auto x: nums2) m2[x]++;

        ll ans = 0;
        for(auto p: m1){
            ll x = p.first*(p.first);
            ll cnt = p.second;
            for(ll d1=1; d1*d1<=x; ++d1){
                if(x%d1==0){
                    ll d2 = x/d1;
                    if(d1==d2){
                        if(m2.count(d1) && m2[d1]>1){
                            ans+=cnt*((m2[d1])*(m2[d1]-1)/2);
                        }
                    }else{
                        if(m2.count(d1) && m2.count(d2))
                            ans+=cnt*(m2[d1]*m2[d2]);
                    }
                }
            }
        }

        for(auto p: m2){
            ll x = p.first*(p.first);
            ll cnt = p.second;
            for(ll d1=1; d1*d1<=x; ++d1){
                if(x%d1==0){
                    ll d2 = x/d1;
                    if(d1==d2){
                        if(m1.count(d1) && m1[d1]>1){
                            ans+=cnt*((m1[d1])*(m1[d1]-1)/2);
                            // ans+=cnt*(m1[d1])*(m1[d1]-1);
                        }
                    }else{
                        if(m1.count(d1) && m1.count(d2))
                            ans+=cnt*(m1[d1]*m1[d2]);
                    }
                }
            }
        }

        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}