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

const int nax = 1e3+10;
int n;
vvi X(nax, vi(nax)), Y(nax, vi(nax));
vs mat(nax, string(nax, ' '));

bool connect(int i, int j, int ni, int nj, char d1, char d2){
    if(X[ni][nj]==-1){
        mat[i][j] = d1;
        if(mat[ni][nj]!=' ') mat[ni][nj] = d2;
        return 1;
    }else   
        return 0;
}

void dfs(int i, int j, char d){
    if(mat[i][j]!=' ') return;
    mat[i][j] = d;

    if(X[i][j]==X[i+1][j] && Y[i][j]==Y[i+1][j])
        dfs(i+1, j, 'U');
    if(X[i][j]==X[i-1][j] && Y[i][j]==Y[i-1][j])
        dfs(i-1,j,'D');
    if(X[i][j]==X[i][j+1] && Y[i][j]==Y[i][j+1])
        dfs(i,j+1, 'L');
    if(X[i][j]==X[i][j-1] && Y[i][j]==Y[i][j-1])
        dfs(i,j-1, 'R');
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    fore(i,1,n+1)   
        fore(j,1,n+1)
            cin>>X[i][j]>>Y[i][j];
    
    fore(i,1,n+1){
        fore(j,1,n+1){
            if(X[i][j]==-1){ // loop
                int res = mat[i][j]!=' ';
                if(!res) res = connect(i,j,i+1,j,'D','U');
                if(!res) res = connect(i,j,i-1,j,'U','D');
                if(!res) res = connect(i,j,i,j+1,'R','L');
                if(!res) res = connect(i,j,i,j-1,'L','R');
                if(!res){
                    cout<<"INVALID"<<endl;
                    return 0;
                }
            }else if(X[i][j]==i && Y[i][j]==j){ // start from blocked
                dfs(i,j,'X');
            }
        }
    }

    fore(i,1,n+1){
        fore(j,1,n+1){
            if(mat[i][j]==' '){
                cout<<"INVALID"<<endl;
                return 0;
            }
        }
    }

    cout<<"VALID"<<endl;
    fore(i,1,n+1){
        fore(j,1,n+1){
            cout<<mat[i][j];
        }
        cout<<endl;
    }

    return 0;
}