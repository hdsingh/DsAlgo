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

// Ref: https://www.youtube.com/watch?v=4jY57Ehc14Y

// prefix_function
vi computeLPSArray(string s){
    int m = s.size();
    vi pi(m);
    int len = 0, i = 1;
    while(i<m){
        if(s[len]==s[i]){
            pi[i] = len+1;
            ++len; ++i;
        }else{
            if(len!=0)
                len = pi[len-1];
            else{
                pi[i] = 0;
                ++i;
            }
        }
    }

    return pi;
}

// Another implementation
// Ref: https://cp-algorithms.com/string/prefix-function.html

vi prefix_function(string &s){
    int m = s.size();
    vi pi(m);
    for(int i=1; i<m; ++i){
        int len = pi[i-1];
        while(len>0 && s[i]!=s[len])
            len = pi[len-1];
        if(s[i]==s[len])
            ++len;

        pi[i] = len;
    }
    return pi;
}

void kmpSearch(string s, string p){
    int n = s.size();
    int m = p.size();
    vi pi = prefix_function(s);
    int i=0, j=0;
    while(i<n-m+1){
        if(s[i]==p[j])
            ++i, ++j;
        else{
            // move j back and then compare
            if(j!=0)
                j = pi[j-1];
            else 
                ++i;
            // if j reaches 0, put 0 and start from next index
        }

        if(j==m){
            cout<<i-j<<endl;
            j = pi[j-1];
        }
    }
}

int main(){
    vs ss = {
        "abcabcd",
        "aabaaab",
    };
    for(auto s: ss){
        vi lps = prefix_function(s); print(lps);
    }

    string s = "onionsionspl", p ="onions";
    kmpSearch(s,p);
    vi d = prefix_function(s); print(d);
    d = prefix_function(p); print(d);


    return 0;
}

// https://codeforces.com/problemset/problem/126/B
// [Prefix-Suffix Palindrome](https://codeforces.com/contest/1326/problem/D2)