#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 5;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

class Solution {
public:
    bool dfs(int i, vector<int> &arr, map<int, int> &m){
        if(m[i]!=-1) return m[i];
        m[i] = 0;

        if(arr[i]==0){
            return m[i]= 1;
        }
        
        bool r=0, l=0;
        if(i + arr[i] < arr.size()){
            r = dfs(i+arr[i], arr, m);
        }


        if(i - arr[i]>=0){
            l =  dfs(i-arr[i], arr, m);
        }
        
        if(l||r){
            return m[i] = 1;
        }
        
        return m[i] = 0;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        map<int, int> m;
        for(int i=0; i<n; i++)
            m[i] = -1;
    
        bool out =  dfs(start, arr, m);

        // for(auto a: m)
        //     cout<<a.first<<" : "<<a.second<<endl;
        return out;
        
    }
};

int main(){
    Solution sol;
    vi arr; int start;

    arr = { 4,2,3,0,3,1,2 }; start = 5;
    cout<<sol.canReach(arr,start)<<endl;

    arr = { 4,2,3,0,3,1,2 }; start = 0;
    cout<<sol.canReach(arr,start)<<endl;

    arr = { 3,0,2,1,2 }; start = 2;
    cout<<sol.canReach(arr,start)<<endl;
    
    return 0;
}