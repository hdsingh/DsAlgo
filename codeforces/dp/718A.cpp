#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;} for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

const int inf = 1e6;

int main(){
    int n, t;
    while(cin>>n>>t){
        vi a;
        int dec_pos;
        char x;
        forn(i, n){
            cin>>x;
            if(x=='.')
                dec_pos = i;
            else 
                a.pb(x-'0');
        }
        if(n==1){
            cout<<a[0]<<endl;
            return 0;
        }

        vi dp(n-1, inf);
        for(int i=n-2; i>=0; i--){
            if(a[i]<=3)
                dp[i] = inf;
            else if(a[i]>4)
                dp[i] = 1;
            else // a[i] is 4
                dp[i] = (i+1<n-1 ? 1 + dp[i+1] : inf);
        }

        int min_pos = inf;
        fore(i, dec_pos, n-1){
            if(dp[i]<=t){
                min_pos = i;
                break;
            }
        }
       

        // print(a, 1);
        // print(dp);
        // deb(min_pos)
        // deb(dec_pos)

        string out = "0";
        forn(i, n-1){
            // deb(i)
            if(i==dec_pos)
                out+=".";
        
            if(i==min_pos-1){
                if(a[i]==9){
                    // deb(out);
                    out+="0";
                    int z = out.size()-2;
                    while(out[z]=='9' || out[z]=='.'){
                        if(out[z]!='.')
                            out[z] = '0';
                        z--;
                    }
                    out[z]++;
                }else{ 
                    out+=to_string(a[i]+1);
                }
                break;
            }else 
                out+=to_string(a[i]);
        }
        forn(i, out.size()){
            if(i==0 && out[0]=='0')
                continue;
            cout<<out[i];
        }
        // cout<<out<<endl;
        cout<<endl;
        
        
        
    }
    return 0;
}