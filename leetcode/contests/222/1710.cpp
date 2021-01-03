#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& a, int mx) {
        int ans = 0;
        sort(a.begin(), a.end(), [&](vector<int> &v1, vector<int> &v2){
            return v1[1]>v2[1];
        });
        for(auto box: a){
            int cnt = min(box[0],mx), units = box[1];
            mx-=cnt;
            ans+=cnt*units;
        }
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}