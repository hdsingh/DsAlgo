#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

const int nmax = 52;

int m,n;
vvl mat, res1,res2;

void print_mat(vvl &M){
    forn(i,m){
        forn(j,m){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}

void mult(vvl &A, vvl&B){
    
    forn(i,m)
        forn(j,m){
            res2[i][j] = 0;
            forn(k,m){
                res2[i][j] += (A[i][k]%mod * B[k][j]%mod)%mod;
                res2[i][j]%=mod;
            }
        }

    forn(i,m)
        forn(j,m)
            A[i][j] = res2[i][j];
                
}

void power(vvl &M, int p){
    
    forn(i,m)
        forn(j,m)
            res1[i][j] = i==j;

    // Exponential
    while(p){
        if(p&1)
            mult(res1,mat);
        
        mult(M,M);
        p>>=1;
    }

    forn(i,m)
        forn(j,m)
            M[i][j] = res1[i][j];
}


// M^n
int main(){
    mat.resize(nmax, vl(nmax));
    res1.resize(nmax, vl(nmax));
    res2.resize(nmax, vl(nmax));
    int t;
    cin>>t;
    while(t--){
        cin>>m>>n;
        forn(i,m) forn(j,m) cin>>mat[i][j];

        power(mat,n);

        print_mat(mat);
        // cout<<endl;
        
    }    
    return 0;
}