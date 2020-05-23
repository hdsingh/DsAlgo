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

int n, t;

const int nax = 200;
vector<double> glass(nax);

void dfs(int g, int l){
    if(l>n) return;

    if(glass[g]>1){
        double half = (glass[g]-1)/2;
        glass[g] = 1;

        int c1 = (g+l);
        int c2 = (g+l+1);
        glass[c1]+=half;
        glass[c2]+=half;

        if(glass[c1]>1)
            dfs(c1,l+1);

        if(glass[c2]>1)
            dfs(c2,l+1);
    }
}

void bfs(){
    set<int> q;
    if(glass[1]>1) q.insert(1);
    int l = 1;

    while(!q.empty()){
        if(l>10) break;
        set<int> nq;
        for(auto top: q){
            double half = (glass[top]-1)/2;
            glass[top] = 1;

            int c1 = (top+l);
            int c2 = (top+l+1);
            glass[c1]+=half;
            glass[c2]+=half;

            if(glass[c1]>1) nq.insert(c1);
            if(glass[c2]>1) nq.insert(c2);
        }
        q = nq;
        ++l;
    }

}

int main(){
    while(cin>>n>>t){
        glass.clear(); glass.resize(nax);
        forn(i,t){
            glass[1]+=1;
            bfs();
            // dfs(1,1);
        }

        int ed = (n*(n+1))/2;
        int cnt = 0;
        fore(i,1,ed+1)
            if(glass[i]>=1)
                ++cnt;

        cout<<cnt<<endl;
    }
    return 0;
}