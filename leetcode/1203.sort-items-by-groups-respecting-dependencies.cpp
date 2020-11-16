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

// create topsort order of node and grps
// collect together all items of a same grp acc to the nodeOrder (grpToItems)
// start processing acc to grpOrder and pick items as in grpToItem
// Process acc to grp and then by node
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0; i<n; ++i){
            if(group[i]==-1)
                group[i] = m;
        }
        vector<set<int>> gadj(m+1);
        vector<set<int>> adj(n);
        for(auto node=0; node<n; ++node){
            for(auto item: beforeItems[node]){
                adj[item].insert(node);
                int grp = group[node];
                int othgrp = group[item];
                if(grp==othgrp) continue;
                gadj[othgrp].insert(grp);
            }
        }

        vector<int> grpOrder = topSort(gadj, m+1);
        vector<int> nodeOrder = topSort(adj, n);
        if(grpOrder.empty() || nodeOrder.empty()) return {};
        vector<vector<int>> grpToItem(m+1);
        for(auto node: nodeOrder){
            grpToItem[group[node]].push_back(node);
        }

        vector<int> ans; // first by grp, then by node
        for(auto grp: grpOrder){
            for(auto node: grpToItem[grp]){
                ans.push_back(node);
            }
        }
        
        return ans;
    }
    
    vector<int> topSort(vector<set<int>> &adj, int n){
        vector<int> indeg(n);
        for(int node=0; node<n; ++node){
            for(auto ad: adj[node])
                indeg[ad]++;
        }
        
        queue<int> q;
        for(int node=0; node<n; ++node)
            if(indeg[node]==0)
                q.push(node);
        
        vector<int> order;
        while(!q.empty()){
            int top = q.front(); q.pop();
            order.push_back(top);
            for(auto ad: adj[top]){
                if(--indeg[ad]==0){
                    q.push(ad);
                }
            }
        }
        
        if(order.size()!=n) return {};
        return order;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; int n, m; vi out, group; vvi beforeItems;
    n = 8, m = 2, group = {-1,-1,1,0,0,1,0,-1}, beforeItems = {{},{6},{5},{6},{3,6},{},{},{}};
    out = sol.sortItems(n,m,group, beforeItems); cout<<out;

    return 0;
}