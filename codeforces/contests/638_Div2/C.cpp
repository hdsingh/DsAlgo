#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

bool all_eq(string &s, int pos){
    fore(i,pos,sz(s))
        if(s[i]!=s[pos])
            return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t,n,k; string s;
    cin>>t;
    while(t--){
        cin>>n>>k>>s;
        vs slot(k);
        sort(all(s));
        forn(i,k)
            slot[i].pb(s[i]);
        
        bool eq1 = true;
        forn(i,k)   
            if(slot[i]!=slot[0])
                eq1 = false;

        if(eq1){
            if(all_eq(s,k)){
                // distribute equally
                // deb(s);
                int i = 0; int pos =k;
                while(pos<n){
                    slot[i]+=s[pos];
                    ++i; ++pos;
                    if(i==k) i = 0;
                }
            }else{
                // all in 0
                fore(i,k,n)
                    slot[0]+=s[i];
            }
        }else{
             // all in 0 (min)
            fore(i,k,n)
                slot[0]+=s[i]; 
        }

        string ans = *max_element(all(slot));
        
        // print_vv(slot);
        cout<<ans<<endl;
        // cout<<endl;
    }
    return 0;
}