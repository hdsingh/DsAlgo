#include <bits/stdc++.h>
using namespace std;

// Hierholzer's algorithm
// add a node only in the end after all adj have been visited
//       2
//       A 
//      | \
//  0 -> 1  -> 3 -> 4
// do dfs 0->1->3->4  , stuck at 4 so add it
// [3,4]
// at 1, 2 is unvisited so go to 2 -> 1
// add 1, 2 , 1, 0
// hence 0, 1, 2, 1, 3, 4

class Solution {
    map<string, multiset<string>> adj;
    vector<string> path;
public:
    vector<string> findItinerary(vector<vector<string>>& edges) {
        for(auto &ed: edges)
            adj[ed[0]].insert(ed[1]);
        
        dfs("JFK");
        reverse(path.begin(), path.end());
        return path;
    }
    
    void dfs(string node){
        while(adj[node].size()){
            auto top = adj[node].begin();
            string ad = *top;
            adj[node].erase(top);
            dfs(ad);
        }
        path.push_back(node);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}