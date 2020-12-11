#include <bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int>>& lists) {
    int n = lists.size();
    unordered_map<int, vector<pair<int,int>>> adj; // {{ad, p}}
    for(auto list: lists){
        int st = list[0]-1, ed = list[1], p = list[2];
        adj[st].push_back({ed,p});
        adj[ed].push_back({st,p});
    }

    bool good = true;
    unordered_map<int,int> cols;
    for(auto &[node, _]: adj){
        if(cols.count(node)) continue;
        queue<int> q;
        q.push(node);
        cols[node] = 0;
        
        while(!q.empty()){
            int top = q.front(); q.pop();
            for(auto [ad, p]: adj[top]){
                if(!cols.count(ad)){
                    cols[ad] = cols[top]^p;
                    q.push(ad);
                }else{
                    good&=(cols[ad]==(cols[top]^p));
                }
            }
        }
    }

    return good;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}