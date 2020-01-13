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
 
int hex_to_int(char c){
    return isdigit(c) ? c-'0' : c -'A' + 10;
}
 
const int NMAX = 5205;
 
int main(){
    int n;
    char c;
    while(cin>>n){
        int sz = n/4;
        // vvi mat(n, vi(n)); //matrix
        
        // vector<bitset<NMAX>> mat(NMAX);
        vector<vector<bool>> mat(NMAX, vector<bool>(NMAX));
 
        forn(i, n){
            forn(j, sz){
                cin>>c;
                int cint = hex_to_int(c);
                int pos=0;
                for(int k=3; k>=0; k--){
                    // deb(pos+ j*4);
                    mat[i][pos+j*4] = (cint&(1<<k))&&1;
                    pos++;
                }
            }
        }
        // print_vv(mat);
 
        vvi rect(n+1, vi(n+1)); //rectangular sum
        forn(i, n){
            forn(j, n){
                rect[i+1][j+1] = rect[i+1][j] + rect[i][j+1] - rect[i][j] + mat[i][j];
            }
        }
        // print_vv(rect);
        auto get_area = [&](int x2, int y2, int x1, int y1){
            return rect[x2][y2] - rect[x1][y2] - rect[x2][y1]  + rect[x1][y1];
        };
 
        for(int x=n; x>=1; x--){
            if(n%x==0){
                int good = true;
                for(int i=0; i<n && good; i+=x){
                    for(int j=0; j<n && good; j+=x){
                        int area = get_area(i+x, j+x,i,j);
 
                        if(area!=0 && area!=x*x)
                            good =false;
                        
                    }
                }
 
                if(good){
                    cout<<x<<endl;
                    break;
                }
            }
        }
 
    }
 
    return 0;
}
 