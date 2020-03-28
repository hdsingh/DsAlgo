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
    int x, y, a,b,c, w;
    while(cin>>x>>y>>a>>b>>c){
        ll ans = 0 ;
        vector<pii> app;
        forn(i,a){
            cin>>w;
            app.push_back({w,1});
        }
        forn(i,b){
            cin>>w;
            app.push_back({w,2});
        }

        forn(i,c){
            cin>>w;
            app.push_back({w,3});
        }

        sort(all(app), [&](pii &p1, pii &p2){
            return p1.first>p2.first;
        });

        ll sum = 0;
        int t = x+y;
        int ca(0), cb(0), co(0);
        for(int i=0; i<app.size(); ++i){
            int cur_c = app[i].second;
            int cur_v = app[i].first;
            
            if(cur_c == 1 && ca<x){
                sum+=cur_v; ca++; 
                --t;
            }else if(cur_c==2 && cb<y){
                sum+=cur_v; cb++;
                --t;
            }else if(cur_c==3){

                sum+=cur_v; co++;
                --t;
            }

            

            if(t==0) break;
        }
        cout<<sum<<endl;
    } 
    return 0;
}