#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int K) {
        int n = code.size();
        vector<int> out(n);
        if(K==0){
            return out;
        }else if(K>0){
            for(int i=0; i<n; ++i){
                for(int k=1; k<=K; ++k){
                    out[i]+=code[(i+k)%n];
                }
            }
        }else{
            for(int i=0; i<n; ++i){
                for(int k=1; k<=-K; ++k){
                    out[i]+=code[(i-k+n)%n];
                }
            }
        }
        return out;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}