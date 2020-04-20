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

bool is_pal(string s){
    string r = s; reverse(all(s));
    return r==s;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m; string s,r;
    while(cin>>n>>m){
        map<string, int> cnt;
        forn(i,n){
            cin>>s;
            r = s; reverse(all(s));
            if(cnt.count(r)){
                cnt[r]++;
            }else{
                cnt[s]++;
            }
        }
 
        // print_m(cnt);
        string f, b;
        for(auto &p: cnt){
            if(p.second>=2){
                f+=p.first;
                r = p.first; reverse(all(r));
                b = r + b;
                p.second-=2;
            }
        }

        // print_m(cnt);
        int len = 0;
        string pal; 
        for(auto p: cnt){
            if(p.second>=1 && (int)p.first.size()>len && is_pal(p.first)){
                pal = p.first;
                len = p.first.size();
            }
        }

        int sz = f.size() + pal.size() + b.size();
        cout<<sz<<endl;
        cout<<f<<pal<<b<<endl;

    }
    return 0;
}