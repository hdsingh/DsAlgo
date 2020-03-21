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

// There is no direct way possible so we will do binary search on the 
// values of x, here x represents if the array could be made non-dec in x turns
// here the first value could be 0, if it could be turned to 0 in under x turns
// else it would stay the same. 
// case 1. 
// prev<=a[i] : if a[i] could be conveted to prev in under x turns then its okay
// else we change the prev to x bec, there is chance that we have more eq, inc elements ahead
// else if prev>a[i] and then it distrupts the non-dec nature of seq and we check if it could be convetered
// to prev in desired steps, else it is not possible for cur value of x and we increment the value of x


int n,m;
vi a;

bool check(int x){
    int prev = 0;
    for(auto num: a){
        if(prev<=num){
            int k = m + prev - num; // ex: prev = 3, num = 5, mod = 6->  5->3 will require 4 moves (5->0->1->2->3)
            if(k>x)
                prev = num;
        }else{
            int k = prev - num;
            if(k>x) return false;
        }
    }
    return true;
}

int main(){
    
    while(cin>>n>>m){
        a.clear(); a.resize(n);
        forn(i,n) cin>>a[i];

        int l = 0, r = m;
        while(r-l>1){
            int mid = l + (r-l)/2;
            if(check(mid))
                r = mid;
            else 
                l = mid + 1;
        }
        if(check(l))
            cout<<l<<endl;
        else 
            cout<<r<<endl;
    }

    return 0;
}