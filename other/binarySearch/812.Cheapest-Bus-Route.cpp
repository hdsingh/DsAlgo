#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> tii;

const int inf = 1e9;
int solve(vector<vector<int>>& cons) {
    int end = 0;
    for(auto x: cons){
        end = max(end,max(x[0], x[1]));
    }
    vector<vector<pair<int,int>>> adj(end+1); // {cost,node,id_of_bus by which reached here}
    for(auto con: cons){
        int st = con[0], ed = con[1], id = con[2];
        adj[st].push_back({ed, id});
    }
    
    int ans = inf;
    vector<unordered_set<int>> vis(end+1); // {node, id} // edges tracker
    deque<tii> pq; // {cost, node, id};
    pq.push_back({0,0,-1});
    
    while(!pq.empty()){
        auto [prev_cost, node, prev_id] = pq.front(); pq.pop_front();
        vis[node].insert(prev_id);
        if(node==end) return prev_cost;

        for(auto [ad_node, id]: adj[node]){
            if(vis[ad_node].count(id)) continue;
            if(id==prev_id)
                pq.push_front({prev_cost, ad_node, id});
            else
                pq.push_back({prev_cost+1,ad_node,id});
        }
    }

    if(ans==inf) return  -1;
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}