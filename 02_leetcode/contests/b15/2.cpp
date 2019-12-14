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

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& ivals) {
        int n = ivals.size();
        int ans = n;
        for(int i=0; i<n; i++){
            int a = ivals[i][0]; int b = ivals[i][1];
            for(int j=0; j<n; j++){
                int c = ivals[j][0]; int d = ivals[j][1];
                if(i!=j && c<=a && b<=d){
                    ans--; break;
                }
                // if(i!=j && ivals[j][0]<=ivals[i][0] && ivals[j][1]<=ivals[i][1])
                //     ans--;
            }
        }
        return ans;

    }
};

         
int main(){
    vvi ival = { { 1,4 },{ 3,6 },{ 2,8 } };
    Solution sol;

    cout<<sol.removeCoveredIntervals(ival)<<endl;

    ival = {{4,5},{5,7},{8,9},{1,3}};
    cout<<sol.removeCoveredIntervals(ival)<<endl;
    // cout<<sol.removeCoveredIntervals(ival);
    return 0;
}