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

// Start processign from the bottom,
// The value at node should be divided amoung ch in such a way that
// the max is as min as possible, so find the maxVal child and make other ch equal to it
// if we still have vals left at node, increase the all the ch as equally  as possible. (val/ch) + (val%Ch ? 1 : 0);
// these leaves will in turn acc  as ch for the par above it.
struct square{
    ll val=0, ch=0, mxVal=0, tot = 0;
};

int n;

vector<square> a;
vvi adj;

void dfs(int node, int p){
    for(auto ad: adj[node]){
        if(ad==p) continue;
        dfs(ad, node);
        a[node].tot+=a[ad].tot;
        max_self(a[node].mxVal, a[ad].mxVal);   
        a[node].ch+=a[ad].ch;
    }

    if(a[node].ch==0){
        // leaf
        a[node] = {a[node].val, 1, a[node].val, a[node].val};
        return; 
    }
    ll dif = a[node].mxVal*a[node].ch -  a[node].tot;
    ll val = a[node].val;
    a[node].tot+=val;
    if(val>dif){
        val-=dif;
        a[node].mxVal+=(val/a[node].ch);
        if(val%a[node].ch)
            ++a[node].mxVal;
    }
}

// Brute:
// we don't need all the ch, only count of ch, maxVal, tot is req.
// vl dfs(int node, int p){
//     vl cur;
//     ll tot = 0;
//     for(auto ad: adj[node]){
//         if(ad==p) continue;
//         for(auto val: dfs(ad, node)){
//             cur.pb(val);
//             tot+=val;
//         }
//     }
//     ll C = sz(cur);
//     // deb(node, C);
//     if(C==0){
//         return {a[node]};
//     }
//     sort(all(cur));
//     ll mx = cur.back();
//     ll dif = mx*C - tot;
//     ll val = a[node];
//     if(val<=dif){
//         forn(i,C){
//             ll add = min(mx-cur[i], val);
//             cur[i]+=add; val-=add;
//         }
//     }else{
//         val-=dif;
//         ll nval = mx + (val/C);
//         ll extra = val%C;
//         forn(i,C){
//             cur[i] = nval;
//             if(extra>0){
//                 cur[i]++;
//                 extra--;
//             }
//         }
//     }

//     return cur;
// }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin>>n){
        adj.assign(n+1,{});
        a.assign(n+1,{0,0,0,0});
        fore(i,2,n+1){
            int p; cin>>p;
            adj[p].pb(i);
            adj[i].pb(p);
        }
        fore(i,1,n+1) cin>>a[i].val;
        
        dfs(1,0);
        cout<<a[1].mxVal<<"\n";
    }
    return 0;
}