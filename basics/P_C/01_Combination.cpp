#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

const int MAXN = 10;
ll C[MAXN+1][MAXN+1];
// vvl C(MAXN+1, vl(MAXN+1));

void precalc(){

    C[0][0] = 1;
    for(int i=1; i<=MAXN; i++){
        C[i][0] = C[i][i] =1;

        for(int j=1; j<=i/2; j++)
            C[i][j] = C[i][i-j] = C[i-1][j-1] + C[i-1][j];
    }

}

const int N = 10;
void precalc2(){
    // vvl C(N, vl(N));
    C[0][0] = 1;
    for(int i=1; i<N; ++i){
        C[i][0] = C[i][i] = 1;
        for(int j=1; j<i; ++j)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}

int main(){
    precalc();
    
    deb(C[10][2]);

    // print_vv(C);
    return 0;
}