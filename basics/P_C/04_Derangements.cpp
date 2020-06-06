#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;

const int mod = 1e9 + 7;

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}

const int nax = 10;
vl D(nax);

void precalcDer(){
    D[0] = 1;
    D[1] = 0;
    D[2] = 1;
    for(int i=3; i<nax; ++i)
        D[i] = (i-1) * (D[i-1] + D[i-2]);
}

int main(){
    precalcDer();
    print(D);
    return 0;
}