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

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}


const int big = 1e9+7;


class Solution {
public:
    int numWays(int steps, int arrLen) {
        int index_sz = min(steps/2+1, arrLen);
        vvi memo(steps+1, vi(index_sz, -1));

        int out = findWays(0, steps, arrLen, memo);
        // print_vv1(memo);
        return out;
    }

    long findWays(int index, int steps, int &arrLen, vvi &memo){
        if(index==0 && steps==0) return 1;
        if(index<0 || index>=arrLen || steps<0 || index>steps) return 0;

        if(memo[steps][index]!=-1) return memo[steps][index];
        long stay = findWays(index,steps-1, arrLen, memo);
        long left = findWays(index-1,steps-1, arrLen, memo);
        long right = findWays(index+1,steps-1, arrLen, memo);
        long out = (stay+left+right)%big;
        return memo[steps][index] = out;
    }
};
// @lc code=end
int main(){
    Solution sol;
    cout<<sol.numWays(10,10)<<endl;
    cout<<sol.numWays(2,4)<<endl;
    cout<<sol.numWays(4,2)<<endl;
    cout<<sol.numWays(4,3)<<endl;
    cout<<sol.numWays(7,21)<<endl;
    cout<<sol.numWays(500,969997)<<endl;
}
