#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> a(n+10);
        a[1] = 1;
        for(int i=2; i<=n; ++i){
            if(i&1){
                a[i] = a[i/2] + a[(i/2)+1];
            }else{
                a[i] = a[i/2];
            }
        }
        int mx = 0;
        for(int i=0; i<=n; ++i) 
            mx = max(mx, a[i]);
        return mx;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    return 0;
}