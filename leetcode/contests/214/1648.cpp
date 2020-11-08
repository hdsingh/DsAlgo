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

typedef long long ll;

// Find the point ans, after that pick 1 from each pile
// till we are able to complete order.
class Solution {
    const int mod = 1e9+7;
public:
    int maxProfit(vector<int>& a, int order) {
        sort(a.begin(), a.end(), greater<int>());

        auto can = [&](ll mid, bool ok){
            ll sum = 0;
            for(auto x: a){
                if(x<=mid) break;
                ll dif = x-mid;
                sum+=dif;
            }
            
            return (sum<=order);
        };

        ll lt = -1, rt = a.front()+1, ans = a.front();

        // N N N Y Y Y
        while(1+lt<rt){
            ll mid = lt + (rt-lt)/2;
            if(can(mid,0)){
                ans = mid;
                rt = mid;
            }else{
                lt = mid;
            }
        }

        ll tot = 0, used = 0;
        for(auto &x: a){
            if(x<=ans) break;
            tot+=find_sum(ans, x);
            used+=(x-ans);
            x = ans;
        }
        assert(used<=order);

        for(auto x: a){
            if(used>=order) break;
            tot+=x; ++used;
        }
        assert(used==order);
        return tot%mod;
    }

    ll find_sum(ll lt, ll rt){
        return rt*(rt+1)/2 - lt*(lt+1)/2;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vi a; int X, out; 
    a = {2,8,4,10,6}, X = 20;  
    a = { 497978859,167261111,483575207,591815159},
    X = 836556809;
    a = {5,5,5},X = 4;
    out = sol.maxProfit(a, X); deb(out);
    return 0;
}