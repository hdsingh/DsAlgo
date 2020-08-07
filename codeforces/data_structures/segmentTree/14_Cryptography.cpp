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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}


int mod, n,m;

const int N = 2; // size of matrix
struct matrix{
    ll arr[N][N];  
    void reset(){
        memset(arr, 0, sizeof(arr));
    }

    void makeIdentity(){
        reset();
        forn(i,N) arr[i][i] = 1;
    }

    matrix operator+(const matrix &oth) const{
        matrix res; 
        forn(i,N) forn(j,N){
            res.arr[i][j] = arr[i][j] + oth.arr[i][j];
            if(res.arr[i][j]>=mod) res.arr[i][j]-=mod;
        }   
        return res;
    }

    matrix operator*(const matrix &oth) const{
        matrix res; res.reset();
        forn(k,N) forn(i,N) forn(j,N){
            (res.arr[i][j]+=arr[i][k]*oth.arr[k][j]%mod)%=mod;
        }
        return res;
    }

    void print(){
        forn(i,N){
            forn(j,N){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
};

matrix pow(matrix a, ll p){
    matrix c; c.makeIdentity();
    while(p){
        if(p&1) c = c*a;
        a = a*a;
        p>>=1;
    }
    return c;
}

matrix I;

class SegmentTree{
public:
    int n; 
    vector<matrix> st;

    SegmentTree(vector<matrix> &a){
        n = sz(a);
        st.resize(4*n);
        build(1, 0, n-1, a);
    }

    void build(int pos, int l, int r, vector<matrix> &a){
        if(l==r){
            st[pos] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*pos, l, mid, a);
        build(2*pos+1, mid+1, r, a);
        st[pos] = st[2*pos] * st[2*pos+1];
    }

    matrix query(int pos, int sl, int sr, int l, int r){
        if(r<sl || sr<l) return I;
        else if(l<=sl && sr<=r) return st[pos];
        int mid = (sl + sr)/2;
        return query(2*pos, sl, mid, l, r) * query(2*pos+1, mid+1, sr, l, r);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    I.makeIdentity();
    cin>>mod>>n>>m;
    vector<matrix> a(n);
    forn(i,n){
        forn(j,2) forn(k,2) cin>>a[i].arr[j][k];
    }

    SegmentTree st(a);
    
    while(m--){
        int l, r; cin>>l>>r; --l, --r;
        matrix res = st.query(1,0,n-1,l,r);
        res.print();
        cout<<"\n";
    }
    
    return 0;
}