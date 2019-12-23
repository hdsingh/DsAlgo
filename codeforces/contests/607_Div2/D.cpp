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
typedef long long ll;
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

int moves(vs &g, int &r, int &c){
    vi rows(r), cols(c);
    int total = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(g[i][j]=='A') rows[i]++, cols[j]++, total++;
        }
    }

    if(total==0)
        return -1;
    if(total==r*c)
        return 0;
    if(rows[0]==c || rows.back()==c || cols[0]==r || cols.back()==r)
        return 1;
    if(g[0][0]=='A' || g[0].back() == 'A' || g.back()[0]=='A' || g.back().back()=='A')
        return 2;
    if(*max_element(all(rows))==c || *max_element(all(cols))==r )
        return 2;
    if(rows[0] || rows.back() || cols[0] || cols.back())
        return 3;
    return 4;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int r, c; 
        cin>>r>>c;
        vector<string> g(r);//grid
        for(int i=0; i<r; i++)
            cin>>g[i];
        
        int m = moves(g, r, c);
        string out = m==-1 ? "MORTAL" : to_string(m);
        cout<<out<<endl;

    }
    return 0;
}