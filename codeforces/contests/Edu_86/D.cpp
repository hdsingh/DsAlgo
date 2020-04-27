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

int n,k,x;
const int nax = 2e5+10;
int cnt[nax], lim[nax];
ll cap[nax];

bool check(int sz){
    fore(i,1,k+1)
        cap[i] = 1LL * lim[i] * sz;
    int val = 0;
    for(int i=k; i>=1; --i){
        val+=cnt[i];
        if(cap[i]<val)
            return 0;
    }
    return 1;
}

int main(){
    while(cin>>n>>k){
        memset(cnt,0,sizeof(cnt));
        memset(lim,0,sizeof(cnt));
        memset(cap,0,sizeof(cap));
        
        fore(i,1,n+1){
            cin>>x; cnt[x]++;
        }
        fore(i,1,k+1)
            cin>>lim[i];
        
        int st = 1;
        int ed = n;
        int ans = n;
        while(st<=ed){
            int mid = (st+ed)/2;
            if(check(mid))
                ans = mid, ed = mid-1;
            else 
                st = mid+1;
        }

        cout<<ans<<endl;

        vvi out(ans);
        int pos = 0;
        for(int i=k; i>=1; --i){
            if(cnt[i]==0) continue;
            
            forn(j,cnt[i]){
                out[pos].push_back(i);
                ++pos;
                if(pos==ans)
                    pos = 0;
            }
        }

        for(auto oo: out){
            int sz = oo.size();
            cout<<sz<<" ";
            for(auto o: oo) cout<<o<<" ";
            cout<<endl;
        }
    }
    return 0;
}