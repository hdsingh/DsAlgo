#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        vector<bool> found(n);
        for(auto piece: pieces){
            for(int i=0; i+(int)piece.size()<=n; ++i){
                bool ok = 1;
                for(int j=0; j<(int)piece.size(); ++j){
                    if(arr[i+j]!=piece[j]){
                        ok = false;
                        break;
                    }
                }
                
                if(ok){
                    for(int j=0; j<(int)piece.size(); ++j)
                        found[i+j] = 1;
                }
            }
        }
        
        bool ok = 1;
        for(int i=0; i<n; ++i){
            ok&=found[i];
        }
        return ok;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}