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

const int nax = 1e6+10;
vi st(nax*4); // st[i] will store the count of ith element
int n,q;

void update(int pos, int l, int r, int i, int inc){
    st[pos]+=inc;
    if(l==r) return;
    int mid = (l+r)/2;
    if(i<=mid) update(2*pos, l, mid, i, inc);
    else update(2*pos+1,mid+1, r, i, inc);
}

int find_kth(int pos, int l, int r, int k){
    if(l==r) return l;
    int mid = (l+r)/2;
    if(st[2*pos]>=k) return find_kth(2*pos,l, mid, k);
    return find_kth(2*pos+1,mid+1,r, k - st[2*pos]);
}

void find_any(int pos, int l, int r){
    if(st[pos]==0){
        cout<<0<<endl;
        return;
    }
    if(l==r){
        cout<<l<<endl;
        return;
    }
    int mid = (l+r)/2;
    if(st[2*pos]) find_any(2*pos,l,mid);
    else find_any(2*pos+1,mid+1,r);
}

int main(){
    scanf("%d %d", &n, &q);
    int x;
    forn(i,n){
        scanf("%d ", &x);
        update(1,1,n,x,1);
    }

    while(q--){
        scanf("%d ", &x);
        if(x<0){
            int val = find_kth(1,1,n,-x);
            update(1,1,n,val,-1);
        }else{
            update(1,1,n,x,1);
        }
    }

    find_any(1,1,n);

    return 0;
}