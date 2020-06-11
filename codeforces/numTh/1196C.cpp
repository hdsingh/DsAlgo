#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)

const int inf = 1e5;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; cin>>q;
    while(q--){
        int n, x,y,f1,f2,f3,f4;
        cin>>n;
        int mnx(-inf), mxx(inf), mny(-inf), mxy(inf);
        forn(i,n){
            cin>>x>>y>>f1>>f2>>f3>>f4;
            if(!f1) max_self(mnx, x);
            if(!f2) min_self(mxy, y);
            if(!f3) min_self(mxx, x);
            if(!f4) max_self(mny, y);
        }

        if(mnx<=mxx && mny<=mxy){
            cout<<1<<" "<<mnx<<" "<<mny<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}