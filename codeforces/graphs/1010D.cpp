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

struct node{
    char type;
    int val = 0, bad=0, c1=0, c2=0;
};


// Idea: Keep on marking the nodes as bad, till they can affect the res
// An input node is bad if all the nodes from it to root are bad.
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<node> a(n+1);
    fore(i,1,n+1){
        string s; cin>>s;
        a[i].type = s[0];
        if(a[i].type=='I'){
            cin>>a[i].val;
        }else if(a[i].type=='N'){
            cin>>a[i].c1;
        }else{
            cin>>a[i].c1>>a[i].c2;
        }
    }

    function<void(int)> dfs = [&](int root){
        if(a[root].type=='I'){
            return;
        }else if(a[root].type=='N'){
            int c1 = a[root].c1;
            dfs(c1);
            a[root].val = !a[c1].val;
        }else if(a[root].type=='A'){
            int c1 = a[root].c1, c2 = a[root].c2;
            dfs(c1); dfs(c2);
            a[root].val = (a[c1].val&a[c2].val);
        }else if(a[root].type=='X'){
            int c1 = a[root].c1, c2 = a[root].c2;
            dfs(c1); dfs(c2);
            a[root].val = (a[c1].val^a[c2].val);
        }else if(a[root].type=='O'){
            int c1 = a[root].c1, c2 = a[root].c2;
            dfs(c1); dfs(c2);
            a[root].val = (a[c1].val|a[c2].val);
        }
    };


    function<void(int)> dfs2 = [&](int root){
        a[root].bad = 1;
        if(a[root].type =='I') return;

        if(a[root].type=='N'){
            int c1 = a[root].c1;
            dfs2(c1);
        }else{
            int c1 = a[root].c1, c2 = a[root].c2;
            if(a[root].type=='A'){
                if(a[c1].val==1) dfs2(c2);
                if(a[c2].val==1) dfs2(c1);
            }else if(a[root].type=='O'){
                if(a[c1].val==0) dfs2(c2);
                if(a[c2].val==0) dfs2(c1);
            }else if(a[root].type=='X'){
                dfs2(c1); dfs2(c2);
            }
        }
    };  

    dfs(1);
    dfs2(1);

    fore(i,1,n+1){
        if(a[i].type=='I'){
            cout<<(a[1].val^a[i].bad);
        }
    }
    cout<<"\n";
    
    return 0;
}