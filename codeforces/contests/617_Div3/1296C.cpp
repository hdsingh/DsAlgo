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



int main(){
    map<char, pii> dir;
    dir['L'] = {-1,0};
    dir['R'] = {1,0};
    dir['U'] = {0,1};
    dir['D'] = {0,-1};

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        pii beg = {0,0};
        map<pii, int> seen;
        seen[beg] = 0;

        pii ans = {-1,-1};
        int len = INT_MAX;
        string s; cin>>s;
        forn(i,n){
            char c = s[i];
            beg.first+= dir[c].first;
            beg.second+=dir[c].second;

            if(seen.count(beg)){
                int clen = i+1 - seen[beg]+1;
                if(clen<len){
                    len = clen;
                    ans = {seen[beg]+1, i+1};
                }
            }

            seen[beg] = i+1;
        }

        if(len!=INT_MAX){
            cout<<ans.first<<" "<<ans.second<<endl;
        }else{
            cout<<-1<<endl;
        }



    }
    return 0;
}