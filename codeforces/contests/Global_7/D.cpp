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

int n; string s;

string find(int l, int r){
    string L, R;
    while(l<=r && s[l]==s[r]){
        L+=s[l]; R = s[r] + R;
        if(l==r) L.pop_back();
        l++; r--;
    }
    if(l>r){
        return L + R;
    }
    return "";
}

string find_lt(int b, int e){
    string out;
    vi pos;
    for(int i=e; i>=b; --i)
        if(s[i]==s[b]) pos.push_back(i);
    
    for(auto x: pos){
        out = find(b, x);
        if((int)out.size()) return out;
    }

    return "";
};

string find_rt(int b, int e){
    vi pos;
    for(int i=b; i<=e; ++i)
        if(s[i]==s[e]) pos.push_back(i);
    
    for(auto x: pos){
        string out = find(x,e);
        if((int)out.size()) return out;
    }
    return "";
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>s;
        n = s.size();

        string B, E;
        int b = 0, e = n-1;
        while(b<=e && s[b]==s[e]){
            B+=s[b]; E = s[e] + E;
            if(b==e) B.pop_back();
            ++b, --e;
        }

        if(b<e){
            string lt = find_lt(b,e);
            string rt = find_rt(b,e);
            if((int)lt.size()>(int)rt.size()){
                B+=lt;
            }else
            {
                E = rt + E;
            }
        }

        cout<<B<<E<<endl;
    }    
    return 0;
}