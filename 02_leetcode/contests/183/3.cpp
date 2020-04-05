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

class Solution {
    string s;
public:
    string longestDiverseString(int a, int b, int c) {
        s.clear();
        vector<pair<int,char>> v;
        v.push_back({a,'a'});
        v.push_back({b,'b'});
        v.push_back({c,'c'});

        // in every iter pick the element with max lim that satisfies condition
        int total = a + b + c;
        while(total>0){
            sort(v.rbegin(),v.rend());
            // for(auto p: v)
            //     cout<<p.first<<": "<<p.second<<"  ";
            // cout<<endl;
    
            bool added = false;
            for(int i=0; i<3; ++i){
                int cnt = v[i].first;
                char l = v[i].second;
                if(cnt==0) continue;
            
                if(canAdd(l)){
                    s+=l;
                    v[i].first--;
                    total--;
                    added = true;
                    break;
                }
            }
    
            if(!added) break;
        }
        return s;
    }

    bool canAdd(char l){
        int n = s.size();
        if(n<2 || (s[n-1]!=l || s[n-2]!=l)) return true;
        return false;
    }
};

int main(){
    int a,b,c;
    Solution sol; string out;
    a = 1, b = 1, c = 7;
    out = sol.longestDiverseString(a,b,c); deb(out);
    a = 2, b = 2, c = 1;
    out = sol.longestDiverseString(a,b,c); deb(out);
    a = 7, b = 1, c = 0;
    out = sol.longestDiverseString(a,b,c); deb(out);
    a = 0, b = 9, c = 12;
    out = sol.longestDiverseString(a,b,c); deb(out);

    return 0;
}