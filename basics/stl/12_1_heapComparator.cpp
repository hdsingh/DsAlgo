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

// method 1
struct cmp1{
    bool operator()(const pii &p1, const pii &p2) const{
        int len1 = p1.second - p1.first + 1;
        int len2 = p2.second - p2.first + 1;
        if(len1==len2)
            return p1.first<p2.first;
        return len1>len2;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vi a(n+1);

        int val = 1;

        // method 1
        // set<pii, cmp1> s;

        ///////////////////////////////////
    
        // method 2
        auto cmp = [&](const pii &p1, const pii &p2){
            int len1 = p1.second - p1.first + 1;
            int len2 = p2.second - p2.first + 1;
            if(len1==len2)
                return p1.first<p2.first;
            return len1>len2;
        };

        set<pii, decltype(cmp)> s(cmp);
        s.insert({1,n});

        // /////////////////////////////

        // method 3, for pq, just opposite signs than that of set
        auto cmp = [&](const pii &p1, const pii &p2){
            int len1 = p1.second - p1.first + 1;
            int len2 = p2.second - p2.first + 1;
            if(len1==len2)
                return p1.first>p2.first;
            return len1<len2;
        };
    
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        pq.push({1,n});

        while(!pq.empty()){
            pii top = pq.top(); pq.pop();
            // pii top = *s.begin(); s.erase(s.begin());

            // int len = top.second - top.first + 1;
            // deb(len, top.first, top.second);
            int mid = (top.first + top.second)/2;
            a[mid] = val++;
            int l1,r1,l2,r2;
            l1 = top.first; r1 = mid - 1;
            l2 = mid + 1; r2 = top.second;

            if(l1<=r1) pq.push({l1,r1});
            if(l2<=r2) pq.push({l2,r2});

            // if(l1<=r1) s.insert({l1,r1});
            // if(l2<=r2) s.insert({l2,r2});
        }
        fore(i,1,n+1) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}