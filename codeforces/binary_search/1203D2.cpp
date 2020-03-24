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

// ref: https://medium.com/@aashish.gaba097/remove-some-substring-from-of-maximum-possible-length-such-that-after-removing-this-substring-t-266045d698bb
int main(){
    string s, t;
    while(cin>>s>>t){   
        int n = s.size(), m = t.size();
        vi leftmost(m), rightmost(m);
        int i =0, j=0;
        while(i<n && j<m){
            if(s[i]==t[j])
                leftmost[j++] = i;
            ++i;
        }

        i = n-1; j=m-1;
        while(i>=0 && j>=0){
            if(s[i]==t[j])
                rightmost[j--] = i;
            --i;
        }

        // deb2(s,t);
        // print(leftmost);
        // print(rightmost);
        // cout<<endl;
        
        // dif bw occurance of leftmost pos of i and rightmost pos of i+1
        // for char in t, all the inbetween char could be removed 
        int ans = max(n-1 -leftmost[m-1], rightmost[0]);
        for(int i=0; i<m-1; i++)
            ans = max(ans, rightmost[i+1] - leftmost[i] - 1);
    
        cout<<ans<<endl;

    }
    return 0;
}