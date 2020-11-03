#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& evs) {
        int n = evs.size(); if(!n) return 0;
  		sort(evs.begin(), evs.end(), [&](vector<int> &v1, vector<int> &v2){
            if(v1[0]==v2[0]) return v1[1]>v2[1];
            return v1[0]<v2[0];
        });
        
		vector<int> lis;
        for(int i=0; i<n; ++i){
            auto pos = lower_bound(lis.begin(), lis.end(), evs[i][1]);
            if(pos==lis.end())
                lis.push_back(evs[i][1]);
            else 
                *pos = evs[i][1];
        }
		return lis.size();
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}