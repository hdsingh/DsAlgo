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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

void min_self(int &a, int b){
    a = min(a,b);
}

const int W = 0;
const int B = 1;

int main(){
    int n,m,x,y;
    char c;
    while(cin>>n>>m>>x>>y){
        vvi C(m+1, vi(2)); //in mth column, # of w, b
        forn(i, n){
            fore(j,1, m+1){
                cin>>c;
                if(c=='#')
                    C[j][B]++;
                else 
                    C[j][W]++;
            }
        }

        // print_vv(C);
        vvi pre(m+1, vi(2)); // accumulation till mth col, of w, b
        forn(clr, 2){
            fore(j, 1, m+1){
                pre[j][clr] = pre[j-1][clr] + C[j][clr];
            }
        }

        // print_vv(pre);

        auto prev = [&](int r, int l, int clr){
            return pre[r][clr] - (l-1>=0 ?  pre[l-1][clr] : 0);
        };

        vvi dp(m+1, vi(2, inf));
        dp[0][W] = dp[0][B] = 0;
        forn(i,m+1){
            fore(sz, x, y+1){
                forn(clr, 2){
                    if(i+sz<=m){
                        min_self(dp[i+sz][clr], dp[i][!clr] + prev(i+sz, i+1, clr));
                    }
                }
            }
        }

        // print_vv(dp);
        cout<<min(dp[m][B], dp[m][W])<<endl;

    }
    return 0;
}