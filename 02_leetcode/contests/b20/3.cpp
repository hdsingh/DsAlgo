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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

class Solution1 {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        if(n<3) return 0;
        vi a(n), b(n), c(n);
        a[0] = s[0]=='a';
        b[0] = s[0]=='b';
        c[0] = s[0]=='c';

        for(int i=1; i<n; i++){
            a[i] = a[i-1] + (s[i]=='a'); 
            b[i] = b[i-1] + (s[i]=='b'); 
            c[i] = c[i-1] + (s[i]=='c'); 
        }

        int cnt = 0;
        for(int i=2; i<n; i++){
            for(int j=i-2; j>=0; j--){
                int ac = a[i] - (j-1>=0 ? a[j-1] : 0);
                int bc = b[i] - (j-1>=0 ? b[j-1] : 0);
                int cc = c[i] - (j-1>=0 ? c[j-1] : 0);
                if(ac && bc && cc){
                    cnt+=j+1;
                    break;
                }
            }
        }
        return cnt;        
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        int la=-1; int lb=-1; int lc =-1; //last loc of a,b,c
        for(int i=0; i<n; i++){
            la = s[i]=='a' ? i : la;
            lb = s[i]=='b' ? i : lb;
            lc = s[i]=='c' ? i : lc;
            int minpt =min({la,lb,lc});
            if(minpt>=0)
                cnt+=minpt+1;

        }
        return cnt;
    }
};

int main(){
    Solution sol; string s; int out;
    s = "abcabc";
    s = "aaacb";
    // s = "a";
    out = sol.numberOfSubstrings(s); deb(out);
    return 0;
}