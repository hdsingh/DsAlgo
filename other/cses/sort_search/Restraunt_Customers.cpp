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

// Coordinate compression + (+,-) counting
int main1(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n){
        vector<pii> a(n);
        forn(i,n) cin>>a[i].first>>a[i].second;
        set<int> s;
        forn(i,n) s.insert(a[i].first), s.insert(a[i].second);
        int id = 1;
        map<int,int> m;
        for(auto x: s) m[x] = id++;


        vi locs(id+2);
        forn(i,n){
            a[i].first = m[a[i].first];
            a[i].second = m[a[i].second];
            locs[a[i].first]++;
            locs[a[i].second+1]--;
        }
        partial_sum(all(locs),locs.begin());
        cout<<*max_element(all(locs))<<endl;
        // print_vp(a);

        
    }
    return 0;
}

// Same Idea, Better implementation
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n){
        vector<pair<int,int>> a;
        int st,ed;
        forn(i,n){
            cin>>st>>ed;
            a.pb({st,1});
            a.pb({ed,-1});
        }
        sort(all(a));

        int cnt = 0;
        int ans = 0;
        forn(i,sz(a)){
            cnt+=a[i].second;
            ans = max(ans,cnt);
        }
        cout<<ans<<endl;

    }
    return 0;
}