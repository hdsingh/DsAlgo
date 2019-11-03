#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        
        int n = a.size();
        vector<int> sums(n+1, 0);
        for(int i=1; i<=n; i++)
            sums[i] += sums[i-1] + a[i-1]%2;
        
        int out = 0;
        for(int i=0; i<n; i++){
            auto it = equal_range(sums.begin(), sums.end(), sums[i]+k);
            out+= it.second - it.first;
        }
        
        return out;

    }
};

int main(){
    Solution s;
    vi a = {2,2,2,1,2,2,1,2,2,2};
    a = {1,1,2,1,1};
    a = {};
    cout<<s.numberOfSubarrays(a, 2);
    return 0;
}