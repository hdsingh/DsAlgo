#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

vs grid(10);

int dx[4] = {1, 0, 1, 1};
int dy[4] = {0, 1, 1, -1};

void check(int x, int y, int k){
    map<char, int> cnt;

    forn(i, 5){
        if(x<0 || y<0 || x>=10 || y>=10)    
            return;
        
        cnt[grid[x][y]]++;
        
        x+=dx[k];
        y+=dy[k];
    }

    if(cnt['X']==4 && cnt['.']==1){
        cout<<"YES"<<endl;
        exit(0);
    }
}

int main(){
            
    forn(i, 10)
        cin>>grid[i];
    
    forn(i, 10){
        forn(j, 10){
            forn(k, 4){
                check(i,j,k);
            }
        }
    }

    cout<<"NO"<<endl;

    return 0;
}