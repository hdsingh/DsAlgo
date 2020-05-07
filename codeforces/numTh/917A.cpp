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

template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(const T &v){if(sz(v)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(v[0]); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<sz(v); i++){cout<<i<<" {";for(auto j = 0; j!=sz(v[i]); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// we count for each substring starting from i.
// our main aim is always to make sum==0 as soon as possible
// (sum==0 means pretty). So when we encounter a '?'
// assume that it is a ')' and decrease the sum, however save it in extra.
// Extra just means '?' seen till now in the substring, so that they can be converted
// to '(', whenever required.
// The only time we will require it is when the sum is <0 (means more ')' ). Now we wish that some of prev pos 
// should have '(' instead of ')' so that it could become valid. Hence if we have some extra '?' we can use those
// Using a '?' means, converting the prev ')' to '(', so the sum will become sum = sum -(-1) + 1, i.e sum+=2
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    while(cin>>s){
        int n = sz(s);
        int ans = 0;

        fore(i,0,n){
            int sum(0), extra(0);
            fore(j,i,n){
                if(s[j]=='(')
                    ++sum;
                else if(s[j]==')')
                    --sum;
                else 
                    --sum, ++extra;
                
                if(sum<0)
                    sum+=2, --extra;

                if(extra<0) break;
                if(sum==0) ++ans;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}