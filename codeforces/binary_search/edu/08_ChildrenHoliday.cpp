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

int m,n;
vi t,z,y;

bool can(ll T, bool show = 0){
    ll tot = 0;
    forn(i,n){
        // deb(i);
        ll cur = T;
        int cnt = 0;
        while(cur>0){
            if(cur<t[i]) break;
            cur-=t[i];
            ++cnt;
            if(cnt%z[i]==0) cur-=y[i];
            // deb(cur,cnt);
        }
        if(show) cout<<max(0ll, min((ll)cnt, m-tot))<<" ";

        tot+=cnt;
        if(tot>=m) return 1;
    }
    if(show) cout<<"\n";
    return tot>=m;
}

// inflates a balloon in ti minutes, but every time after zi balloons are inflated he gets tired and rests for yi minutes. 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m>>n;
    t.resize(n), y.resize(n), z.resize(n);
    forn(i,n){
        cin>>t[i]>>z[i]>>y[i];
    }
    
    if(m==0){
        cout<<"0\n";
        forn(i,n) cout<<"0\n";
        return 0;
    }

    ll l = 0, r = 1e8, ans = 0;
    while(1+l<r){
        ll mid = (l+r)/2;
        if(can(mid))
            r = mid, ans = mid;
        else    
            l = mid;
    }
    cout<<ans<<"\n";
    can(ans, 1);

    return 0;
}