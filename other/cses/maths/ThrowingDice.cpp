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
    ll n; 
    while(cin>>n){

        // vl save(n+1);
        // function<ll(ll)> dfs = [&](ll a){
        //     if(a<0) return 0LL;
        //     if(a==0) return 1LL;
        //     if(save[a]!=0) return save[a];
        //     ll ans = 0;
        //     for(int i=1; i<=6 && a-i>=0; ++i){
        //         ans+=dfs(a-i);
        //     }
        //     return save[a] = ans;
        // };
        // cout<<dfs(n)<<"\n";
        // print(save,1);
        
        vl dp = {1,2,4,8,16,32};
        //       2 4 8 16 32 ?
        // forn(i,n-1){
        //     vl ndp(6);
        //     forn(j,6){
        //         ndp[5]+=dp[j];
        //     }
        //     forn(j,5)
        //         ndp[j] = dp[j+1];
        //     dp = ndp;
        // }
        // cout<<dp[0]<<"\n";

        Matrix m(6);
        // Assigning values to m based on above transitions.
        forn(j,6){
            m.a[j][5] = 1;
        }
        forn(j,5){
            m.a[j+1][j] = 1;
        }

        m = pow(m,n-1);
        vl ndp(6);
        forn(i,6) forn(j,6){
            add_self(ndp[j], dp[i]*m.a[i][j]%mod);
        }
        cout<<ndp[0]<<"\n";

    }
    return 0;
}