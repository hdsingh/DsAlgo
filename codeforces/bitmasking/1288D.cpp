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

int n,m;
vvi a;
int I, J;

bool can1(int mid){
    vi mask(1<<m, -1);
    forn(i,n){
        int cur = 0;
        forn(j,m){
            if(a[i][j]>=mid)
                cur ^= (1<<j);
        }
        mask[cur] = i;
    }

    if(mask[(1<<m)-1]!=-1){
        I = J = mask[(1<<m)-1];
        return true;
    }

    forn(i,(1<<m)){
        forn(j,(1<<m)){
            if(mask[i]!=-1 && mask[j]!=-1 && (i|j)==(1<<m)-1){
                I = mask[i], J = mask[j];
                return true;
            }
        }
    }

    return false;
}

bool can(int mid)
{
    vector<int> msk(1 << m, -1);
    for(int i = 0; i < n; i++)
    {
        int cur = 0;
        for(int j = 0; j < m; j++)
            if(a[i][j] >= mid)
                cur ^= (1 << j);
        msk[cur] = i;
    }
    if(msk[(1 << m) - 1] != -1)
    {
        I = J = msk[(1 << m) - 1];
        return true;
    }
    for(int i = 0; i < (1 << m); i++)
        for(int j = 0; j < (1 << m); j++)
            if(msk[i] != -1 && msk[j] != -1 && (i | j) == (1 << m) - 1)
            {
                I = msk[i];
                J = msk[j];
                return true;
            }
    return false;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    a.resize(n,vi(m));
    forn(i,n){
        forn(j,m)
            cin>>a[i][j];
    }

    int l = 0, r = 1e9 + 43;
    while(1+l<r){
        int m = l + (r-l)/2;
        if(can(m))
            l = m;
        else 
            r = m;
    }

    assert(can(l));
    cout<<I+1<<" "<<J+1<<endl;

    return 0;
}