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
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();

        int tot_time = 0;
        for(int i=1; i<n; i++){
            tot_time += max(abs(points[i][0]-points[i-1][0]), abs(points[i][1]-points[i-1][1]));
        }
        return tot_time;
    }
};


int main(){
    Solution sol;
    vector<vvi> points = {{{1,1},{3,4},{-1,0}},
                            {{3,2},{-2,2}},
                            {{1,0}}};
    for(auto point: points)
        cout<<sol.minTimeToVisitAllPoints(point)<<endl;
    return 0;
}