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

// Start from end and keep on adding nums in p1;
// If at any point the remaining nums to be added in p1,
// becomes less than cur i (that is is is some number available ahead)
// use it, add remaining nums to p2
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    while(cin>>n){
        // deb(n);
        ll sum = n*(n+1)/2;
        if(sum&1){
            cout<<"NO\n";
            continue;
        }
    
        cout<<"YES\n";
        vi p1, p2;
        ll req = sum/2;
        ll tot = 0;
        // deb(req);
        for(int i=n; i>=1; --i){
            tot+=i;
            p1.pb(i);
            ll dif = req-tot;
            if(dif<i){
                if(dif) p1.pb(dif);

                for(int j=i-1; j>=1; --j)
                    if(j!=dif)
                        p2.pb(j);
                break;
            }
        }

        ll s1 = accumulate(all(p1),0ll);
        ll s2 = accumulate(all(p2),0ll);
        // deb(s1,s2);
        assert(s1==s2);
        cout<<sz(p1)<<"\n";
        print(p1); 
        cout<<sz(p2)<<"\n";
        print(p2);
    }
    return 0;
}