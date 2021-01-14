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

const ll inf = 3e18L + 100;
class Matrix{
public:
    int N; // size of Matrix
    vector<vector<ll>> arr;
    Matrix(int n){
        N = n;
        arr.assign(n, vl(n, inf));
    }

    void makeIdentity(){
        arr.assign(N, vl(N, inf));
        forn(i,N) arr[i][i] = 1;
    }

    Matrix operator*(const Matrix &oth) const{
        Matrix res(N);
        forn(i,N) forn(k,N) forn(j,N){
            min_self(res.arr[i][j], arr[i][k] + oth.arr[k][j]);
        }
        return res;
    }
};

Matrix pow(Matrix a, ll p){
    Matrix c(a); 
    while(p){
        if(p&1) c = c*a;
        a = a*a;
        p>>=1;
    }
    return c;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; ll K;
    while(cin>>n>>m>>K){
        ll ans = inf;
        Matrix G(n);
        forn(i,m){
            int x, y, w; cin>>x>>y>>w;
            --x,--y;
            min_self(G.arr[x][y], w);
        }

        G = pow(G,K-1);
        forn(i,n) forn(j,n) min_self(ans, G.arr[i][j]);
        

        // vvl G(n,vl(n, inf));
        // forn(i,m){
        //     int x, y, w; cin>>x>>y>>w;
        //     --x,--y;
        //     min_self(G[x][y], w);
        // }

        // // G = pow(G,K,G);

        // vvl dp(G);
        // forn(rep, K-1){
        //     vvl ndp(n, vl(n, inf));
        //     forn(k,n) forn(i,n) forn(j,n){
        //         min_self(ndp[i][j], dp[i][k] + G[k][j]);
        //     }
        //     dp = ndp;
        // }
        // forn(i,n) forn(j,n) min_self(ans, dp[i][j]);

        if(ans>=inf/2){
            cout<<"IMPOSSIBLE\n";
        }else{
            cout<<ans<<"\n";
        }
    }
    return 0;
}