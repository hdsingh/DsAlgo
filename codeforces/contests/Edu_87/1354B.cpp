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

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; string s;
    cin>>t;
    while(t--){
        cin>>s;
        map<char,int> cnt;
        for(auto x: s)  
            cnt[x]++;
        if(cnt['1']==0 || cnt['2']==0 || cnt['3']==0){
            cout<<0<<endl;
            continue;
        }
        int n = s.size();
        vvi pos(4);
        vvi apos(4);
        forn(i,n){
            if(i<n-2 && s[i]!=s[i+1])
                pos[s[i]-'0'].pb(i);

            apos[s[i]-'0'].pb(i);
        }

        // print_vv(pos);
        // print_vv(apos);

        int min_len = INT_MAX;

        fore(i,1, 4){
            for(auto x: pos[i]){
                int c = s[x] - '0';
                int nc = s[x+1] - '0';
                int req = 6 - c - nc;
                auto it = lower_bound(all(apos[req]),x+1);
                if(it!=apos[req].end()){
                    int len = *it - x + 1;
                    min_len = min(min_len, len);

                }
                if(min_len==3) break;
            }
        }

        cout<<min_len<<endl;
    }
    return 0;
}