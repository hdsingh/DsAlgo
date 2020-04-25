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
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vi row_count(rows, 0);
        vi col_count(cols, 0);
        int tot = 0;

        // find total servers for each row and col
        for(int r=0; r<rows; r++){           
            for(int c=0; c<cols; c++){
                if(grid[r][c])
                    row_count[r]++, col_count[c]++;
            }
        }   


        // check at every point and increment if there is any other server in its row or col,
        // beides itself
        for(int c=0; c<cols; c++){
            for(int r=0; r<rows; r++){
                if(grid[r][c] &&(col_count[c]>1 || row_count[r]>1))
                    tot++; 
            }
        }

        return tot;

    }
};

int main(){
    Solution sol;
    vector<vvi> tests = {
                        {{1,0},{0,1}},
                        {{1,0},{1,1}},
                        {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}},
                        };
    for(auto test: tests)
        cout<<sol.countServers(test)<<endl;
    return 0;
}