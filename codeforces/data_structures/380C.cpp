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

const int inf = 1e9;
string s;

struct node {
    int tot = 0, open =0, close = 0;
    // node(int t, int o, int c): tot(t), open(o), close(c) {}
};

class SegmentTree {
    int n;
    vector<node> st;

    node make_node(int t, int o, int c){
        node res;
        res.tot = t; res.open = o, res.close = c;
        return res;
    }

public:
    SegmentTree() {
        n = s.size();
        if(!n) return;

        int max_size = 4*n;
        st.clear(); st.resize(max_size);
        build(1,0,n-1);
    }

    void merge(node &cur, node l, node r){
        int temp = min(l.open, r.close);
        cur.tot = l.tot + r.tot + temp;
        cur.open = l.open + r.open - temp;
        cur.close = l.close + r.close - temp;
    }

    void build(int pos, int l, int r){
        if(l==r){
            int o = (s[l]=='(');
            int c = (s[l]==')');
            st[pos] = make_node(0,o,c);
            return;
        }
        int mid = (l+r)/2;
        build(2*pos,l,mid);
        build(2*pos+1,mid+1,r);
        merge(st[pos] ,st[2*pos] , st[2*pos+1]);
    }
    
    node query(int i, int j, int pos, int l, int r) {
        if(i>r || l>j) return make_node(0,0,0);
        if(i<=l && r<=j) return st[pos];
        int mid = (l+r)/2;
        node left = query(i,j,2*pos,l,mid);
        node right = query(i,j,2*pos+1,mid+1,r);
        node cur = make_node(0,0,0);
        merge(cur, left, right);
        return cur;
    }

    int query(int i,int j){
        node q = query(i,j,1,0,n-1);
        return q.tot;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    SegmentTree st;
    int m, l,r;
    cin>>m;
    while(m--){
        cin>>l>>r;
        --l,--r;
        cout<<2*st.query(l,r)<<endl;
    }

    return 0;
}