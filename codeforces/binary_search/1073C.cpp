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

#define x first
#define y second

string s;
int n,x,y;



void upd(pii &pos, char mv, int d){
    if(mv=='U')
        pos.y+=d;
    else if(mv=='D')
        pos.y-=d;
    else if(mv=='L')
        pos.x-=d;
    else if(mv=='R')
        pos.x+=d;
}

bool can(pii u, pii v, int len){
    int d = abs(u.x - v.x) + abs(u.y - v.y);
    if(d%2 != len%2) return false;
    return len>=d;
}

bool ok(int len){
    pii pos = {0,0};
    for(int i=len; i<n; ++i)
        upd(pos, s[i], 1);
    
    int l = 0, r = len;

    while(r<=n){
        if(can(pos,{x,y}, len))
            return true;

        upd(pos, s[l++], 1);
        upd(pos, s[r++],-1);
    }
    return false;
}

int main(){
    while(cin>>n>>s>>x>>y){
        // deb3(n,s,x);
        if(!ok(n)){
            cout<<-1<<endl;
            continue;
        }

        int l = -1, r = n;
        while(1+l<r){
            int mid = l + (r-l)/2;
            // if can reach in mid steps, it can also reach in mid+1, +2, + 3, ...inf
            // so we are interested in finding less
            if(ok(mid))
                r = mid;
            else 
                l = mid;
        }
        cout<<r<<endl;
    }
    return 0;
}