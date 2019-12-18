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

bool dp[210][210][210]; //rgb

void dfs(int r, int g, int b){
    if(dp[r][g][b]) return;
    dp[r][g][b] = true;
    if(r>=2) dfs(r-1, g, b);
    if(g>=2) dfs(r, g-1, b);
    if(b>=2) dfs(r, g, b-1);

    if(r && g) dfs(r-1, g-1, b+1);
    if(b && r) dfs(r-1, g+1, b-1);
    if(g && b) dfs(r+1, g-1, b-1);

}


int main(){
    int n; char c;
    cin>>n;
    string cards;
    cin>>cards;

    map<char, int> cnt;
    for(auto &a: cards)
        cnt[a]++;
    
    dfs(cnt['R'], cnt['G'], cnt['B']);
    string ans;
    if(dp[0][0][1]) ans+='B';
    if(dp[0][1][0]) ans+='G';
    if(dp[1][0][0]) ans+='R';
    cout<<ans;
    

    return 0;
}