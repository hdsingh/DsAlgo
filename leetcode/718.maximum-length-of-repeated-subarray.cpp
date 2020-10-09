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
    Hashs(vi &s){
        n = s.size();
        p_pow.assign(n+1,0); h.assign(n+1,0);
        p_pow[0] = 1;
        for(int i=1; i<n; ++i)
            p_pow[i] = (p_pow[i-1]*p)%m;
        
        for(int i=0; i<n; ++i)  
            h[i+1] = (h[i] + (s[i]+1)*p_pow[i])%m;
    }

    ll find(int l, int r){
        ll cur = (h[r+1] - h[l] + m)%m;
        return (cur*p_pow[n-1-l])%m;
    }
};

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.size()<B.size()) swap(A,B);
        int n = A.size(), m = B.size();
        
        Hashs a_hash(A), b_hash(B);

        auto are_equal = [&](int ai, int bi, int len){
            for(int i=0; i<len; ++i)
                if(A[i+ai]!=B[i+bi])
                    return false;
            return true;
        };

        auto can = [&](int len){
            map<ll,vector<int>> seen;
            for(int i=0; i+len<=n; ++i){
                seen[a_hash.find(i,i+len-1)].push_back(i);
            }
            
            for(int i=0; i+len<=m; ++i){
                int hash = b_hash.find(i, i+len-1);
                if(seen.count(hash)){
                    for(auto pos: seen[hash]){
                        if(are_equal(pos, i, len))
                            return 1;
                    }
                }
            }
            
            return 0;
        };
        
        int lt = 0, rt = m+1;

        while(1+lt<rt){
            int mid = lt + (rt-lt)/2;
            if(can(mid)){
                lt = mid;
            }else
                rt = mid;
        }

        return lt;
    }
};

class Solution0 {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        int ans = 0;

        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=n-1; i>=0; --i){
            for(int j=m-1; j>=0; --j){
                if(A[i]==B[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        
        return ans;    
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vi A, B; int out;
    A = {1,2,3,2,1}, B = {3,2,1,4,7};
    A = { 0,0,0,0,1 }; B = { 1,0,0,0,0 };
    out =  sol.findLength(A, B); cout<<out<<"\n";
    return 0;
}