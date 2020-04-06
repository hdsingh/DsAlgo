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

// Ref: https://www.geeksforgeeks.org/digit-dp-introduction/amp/
// Given 2 digits a and b, print sum of digits bw a and b.
// 1<= a < b < 1e18;

// for k digit number k, k*9, 2
ll dp[20][180][2]; // idx, sum, tight
vi digits;

void getDigits(ll n){
    digits.clear();
    while(n){
        digits.pb(n%10);
        n/=10;
    }
}

ll digitSum(int idx, ll sum, int tight){
    if(idx==-1) return sum;

    if(dp[idx][sum][tight]!=-1 && tight!=1)
        return dp[idx][sum][tight];
    
    ll res = 0;

    // range value
    int k = tight ? digits[idx]  : 9;

    for(int i=0; i<=k; ++i){
        int newTight = (digits[idx]==i) ? tight : 0;
        res += digitSum(idx-1,sum+i,newTight);
    }

    if(!tight)
        dp[idx][sum][tight] = res;
    
    return res;

}

// returns sum of digits from a to b
ll rangeDigitSum(ll a, ll b){
    // sumDigit(b) - sumDigit(a-1);
    memset(dp, -1, sizeof(dp));

    getDigits(a-1);
    ll aSum = digitSum((int)digits.size(),0, 1);

    getDigits(b);
    ll bSum = digitSum((int)digits.size(), 0, 1);

    return bSum - aSum;
}

int main(){

    ll a = 123, b = 1024;
    ll res = rangeDigitSum(a,b);
    cout<<res<<endl;

    return 0;
}