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
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int ra = toBeRemoved[0];
        int rb = toBeRemoved[1];

        vector<vector<int>> out;

        for(auto ival: intervals){
            int a = ival[0];
            int b = ival[1];

            if(ra<=a && b<rb)
                continue;
            else if(a<=ra && rb<b){
                out.push_back({a,ra});
                out.push_back({rb,b});
            }
            else if(a<=ra)
                out.push_back({a,ra});
            else if(rb<b)
                out.push_back({rb,b});
            else
                out.push_back({a,b});
        }
        return out;
    }
};

int main(){
    Solution sol;
    vvi intervals; vi toBeRemoved;  
    intervals = {{0,5}}, toBeRemoved = {2,3};
    // intervals = {{0,2},{3,4},{5,7}}, toBeRemoved = {1,6};
    vvi out = sol.removeInterval(intervals,toBeRemoved);
    print_vv(out);
    return 0;
}