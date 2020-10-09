#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<string> vs;

class Hashs{
    int n;
    const int p = 31;
    const int m = 1e9 + 9;
    vl h, p_pow;
public:
    Hashs(string &s){
        n = s.size();
        p_pow.assign(n+1,0); h.assign(n+1,0);
        p_pow[0] = 1;
        for(int i=1; i<n; ++i)
            p_pow[i] = (p_pow[i-1]*p)%m;
        
        for(int i=0; i<n; ++i)  
            h[i+1] = (h[i] + (s[i]-'a'+1)*p_pow[i])%m;
    }

    ll find(int l, int r){
        ll cur = (h[r+1] - h[l] + m)%m;
        return (cur*p_pow[n-1-l])%m;
    }
};

int main(){
    
    return 0;
}

// https://leetcode.com/problems/distinct-echo-substrings/
// https://leetcode.com/problems/longest-duplicate-substring/
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
