#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vi last(26);
        for(int i=0; i<n; ++i) last[s[i]-'a'] = i;
        vi out;
        int cnt = 0;
        for(int i=0; i<n; ++i){
            int l = i;
            int r = last[s[i]-'a'];
            while(r<n && l<=r){
                r = max(r, last[s[l]-'a']);
                ++l;
            }
            out.push_back(r-i+1);
            ++cnt;
            i = r;
        }
        return out;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}