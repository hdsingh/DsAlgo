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


// ans[0] = x
// i is bad, ans[i] = ans[0] = x
// else ans[i] = (ans[i+1]...ans[i+m])/M + 1
// since this rel is cyclic, and depends on the val of ans[0], 
// we can suppose ans[0] = x
// and ans[i] = cof[i]*x + val[i]
// ans[0] = cof[0]*x + val[0]
// x = c*x + v
// x(1-c) = v 
// x = v/(1-c)

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, K;
    while(cin>>n>>m>>K){
        vi vis(n+m+1);
        forn(i,K){
            int x; cin>>x;
            vis[x] = 1;
        }

        vector<double> cof(n+m+1), val(n+m+1);
        double c = 0, v = 0, sum = 0;
        bool ok = 1;
        for(int i=n-1; i>=0; --i){
            if(vis[i]){
                // ans =  f[0]
                cof[i] = 1, val[i] = 0;
            }else{
                cof[i] = c/m;
                val[i] = v/m + 1;
            }

            sum += vis[i] - vis[i+m];
            if(sum==m){
                ok = 0;
                break;
            }
            c+=cof[i] - cof[i+m]; // sliding window
            v+=val[i] - val[i+m];
        }

        if(!ok){
            cout<<"-1\n";
        }else{
            cout<<fixed<<setprecision(10)<<val[0]/(1-cof[0])<<"\n";
        }

    }
    return 0;
}