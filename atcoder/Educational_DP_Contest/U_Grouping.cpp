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

const ll inf = 1e18L;
const int nax = 16;
vl dp; // represents max possible score of all the taken rabits irrespective of groups
vl pre; // represents  score of a group of rabits
vvi a; // input
int n;

void rec(int idx, const vi &not_taken, ll cur_score, int mask, int group){
    if(idx==(int)not_taken.size()){
        max_self(dp[mask], cur_score + pre[group]);
        return;
    }
    
    // dont add this idx
    rec(idx+1, not_taken, cur_score, mask, group);

    // add this idx
    rec(idx+1, not_taken, cur_score, (mask ^ (1<<not_taken[idx])), (group ^ (1<<not_taken[idx])) );
}

int main(){
    while(cin>>n){
        dp.clear(); dp.resize((1<<n),-inf);
        pre.clear(); pre.resize(1<<n);
        a.clear(); a.resize(n, vi(n));

        forn(i,n)
            forn(j,n)
                cin>>a[i][j];

        // calculate score of each group
        for(int mask=0; mask<(1<<n); ++mask){
            for(int i=0; i<n; ++i){
                if(mask & (1<<i)){
                    for(int j=i+1; j<n; ++j){
                        if(mask & (1<<j)){
                            pre[mask]+=a[i][j];
                        }
                    }
                }
            }
        }

        dp[0] = 0;
        // form diff groups, find the ones not added in and try adding
        for(int mask=0; mask<(1<<n); ++mask){
            vi not_taken;
            for(int i=0; i<n; ++i){
                if(!(mask & (1<<i)))
                    not_taken.pb(i);
            }

            rec(0, not_taken, dp[mask] ,mask, 0);
        }

        cout<<dp[(1<<n)-1]<<endl;
    }
    return 0;
}