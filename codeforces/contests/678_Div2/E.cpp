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


const int inf = 1e9+10;

struct node{
    int val;
    node(){};
    node(int V): val(V) {};
};

class SegmentTree{
public:
    int n;
    vector<node> st;

    SegmentTree(vi &a){
        n = sz(a);
        st.resize(4*n,-1);
    }

    void merge(node &cur, node &l, node &r){
        cur.val = min(l.val, r.val);   
    }

    node query(int pos, int sl, int sr, int l, int r){
        if(sr<l || r<sl) return node(inf);
        else if(l<=sl && sr<=r) return st[pos];
        int mid = (sl+sr)/2;
        node left = query(2*pos, sl, mid, l, r);
        node right = query(2*pos+1, mid+1, sr, l, r);
        node cur;
        merge(cur, left, right);
        return cur;
    }

    void update(int pos, int sl, int sr, int i, int &val){
        if(sl==sr){
            st[pos] = node(val);
            return;
        }
        int mid = (sl + sr)/2;
        if(i<=mid) 
            update(2*pos, sl, mid, i, val);
        else 
            update(2*pos+1, mid+1, sr, i, val);
        merge(st[pos], st[2*pos], st[2*pos+1]);
    }

    int query(int l, int r){
        return query(1,0,n-1, l, r).val;
    }

    void update(int i, int val){
        update(1,0,n-1,i,val);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n){
        vi a(n); forn(i,n) cin>>a[i];
        set<int> mexs;
        fore(i,1,n+3) mexs.insert(i);

        vi last(n+2,-1);
        SegmentTree st(last);
        forn(i,n){
            if(a[i]==1){
                mexs.erase(2);
            }else{
                mexs.erase(1); // for single digit.
                int minIdx = st.query(1,a[i]-1);
                if(minIdx>last[a[i]])
                    mexs.erase(a[i]);
            }
            st.update(a[i],i);
            last[a[i]] = i;
        }

        fore(i,2,n+2){
            int minIdx = st.query(1,i-1);
            if(minIdx>last[i])
                mexs.erase(i);
        }
        cout<<*mexs.begin()<<"\n";
    }
    return 0;
}