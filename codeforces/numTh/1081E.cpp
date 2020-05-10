#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

const ll inf  = 2e18L + 5;

// Imortant observation
// Given a difference X, we need to find b^2 - a^2 = X
// (b+a)(b-a) = X
// here (b+a) = d2, (b-a) = d1, where d1 and d2 are divisors(factors) of X and d2>=d1
// we are interested in least possible value of a,
// a = (d2-d1)/2 
// seq : sum , a^2 , b^2
//       X1          X2
// since the seq is increasing, a^2 > sum
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n){
        vl out;
        ll sum = 0;
        vi nums(n/2); forn(i,n/2) cin>>nums[i];

        for(auto dif: nums){
            ll min_a_sq = inf;

            for(ll d1=1; d1*d1<dif; ++d1){
                if(dif%d1==0){
                    ll d2 = dif/d1;

                    if(d1!=d2 && (d2-d1)%2==0){
                        ll a = (d2-d1)/2;
                        
                        if(a*a>sum){
                            min_a_sq = min(min_a_sq, a*a);
                        }
                    }
                }
            }

            if(min_a_sq==inf){
                cout<<"No"<<endl;
                return 0;
            }

            out.push_back(min_a_sq - sum);
            out.push_back(dif);
            sum = min_a_sq + dif; 
        }
        cout<<"Yes\n";
        print(out);
    }    
    return 0;
}