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

int type(const char &c){
    if(isdigit(c)) return 0;
    if(isalpha(c)) return 1;
    return 2;
}

int main(){
    int n, m; cin>>n>>m;

    char s[55][55];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>s[i][j];
    }

    vector<int> di, ch, sy;
    for(int i=0; i<n; i++){
        int d=1e5, c=1e5, y=1e5;
        for(int j=0; j<m; j++){
            int t = type(s[i][j]);
            int pos = min(j, m-j);
            if(t==0)
                d = min(d, pos);
            else if(t==1) 
                c = min(c, pos);
            else
                y = min(y, pos);
        }
        di.push_back(d);
        ch.push_back(c);
        sy.push_back(y);
    }

    int ans = 1e8;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                if(i!=j && j!=k && k!=i)
                    ans = min(ans, di[i]+ch[j]+sy[k]);
    

    cout<<ans;
    

    
    
    return 0;
}