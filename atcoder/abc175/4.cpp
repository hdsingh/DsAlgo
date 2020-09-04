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

ll n,K;
vi P;
vl C;
vvi cycles;
vi cycle;
vb vis;

void dfs(int x){
    vis[x] = 1;
    cycle.pb(C[x]);
    if(!vis[P[x]]) 
        dfs(P[x]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin>>n>>K){
        cycles.clear();
        P.resize(n+1); C.resize(n+1);
        vis.assign(n+1,0);
        fore(i,1,n+1) cin>>P[i];
        fore(i,1,n+1) cin>>C[i];
              
        fore(i,1,n+1){
            if(!vis[i]){
                cycle.clear();
                dfs(i);
                cycles.pb(cycle);
            }
        }

        // print_vv(cycles);

        ll ans = INT_MIN;
        for(auto &cyc: cycles){
            ll tot_sum = accumulate(all(cyc),0ll);
            ll len = sz(cyc);
            ll rounds = K/len;
            ll extra = K%len;
            if(extra==0){
                rounds--;
                extra+=len;
            }
            
            if(tot_sum<=0){
                extra = min(K, len);   
            }

            ll mx_extra_sum = cyc.front();
            // start from each pt and check till i+extra-1
            forn(i,len){
                ll cur_sum = 0;
                forn(j,extra){
                    cur_sum+=cyc[(i+j)%len];
                    max_self(mx_extra_sum, cur_sum);
                }
            }

            ll cyc_ans = mx_extra_sum;
            if(tot_sum>0)
                cyc_ans+=tot_sum*rounds;
            
            max_self(ans, cyc_ans);
        }

        cout<<ans<<"\n";
    }

    return 0;
}