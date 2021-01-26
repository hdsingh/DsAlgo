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

#define x first
#define y second
typedef array<int,3> arr;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; 
    while(cin>>n){
        vector<pii> a(n+1);
        fore(i,1,n+1) cin>>a[i].x>>a[i].y;
        int m; cin>>m;
        vector<pii> ops(m+1);
        fore(i,1,m+1){
            cin>>ops[i].x;
            if(ops[i].x>=3){
                cin>>ops[i].y;
            }
        }

        int q; cin>>q;
        vector<arr> qs(q);
        forn(i,q){
            cin>>qs[i][0]>>qs[i][1];
            qs[i][2] = i;
        }
        sort(all(qs));
        vector<pll> ans(q);

        ll sw = 0, sx = 1, sy = 1, cx = 0, cy = 0;

        auto calc = [&](ll x, ll y){
            pll out = {-1,-1};
            if(!sw){
                out = {sx*x+cx, sy*y+cy};
            }else{
                out = {sx*y+cx, sy*x+cy};
            }

            return out;
        };


        int id = 0;
        forn(i,m+1){
            if(i){
                if(ops[i].x==1){
                    sw^=1;
                    swap(sx,sy), swap(cx,cy);
                    sy*=-1, cy*=-1;
                }else if(ops[i].x==2){
                    sw^=1;
                    swap(sx,sy), swap(cx,cy);
                    sx*=-1, cx*=-1; 
                }else if(ops[i].x==3){
                    ll p = ops[i].y;
                    sx*=-1, cx*=-1; 
                    cx+=2*p;
                }else{
                    ll p = ops[i].y;
                    sy*=-1, cy*=-1;
                    cy+=2*p;
                }
            }

            while(id<q && qs[id][0]==i){
                int idx = qs[id][1];
                ans[qs[id][2]] = calc(a[idx].x, a[idx].y);
                ++id;
            }
        }

        for(auto x: ans){
            cout<<x.x<<" "<<x.y<<"\n";
        }
    }
    return 0;
}