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

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m;
    while(cin>>n>>m){
        if(m==0){
            cout<<"3 "<<n*(n-1)*(n-2)/6<<"\n";
            continue;
        }

        vvi adj(n+1);
        forn(i,m){
            int x, y; cin>>x>>y;
            adj[x].pb(y); adj[y].pb(x);
        }

        bool isBipartite = 1;
        bool hasOnlySingleEdge = true;
        ll ans = 0;
        vi cols(n+1,-1);
        fore(i,1,n+1){
            if(cols[i]!=-1) continue;
            cols[i] = 1;
            queue<int> q;
            q.push(i);
            ll b = 0, w = 0;

            while(!q.empty()){
                auto top = q.front(); q.pop();
                for(auto ad: adj[top]){
                    if(cols[ad]==-1){
                        cols[ad] = cols[top]^1;
                        q.push(ad);
                    }else{
                        isBipartite&=(cols[ad]!=cols[top]);
                    }
                }
                if(cols[top]){
                    ++w;
                }else 
                    ++b;
            }

            if(w+b>2){
                hasOnlySingleEdge = false;
                ans+=w*(w-1)/2 + b*(b-1)/2;
            }
        }

        if(!isBipartite){
            cout<<"0 1\n";
        }else if(hasOnlySingleEdge){
            cout<<"2 "<<m*(n-2)<<"\n";
        }else{
            cout<<"1 "<<ans<<"\n";
        }

    }
    return 0;
}