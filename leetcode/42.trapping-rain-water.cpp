#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        if(n<=2) return 0;
        int ans = 0;
        
        int lt = 0, rt = n-1, lmax = 0, rmax = 0;
        while(lt<rt){
            if(arr[lt]<arr[rt]){
                lmax = max(lmax, arr[lt]);
                ans+=lmax-arr[lt];
                ++lt;
            }else{
                rmax = max(rmax, arr[rt]);
                ans+=rmax-arr[rt];
                --rt;
            }
        }
    
        return ans;
    }
};

class Solution1 {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        if(n<=2) return 0;
        int ans = 0;
        
        vector<int> rmax(n);
        rmax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; --i)
            rmax[i] = max(rmax[i+1], arr[i]);

        int lmax = 0;
        for(int i=0; i<n; ++i){
            lmax = max(lmax, arr[i]);
            int mn = min(lmax, rmax[i]);
            ans+=(mn-arr[i]);
        }

        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}