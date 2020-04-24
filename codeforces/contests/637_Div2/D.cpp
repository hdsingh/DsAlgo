#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

const int inf = 1e9;

int steps_to_convert(string &a, string &b){
    int steps = 0;
    forn(i,7){
        if(a[i]=='1' && b[i]=='0')
            return inf;
        else if(a[i]=='0' && b[i]=='1')
            ++steps;
    }
    return steps;
}

int main(){
    vs digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
    
    int n,k;
    while(cin>>n>>k){
        vs a(n);
        for(auto &s: a)
            cin>>s;
        
        vector<vb> possible(n+1, vb(k+1));
        // is it possible to convert ith digit with j remaining steps
        possible[n][0] = true;
        for(int i=n-1; i>=0; --i){
            for(int d=9; d>=0; --d){
                for(int steps = 0; steps<=k; ++steps){
                    int prev_used = steps - steps_to_convert(a[i],digits[d]);
                    if(prev_used>=0 && possible[i+1][prev_used]){
                        possible[i][steps] = true;
                    }
                }
            }
        }

        if(!possible[0][k]){
            cout<<-1<<endl;
            continue;
        }

        // print_vv(possible);

        for(int i=0; i<n; ++i){
            for(int d=9; d>=0; --d){
                if(possible[i][k]){
                    int conv_steps = steps_to_convert(a[i],digits[d]);
                    int prev_steps = k - conv_steps; 
                    if(prev_steps>=0 && possible[i+1][prev_steps]){
                        cout<<d;
                        k-=conv_steps;
                        break;
                    }
                }
            }
        }

        cout<<endl;
    }

    return 0;
}