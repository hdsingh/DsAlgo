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
const ll mod = 4294967296;
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
    int N; // size of Matrix
    vector<vector<unsigned int>> arr;
    Matrix(int _N){
        N = _N;
        reset();
    }

    void reset(){
        arr.assign(N, vector<unsigned int>(N));
    }

    void makeIdentity(){
        reset();
        forn(i,N) arr[i][i] = 1;
    }

    Matrix operator+(const Matrix &oth) const{
        Matrix res(N); 
        forn(i,N) forn(j,N){
            res.arr[i][j] = arr[i][j] + oth.arr[i][j];
        }   
        return res;
    }

    Matrix operator*(const Matrix &oth) const{
        Matrix res(N); res.reset();
        forn(k,N) forn(i,N) forn(j,N){
            res.arr[i][j] = (res.arr[i][j] + arr[i][k]*oth.arr[k][j]);
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

const vvi dirs = {{1,2},{1,-2},{-1,-2},{-1,2},{2,1},{2,-1},{-2,1},{-2,-1}};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll K;
    while(cin>>K){
        // Method 1 
        // vvl grid(8, vl(8));
        // grid[0][0] = 1;
        // ll ans = 1;
        // forn(i,K){
        //     vvl ngrid(8,vl(8));
        //     forn(i,8) forn(j,8){
        //         for(auto dir: dirs){
        //             int ni = i + dir[0], nj = j + dir[1];
        //             if(0<=ni && ni<8 && 0<=nj && nj<8)
        //                 add_self(ngrid[ni][nj], grid[i][j]);
        //         }
        //     }
        //     grid = ngrid;
        //     forn(i,8) forn(j,8) add_self(ans, grid[i][j]);
        // }
        // cout<<ans<<"\n";

        // Method 2
        // vector<unsigned int>  dp(65);
        // dp[0] = 1;
        // forn(I,K+1){
        //     vector<unsigned int> ndp(65);
        //     forn(i,8) forn(j,8){
        //         for(auto dir: dirs){
        //             int ni = i + dir[0], nj = j + dir[1];
        //             if(0<=ni && ni<8 && 0<=nj && nj<8){
        //                 ndp[8*ni+nj]+=dp[8*i+j];
        //             }
        //         }
        //     }
        //     ndp[64]+=dp[64];
        //     forn(i,8) forn(j,8){
        //         ndp[64]+=dp[8*i+j];
        //     }
        //     dp = ndp;
        // }
        // cout<<dp[64]<<"\n";

        Matrix moves(65);
        forn(i,8) forn(j,8){
            for(auto dir: dirs){
                int ni = i + dir[0], nj = j + dir[1];
                if(0<=ni && ni<8 && 0<=nj && nj<8){
                    moves.arr[8*i+j][8*ni+nj] = 1;
                }
            }
        }
        moves.arr[64][64] = 1;
        forn(i,8) forn(j,8) moves.arr[8*i+j][64] = 1;
        moves = pow(moves, K+1);
        cout<<moves.arr[0][64]<<"\n";
    }
    return 0;
}