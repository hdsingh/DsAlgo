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

// Ref: https://www.youtube.com/watch?v=o7278rPg_9I
// sum

int n;
int nax = 10;
vi a(nax);
// use actual constant number for block size instead of computing
const int SZ = (int) sqrt (nax + .0) + 1; // size of the block and the number of blocks
vi save(SZ); // saved preprocessed ans (bucket)

void preprocess(){
    for(int i=0; i<n; ++i)
        save[i/SZ]+=a[i];
}

int getSum(int l, int r){
    int lb = l/SZ;
    int rb = r/SZ;
    int sum  = 0;

    if(lb==rb){
        for(int i=l; i<=r; ++i)
            sum+=a[i];
    }else{
        // begin incomplete block range
        for(int i=l; i<(lb+1)*SZ; ++i)
            sum+=a[i];
        
        // over the precomputed blocks
        for(int i=lb+1; i<rb; ++i)
            sum+=save[i];
        
        // last incomplete block range
        for(int i=SZ*rb; i<=r; ++i)
            sum+=a[i];
    }

    return sum;
}

int update(int pos, int val){
    save[pos/SZ]-=a[pos];
    a[pos] = val;
    save[pos/SZ]+=val;
}

int main(){
    n = 8;
    a = {0,1,2,3,4,5,6,7};
    preprocess();
    deb(getSum(4,7));
    deb(getSum(1,4));
    update(3,10);
    deb(getSum(1,4));

    return 0;
}