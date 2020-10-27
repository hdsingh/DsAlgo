#include <bits/stdc++.h>
using namespace std;

class Fancy {
    const int mod = 1e9+7;
    vector<array<int,3>> arr;
    int rsum, rmul; // running sum, running prod
public:
    Fancy() {
        rsum = 0, rmul = 1;
    }
    
    void append(int val) {
        arr.push_back({val,rsum, rmul});
    }
    
    void addAll(int inc) {
        rsum = rsum + inc;
        if(rsum>=mod) rsum-=mod;
    }
    
    void multAll(int m) {
        rsum = (long)rsum*m%mod;
        rmul = (long)rmul*m%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=arr.size()) return -1;
        auto [val, psum, pmul] = arr[idx];
        long long ratio = (long)rmul * powmod(pmul, mod-2)%mod;
        return (ratio*(val-psum+mod)%mod + rsum)%mod;    
    }
private:
    int powmod(long n, int p){
        long ans = 1;
        while(p>0){
            if(p&1) 
                ans = (ans*n)%mod;
            n = (n*n)%mod;
            p>>=1;
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}