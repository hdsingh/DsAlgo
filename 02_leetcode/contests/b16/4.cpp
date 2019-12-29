#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;


template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

const int mod = 1e9+7;
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        board[0][0] = '0'; board[n-1][n-1] = '0';

        vvi score(n+1, vi(n+1)), paths(n+1, vi(n+1));

        vvi dirs = {{1,0}, {0,1}, {1,1}}; //[i-1][j], [i][j-1], [i-1][j-1]
        paths[0][0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(board[i-1][j-1]=='X') continue;
                for(vi d: dirs){
                    int i1 = i-d[0]; int j1 = j-d[1];
                    if(paths[i1][j1]){
                        int val = score[i1][j1] + board[i-1][j-1] - '0';
                        if(score[i][j]<=val){
                            paths[i][j] = ((score[i][j]==val ? paths[i][j]: 0) + paths[i1][j1])%mod;
                            score[i][j] = val;
                        }
                    }
                }
            }
        }

        // print_vv(score);
        // print_vv(paths);

        return {score[n][n], paths[n][n]}; 
    }
};

int main(){
    Solution sol;
    vs board;

    board = { "E23","2X2","12S" }; //[7,1]
    vi out = sol.pathsWithMaxScore(board);
    print(out);

    board = { "E12","1X1","21S" }; //[4,2]
    out = sol.pathsWithMaxScore(board);
    print(out);

    board = { "E11","XXX","11S" }; // [0, 0]
    out = sol.pathsWithMaxScore(board);
    print(out);

    return 0;
}
