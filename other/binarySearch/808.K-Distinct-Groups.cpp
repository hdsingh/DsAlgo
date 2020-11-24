#include <bits/stdc++.h>
using namespace std;

bool can(int G, vector<int> &counts, int K){
    int tot = 0;
    // Since each count of each element we are including is<=G
    // So we can always make an arrrangement where there is only
    // 1 element of each type in a single group
    for(auto x: counts){
        tot+=min(G,x);
    }
    // in the end we check if total groups possible with the size K>=G 
    return (tot/K)>=G;
}

int solve(vector<int>& counts, int k) {
    int lt = 0, rt = accumulate(counts.begin(), counts.end(),0)+1;
    while(1+lt<rt){
        int mid = lt + (rt-lt)/2;
        if(can(mid,counts,k)){
            lt = mid;
        }else 
            rt = mid;
    }
    return lt;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}