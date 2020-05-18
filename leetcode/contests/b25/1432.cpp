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

class Solution {
public:
    int maxDiff(int num) {
        vi a;
        while(num){
            int lst = num%10;
            num/=10;
            a.push_back(lst);
        }
        reverse(a.begin(), a.end());
        int sz = a.size();
        vi mxa = a;
        
        for(int i=0; i<sz; ++i){
            if(mxa[i]!=9){
                int prev = mxa[i];
                int j = i;
                while(j<sz){
                    if(mxa[j]==prev){
                        mxa[j] = 9;
                    }
                    ++j;
                }
                break;
            }
        }


        vi mna = a;
        bool st1 = (a[0]==1);
        bool done = false;
        for(int i=0; i<sz; ++i){
            if(i==0){
                if(mna[i]!=1){
                    int prev = mna[i];
                    mna[i] = 1;
                    int j = i;
                    while(j<sz){
                        if(mna[j]==prev){
                            mna[j] = 1;
                        }
                        ++j;
                    }
                    break;                    
                }
            }else{
                if(mna[i]!=0){
                    if(mna[i]==1 && st1) continue;

                    int prev = mna[i];
                    mna[i] = 0;
                    int j = i;
                    while(j<sz){
                        if(mna[j]==prev){
                            mna[j] = 0;
                        }
                        ++j;
                    }
                    break;
                }
            }
        }

        // print(a);
        // print(mxa);
        // print(mna);

        int mn = recover(mna);
        int mx = recover(mxa);

        return mx - mn;
    }

    int recover(vi in){
        int out = 0;
        for(auto x: in){
            out = out*10 + x;
        }
        return out;
    }
};

int main(){
    Solution sol;
    vi a = {555,
9,
123456,
10000,
9288,
1101057,
};
    for(auto x: a){
        int out = sol.maxDiff(x);
        deb(out);
    }
    return 0;
}