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
// #define ar array
typedef array<int,3> ar;
const int arv = 1;
const int dept = 0;
const int id = 2;

// based on room allocation.
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    while(cin>>n>>k){
        int ans2 = 0;
        vector<int> ans(n);
        vector<ar> a(n); //{dept, arrive}
        forn(i,n) cin>>a[i][arv]>>a[i][dept], a[i][id] = i;
        sort(all(a));// based on dept
        for(auto x: a){
            auto [dep, av, id] = x;
            deb(av, dep);
        }

        set<ar> s; // {dept, room id}
        forn(i,n){
            auto it = s.upper_bound({a[i][arv]});
            if(it!=s.begin()){
                --it;
                ans[a[i][id]] = (*it)[1];
                s.erase(it);
            }else{
                ans[a[i][id]] = sz(s);
            }

            if(sz(s)<k){
                deb(ans[a[i][id]]+1);
                s.insert({a[i][dept], ans[a[i][id]]});
                ++ans2;
            }
        }

        cout<<ans2<<"\n";
    }
    return 0;
}