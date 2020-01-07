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

int main(){
    int n, m;
    while(cin>>n>>m){
        vector<string> flag(n);
        forn(i, n)
            cin>>flag[i];
        
        
        // find h or v
        bool hor = true;
        char a;
        a = flag[0][0];
        fore(i, 1, m)
            if(flag[0][i]!=a){
                hor = false;
                break;
            }
        
        int r(0), b(0), g(0);
        vi cols;
        if(hor){
            forn(i, n){
                a = flag[i][0];
                fore(j, 1, m){
                    if(flag[i][j]!=a){
                        cout<<"NO"<<endl;
                        return 0;
                    }
                }
                cols.pb(a);
            }
        }else{
            forn(i, m){
                a = flag[0][i];
                fore(j, 1, n){
                    if(flag[j][i]!=a){
                        cout<<"NO"<<endl;
                        return 0;
                    }
                }
                cols.pb(a);
            }

        }

        // Check matching
        if(cols.size()%3!=0){
            cout<<"NO"<<endl;
            return 0;
        }
        int cnt = cols.size()/3;

        map<char, int> used;
        forn(i, 3*cnt){
            if(i%cnt==0){
                if(i!=0){
                    if(used[cols[i]]){
                        cout<<"NO"<<endl;
                        return 0;
                    }
                }
                a = cols[i];
                used[a] = 1;
            }else{
                if(cols[i]!=a){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
        
        cout<<"YES"<<endl;

    }    
    return 0;
}