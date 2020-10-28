#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<pair<int,int>> q; // {time, server_id}
        set<int> free_server;
        for(int i=0; i<k; ++i)
            free_server.insert(i);
        vector<int> handled(k); // reqs handled by a server
        
        for(int i=0; i<n; ++i){
            int start = arrival[i], end = arrival[i] + load[i];
            while(q.size() && q.begin()->first<=start){
                int id = q.begin()->second;
                q.erase(*q.begin());
                free_server.insert(id);
            }
            if(free_server.empty()) continue;
            
            int duty = i%k; // whose turn is this to process the req
            auto pos = free_server.lower_bound(duty);
            int use_now = (pos==free_server.end()) ? *free_server.begin() : *pos;
            
            handled[use_now]++;
            free_server.erase(use_now);
            q.insert({end, use_now});
        }
        
        int mx = *max_element(handled.begin(), handled.end());
        vector<int> out;
        for(int i=0; i<k; ++i){
            if(handled[i]==mx){
                out.push_back(i);
            }
        }
        return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}