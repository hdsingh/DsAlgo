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
typedef pair<ll, ll> pll;
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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

bool solve(){
    auto check = [](vl b){
        int n = b.size();
        fore(i,1,n){
            if(b[i-1]>b[i]) return false;
            b[i]-=b[i-1];
        }
        return (b[n-1]==0);
    };


    int n; cin>>n;
    vl a(n);
    forn(i,n) cin>>a[i];
    // print(a);
    if(check(a)) return 1;

    swap(a[0], a[1]);
    if(check(a)) return 1;
    swap(a[0], a[1]);

    swap(a[n-2], a[n-1]);
    if(check(a)) return 1;
    swap(a[n-2], a[n-1]);

    vl p(n), s(n);
    vl b = a;

    p[0] = b[0];
    fore(i,1,n){
        if(p[i-1]==-1 || b[i-1]>b[i]){
            p[i] = -1;
        }else{
            b[i]-=b[i-1];
            p[i] = b[i];
        }
    }
    
    b = a;
    s[n-1] = b[n-1];
    for(int i=n-2; i>=0; --i){
        if(s[i+1]==-1 || b[i+1]>b[i]){
            s[i] = -1;
        }else{
            b[i]-=b[i+1];
            s[i] = b[i];
        }
    }

    for(int i=1; i<n-2; ++i){
        if(p[i-1]==-1 || s[i+2]==-1){
            continue;
        }else{
            vl c = {p[i-1], a[i+1], a[i], s[i+2]};
            if(check(c)) return 1;   
        }
    }
    
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cout<<(solve() ? "YES\n" : "NO\n");
    }
    return 0;
}