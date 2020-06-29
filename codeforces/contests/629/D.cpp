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
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

// 1. If there are odd grps and front!=back
//     i. in case a seq of len 2 is present, we can adjust the colors
//     ii. else use 3 colors (3 at end)
// 2. all other cases use 1 or 2
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n; cin>>n;
        vi a(n); forn(i,n) cin>>a[i];
        int grps = 0; bool has_len2 = false;
        for(int i=0; i<n; ++i){
            int j = i;
            while(j+1<n && a[j+1]==a[i]){
                ++j;
            }
            ++grps;
            has_len2|=(j-i+1 >=2);
            i = j;
        }

        vi ans(n); int col = 0;
        if(grps%2==1 && a.front()!=a.back()){
            if(has_len2){
                bool found = false;
                for(int i=0; i<n; ++i){
                    int j = i;
                    ans[i] = col+1;
                    while(j+1<n && a[j+1]==a[i]){
                        ans[j+1] = col+1;
                        ++j;
                    }
                    if(!found && j-i+1>=2){
                        col^=1;
                        ans[j] = col+1; 
                        found = true;
                    }
                    col^=1;
                    i = j;
                }
            }else{
               for(int i=0; i<n; ++i){
                    int j = i;
                    ans[i] = col+1;
                    while(j+1<n && a[j+1]==a[i]){
                        ans[j+1] = col+1;
                        ++j;
                    }
                    col^=1;
                    i = j;
                }
                ans[n-1] = 3;
            }
        }else{
            for(int i=0; i<n; ++i){
                int j = i;
                ans[i] = col+1;
                while(j+1<n && a[j+1]==a[i]){
                    ans[j+1] = col+1;
                    ++j;
                }
                col^=1;
                i = j;
            }
        }    

        int mx = *max_element(all(ans));
        cout<<mx<<"\n";
        // print(a,1);
        print(ans);

    }
    return 0;
}