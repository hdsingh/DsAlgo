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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

string dul = "DUL";

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,K;
    while(cin>>n>>m>>K){
        vector<pair<int, string>> moves;
        int k = 0;
        int mx = 4*n*m - 2*n - 2*m;
        // deb(mx);

        if(K>mx){
            cout<<"NO"<<endl;
            // cout<<-1<<endl;
            continue;
        }

        if(m==1){
            int down = min(n-1,K);
            k+=down;
            moves.push_back({down, "D"});
            if(k>=K) break;
            int up = min(n-1, K-k);
            k+=up;
            moves.push_back({up, "U"});
        }

        int row = 0;
        while(k<K){
            // deb(row);
            if(row==n-1) break;

            int right = min(m-1, K-k);
            k+=right;
            moves.push_back({right, "R"});
            // deb2(left, "L");
            if(k>=K) break;

            // dul
            int rpos = 3*(m-1);
            int d = K-k;
            if(d<rpos){
                int q = d/3;
                int r = d%3;
                if(q){
                    moves.push_back({q,"DUL"});
                    // deb2(q, "DUR");
                    k+=3*q;
                }
                if(r){
                    moves.push_back({1,dul.substr(0,r)});
                    // deb2(1,dur.substr(0,r))
                    k+=r;
                }
                break;
            }else{
                k+= 3*(m-1);
                moves.push_back({m-1, "DUL"});
                // deb2(m-1, "DUR");
            }

            if(k>=K) break;

            k+=1; // down
            moves.push_back({1,"D"});
            // deb2(1,"D");
            if(k>=K) break;

            ++row;

        }   

        // last row moves
        int d = K-k;
        while(k<K){
            int right = min(K-k, m-1);
            moves.push_back({right,"R"});
            k+=right;
            // deb3(left, k, K);
            if(k>=K) break;

            int left = min(K-k, m-1);
            moves.push_back({left, "L"});
            k+=left;
            // deb3(right, k, K);
            if(k>=K) break;

            int up = min(K-k,n-1);
            k+=up;
            moves.push_back({up,"U"});
            // deb3(up, k, K);
            if(k>=K) break;
        }

        assert(k==K);
        // deb2(k,K);
    
        cout<<"YES"<<endl;
        cout<<(int)moves.size()<<endl;
        for(auto p: moves){
            cout<<p.first<<" "<<p.second<<endl;
        }
        // cout<<endl;
    }
    return 0;
}