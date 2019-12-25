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
const int inf = 1e9;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

vs grid;
vvi grps;
int n;

void dfs(int i, int j, int g){
    if(0<=i && i<n && 0<=j && j<n)
        if(grid[i][j]=='0' && grps[i][j]==0){ //land and not given grp
        grps[i][j] = g;
        dfs(i+1, j, g);
        dfs(i-1, j, g);
        dfs(i, j+1, g);
        dfs(i, j-1, g);
    }
}

int main(){
    while(cin>>n){
        if(n<=1){
            cout<<"0"<<endl;
            return 0;
        }
        int r1,c1, r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--; c1--; r2--; c2--;


        grid.resize(n);
        grps.resize(n, vi(n));

        for(int i=0; i<n; i++)
            cin>>grid[i];
        
        int g = 1; //group
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='0' && grps[i][j]==0){ //0:land and not given grp
                    dfs(i,j,g);
                    g++;
                }   
            }
        }

        vector<vector<pair<int,int>>> ss(n*n);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                int s =grps[i][j];
                if(s) ss[s].push_back({i,j});
            }

        int s1 = grps[r1][c1];
        int s2 = grps[r2][c2];

        // print_vv(grps);
        // deb(s1); deb(s2);
        

        int cost = INT_MAX;
        for(int i=0; i<ss[s1].size(); i++){
            for(int j=0; j<ss[s2].size(); j++){
                int x1 = ss[s1][i].first;
                int y1 = ss[s1][i].second;
                int x2 = ss[s2][j].first;
                int y2 = ss[s2][j].second;
                int c = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
                // cout<<x1<<" "<<y1<<" , "<<x2<<" "<<y2<<" c:"<<cost<<endl;
                cost = min(c, cost);
            }
        }

        cout<<cost<<endl;
    }

    return 0;
}