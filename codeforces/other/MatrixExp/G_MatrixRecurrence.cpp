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


class Matrix{
public:
    int n; // size of Matrix
    vector<vector<ll>> a;
    Matrix(int N){
        n = N;
        a.assign(n, vl(n));
    }

    void makeIdentity(){
        a.assign(n, vl(n));
        forn(i,n) a[i][i] = 1;
    }

    Matrix operator*(const Matrix &oth) const{
        Matrix res(n);
        forn(i,n) forn(k,n) forn(j,n){
            res.a[i][j] = (res.a[i][j] + a[i][k]*oth.a[k][j])%mod;
        }
        return res;
    }

    Matrix operator+(const Matrix &oth) const{
        Matrix res(n); 
        forn(i,n) forn(j,n){
            res.a[i][j] = a[i][j] + oth.a[i][j];
            if(res.a[i][j]>=mod) res.a[i][j]-=mod;
        }   
        return res;
    }
};

Matrix pow(Matrix a, ll p){
    Matrix c(a); c.makeIdentity();
    while(p){
        if(p&1) c = c*a;
        a = a*a;
        p>>=1;
    }
    return c;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; ll K;
    while(cin>>n>>K){
        vl a(n), c(n);
        forn(i,n) cin>>a[i];
        forn(i,n) cin>>c[i];
        ll p, q, r; cin>>p>>q>>r;
        if(K<n){
            cout<<a[K]<<"\n"; continue;
        }

        vl dp(n+3);
        dp[n] = 1; // for 1
        dp[n+1] = n; // for i
        dp[n+2] = n*n; // for i*i
        forn(i,n) dp[i] = a[i];

        Matrix m(n+3);
        m.a[n][n-1] = p;
        m.a[n+1][n-1] = q;
        m.a[n+2][n-1] = r;
        m.a[n][n] = 1;
        m.a[n+1][n+1] = 1;
        m.a[n][n+1] = 1;
        m.a[n+2][n+2] = 1;
        m.a[n+1][n+2] = 2;
        m.a[n][n+2] = 1;
        forn(j,n){
            m.a[n-1-j][n-1] = c[j];
        }
        forn(j,n-1){
            m.a[j+1][j] = 1;
        }

        m = pow(m,K-n+1);

        vl ndp(n+3);
        forn(i,n+3) forn(j,n+3){
            add_self(ndp[j], dp[i]*m.a[i][j]%mod);
        }
        cout<<ndp[n-1]<<"\n";

        // basic process, given the resultant coeff matrix = m;
        // forn(times, rep){
        //     vl ndp(n+3);
        //     forn(i,n+3) forn(j,n+3){
        //         ndp[j]+=dp[i]*m[i][j];
        //     }
        //     dp = ndp;
        // }


        // fore(i,n,K+1){
        //     vl ndp(n+3);
        //     // deb(dp[n], dp[n+1], dp[n+2]);
        //     // ndp[n-1] = p + i*q + i*i*r;
        //     // use 1, i,to compute new val
        //     ndp[n-1] += p * dp[n];
        //     ndp[n-1] += q * dp[n+1];
        //     ndp[n-1] += r * dp[n+2];

        //     // update 1
        //     ndp[n] = dp[n];
        //     // update i (ni = i + 1)
        //     ndp[n+1] = dp[n+1] +  dp[n]; 
        //     // update i*i, (i+1)^2 = i*i + 2i + 1
        //     ndp[n+2] = dp[n+2] + 2*dp[n+1] + dp[n];

        //     forn(j,n){
        //         add_self(ndp[n-1], c[j]*dp[n-1-j]);
        //     }
            
        //     forn(j,n-1) ndp[j] = dp[j+1];
        //     dp = ndp;
        // }
        // cout<<dp[n-1]<<"\n";
    }
    return 0;
}