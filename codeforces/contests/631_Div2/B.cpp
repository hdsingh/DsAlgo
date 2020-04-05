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

const int nax = 2e5+10;
vi a(nax);
vvi ans(2,vi(2));
int ans_cnt;

bool is_perm(int l, int r, int sz){
    static vi used(nax);
    for(int i=1; i<=sz; ++i) used[i] = 0;
    for(int i=l; i<=r; ++i) used[a[i]] = 1;
    for(int i=1; i<=sz; ++i){
        if(!used[i]) return 0;
    }
    return 1;
}

bool judge(int len1, int n){
    return is_perm(0,len1-1, len1) && is_perm(len1, n-1, n-len1);
}

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        ans_cnt = 0;
        scanf("%d", &n);
        int mx =0;
        forn(i,n){
            scanf("%d", &a[i]);
            if(a[i]>mx) mx = a[i];
        }

        if(judge(n-mx,n)){
            ans[ans_cnt][0] = n-mx;
            ans[ans_cnt++][1] = mx;
        }

        if((mx!=n-mx) && judge(mx,n)){
            ans[ans_cnt][0] = mx;
            ans[ans_cnt++][1] = n-mx;
        }

        printf("%d\n", ans_cnt);
        forn(i,ans_cnt){
            printf("%d %d\n", ans[i][0], ans[i][1]);
        }
    }
    
    return 0;
}