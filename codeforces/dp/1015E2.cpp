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
 
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
 
vs grid;
int n,m;
 
vs draw(const vector<pair<pii, int>> &stars){
    vs new_grid(n, string(m,'.'));
    vvi hor(n, vi(m)), ver(n, vi(m));
 
    for(auto star: stars){
        // int x = star[0];
        // int y = star[1];
        // int sz = star[2];
        int x = star.first.first;
        int y = star.first.second;
        int sz = star.second;
 
        ++hor[x][y-sz];
        if(y+sz+1 < m)
            --hor[x][y+sz+1];
 
        ++ver[x-sz][y];
        if(x+sz+1<n)
            --ver[x+sz+1][y]; 
    }
 
    forn(i, n){
        forn(j, m){
            hor[i][j] += (j-1>=0 ? hor[i][j-1] : 0);
            ver[i][j] += (i-1>=0 ? ver[i-1][j] : 0);
            if(hor[i][j]>0 || ver[i][j]>0)
                new_grid[i][j] = '*';
        }
    }
 
    return new_grid;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;
    // while(cin>>n>>m){
        // stars.clear();
        // grid.clear();
        grid = vs(n);
        
        forn(i,n)
            cin>>grid[i];
        
        vvi up(n, vi(m)), down(n, vi(m)), left(n, vi(m)), right(n, vi(m));
 
        forn(i,n){
            forn(j, m){
                if(grid[i][j]=='*'){
                    left[i][j] = 1 + (j-1>=0 ? left[i][j-1] : 0);
                    up[i][j]   = 1 + (i-1>=0 ? up[i-1][j] : 0);
                }
            }
        }
 
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(grid[i][j]=='*'){
                    right[i][j] = 1 + (j+1<m ? right[i][j+1] : 0);
                    down[i][j]  = 1 + (i+1<n ? down[i+1][j] : 0);
                }
            }
        }
 
        // vvi stars;//{x,y, sz}
        vector<pair<pii, int>> stars;
        // Find stars with center and max extensions
        forn(i, n){
            forn(j, m){
                if(grid[i][j]!='.'){
                    // vi sizes = {left[i][j], right[i][j], up[i][j], down[i][j]};
                    // int sz = *min_element(all(sizes)) - 1;
                    int sz = min( min(left[i][j], right[i][j]), min(up[i][j], down[i][j]) )-1;
                    if(sz){
                        stars.pb({{i, j}, sz});
                    }
                }
            }
        }
        
 
        // Reconstruct pic from stars arr and compare it with orignal pic
        if(draw(stars)!=grid){
            cout<<-1<<endl;
        }else{
            cout<<stars.size()<<endl;
            for(auto &s: stars){
                cout<<s.first.first+1<<" "<<s.first.second+1<<" "<<s.second<<endl;
            }
        }
 
        // cout<<endl;
        
    // }
    return 0;
}