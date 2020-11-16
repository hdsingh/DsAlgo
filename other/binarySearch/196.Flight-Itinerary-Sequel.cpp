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

// For an eulerian path to exist atmost 1 vertex has out-in = 1 and at most 1 has in-out=1
class Solution0 {
public:
    vector<string> solve(vector<vector<string>>& flights) {
        unordered_map<string, int> indeg, outdeg;
        unordered_map<string, multiset<string>> adj;
        for(auto ed: flights){
            outdeg[ed[0]]++; indeg[ed[1]]++;
            adj[ed[0]].insert(ed[1]);
        }
        string start, end;
        // eulerian path
        for(auto& [st, ad_cities]: adj){
            if(abs(outdeg[st]-indeg[st])>1)     
                return {};
            
            if(outdeg[st] - indeg[st]==1){
                if(start.empty()) start = st;
                else return {};
            }
            else if(indeg[st] - outdeg[st]==1){
                if(end.empty()) end = st;
                else return {};
            }
        }
        // If all indeg==outdeg, eulerian circuit exist(both start and end are same)
        if(start.empty()){
            for(auto& [st, ad_cities]: adj){
                if(start.empty() || st<start)
                    start = st;
            }
        }
        
        vector<string> order;
        dfs(start, order, adj);
        reverse(order.begin(), order.end());
        return order;
    }
    
    void dfs(string start, vector<string> &order, unordered_map<string, multiset<string>> &adj){
        while(!adj[start].empty()){
            string next = *adj[start].begin();
            adj[start].erase(adj[start].begin());
            dfs(next, order, adj);
        }
        order.push_back(start);
    }
};

class Solution {
public:
    vector<string> solve(vector<vector<string>>& flights) {
        unordered_map<string, int> indeg, outdeg;
        unordered_map<string, vector<string>> adj;
        for(auto ed: flights){
            outdeg[ed[0]]++; indeg[ed[1]]++;
            adj[ed[0]].push_back(ed[1]);
        }
        string start, end;
        // eulerian path
        for(auto &[st, ad_cities]: adj){
            if(abs(outdeg[st]-indeg[st])>1)     
                return {};
            
            if(outdeg[st] - indeg[st]==1){
                if(start.empty()) start = st;
                else return {};
            }
            else if(indeg[st] - outdeg[st]==1){
                if(end.empty()) end = st;
                else return {};
            }

            // smallest at end since we are using outdeg;
            sort(adj[st].begin(), adj[st].end(), greater<string>());
        }
        // If all indeg==outdeg, eulerian circuit exist(both start and end are same)
        if(start.empty()){
            for(auto& [st, ad_cities]: adj){
                if(start.empty() || st<start)
                    start = st;
            }
        }

        vector<string> order;
        dfs(start, order, adj, outdeg);
        reverse(order.begin(), order.end());
        return order;
    }
    
    void dfs(string start, vector<string> &order, unordered_map<string, vector<string>> &adj, unordered_map<string, int> &outdeg){
        while(outdeg[start]>0){
            string next = adj[start][--outdeg[start]];
            dfs(next, order, adj, outdeg);
        }
        order.push_back(start);
    }
};


vector<string> solve(vector<vector<string>>& flights) {
    Solution0 sol; return sol.solve(flights);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vs> flights;
    flights = {
        {"ABA", "TID"},
        {"TID", "XQU"},
        {"XQU", "IVC"},
        {"IVC", "YXL"}
    };

flights = {
    {"QJY", "EGM"},
    {"EGM", "AOI"},
    {"AOI", "EGM"},
    {"HTA", "QJY"},
    {"EGM", "EGM"}
};
    vs out =  solve(flights); print(out);

    return 0;
}