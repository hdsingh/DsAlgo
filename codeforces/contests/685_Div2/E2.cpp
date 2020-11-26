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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

const vi sol = {9,6, 12, 15, 5, 14, 0, 2, 8, 7, 10, 11, 1, 4, 13, 3};

void ask(string op, int a, int b, int &val){
    cout<<op<<" "<<a+1<<" "<<b+1<<endl;
    // cin>>val;
    if(op=="AND") val = sol[a]&sol[b];
    if(op=="OR") val = sol[a]|sol[b];
    if(op=="XOR") val = sol[a]^sol[b];
}

// a + b = x
// a + c = y
// b + c = z
tuple<int,int,int> findABC(int x, int y, int z){
    int a = -1, b = -1, c = -1;
    if(x>=y){
        b = (z+x-y);
        assert(b%2==0);
        b/=2;
        a = x-b;
        c = z-b;
    }else{
        c = z + y - x;
        assert(c%2==0);
        c/=2;
        a = y-c;
        b = z-c;
    }
    return {a,b,c};
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int mask = n-1;
    vi out(n);
    vi xrs(n);
    vector<vector<int>> save(n+1);
    bool rep = 0; pii at;
    int same_idx = -1, val = -1;
    fore(i,1,n){
        ask("XOR", 0, i, xrs[i]);
        save[xrs[i]].pb(i);
        if(sz(save[xrs[i]])==2 && !rep){
            rep = true;
            at = {save[xrs[i]][0], save[xrs[i]][1]};
        }
    }
    
    if(rep){
        // same xor i.e same nums
        auto [i,j] = at;
        int ad; // and
        ask("AND",i,j, ad);
        // out[i] = out[j] = ad;
        out[0] = xrs[i]^ad;
        
    }else{
        int x, y, z;
        // all nums are diff
        int i = -1, j = -1;
        fore(temp,2,n){
            fore(k,temp,n){
                if((xrs[temp-1]^xrs[k])==mask){
                    i = temp-1, j = k;
                    break;
                }
            }
        }
        assert(i!=-1);
        // aIdx = 0, bIdx = i, cIdx = j
        int xr1 = xrs[i]; int ad;
        ask("AND", 0, i, ad);
        x = xr1 + 2*ad;

        int xr2 = xrs[j];
        ask("AND", 0, j, ad);
        y = xr2 +  2*ad;

        int xr3 = xr1^xr2;
        ad = 0; // (since out[i]^out[j]==mask)
        z = xr3;
        auto [a,b,c] = findABC(x,y,z);
        out[0] = a, out[1] = b, out[2] = c;        
    }
    
    fore(i,1,n){
        out[i] = mask&(xrs[i]^out[0]);
    }

    cout<<"! ";
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
    
    return 0;
}