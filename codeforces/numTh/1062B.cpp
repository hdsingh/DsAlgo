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
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
void print_m(map<int,int> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

map<int,int> primeFact(int n){
    map<int,int> m;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            while(n%i==0){
                m[i]++;
                n/=i;
            }
        }
    }
    if(n>1) m[n]++;
    return m;
}

bool all1(const vi &a){
    bool ans = true;
    for(int x: a){
        if(x!=1){
            ans = false;
            break;
        }
    }
    return ans;
}

// if all even, equal, pow of 2
bool isRtpos(const vi &a){
    int mx = *max_element(all(a));
    mx = pow(2, ceil(log2(mx))); 
    bool ans = true;
    for(auto x: a){
        if(x!=mx){
            ans = false;
            break;
        }
    }
    return ans;
}

void findRt(vi &a){
    for(auto &x: a)
        x/=2;
}

void mul(vi &a){
    int mx = *max_element(all(a));
    mx = pow(2, ceil(log2(mx)));
    for(auto &x: a){
        x=mx;
    }
}

int main1(){
    int n;
    while(cin>>n){
        auto m = primeFact(n);
        // print_m(m);
        vi a;
        int num = 1;
        for(auto x: m){
            num*=x.first;
            a.pb(x.second);
        }
        
        int ops = 0;
        while(!all1(a)){
            // print(a);
            if(isRtpos(a)){
                findRt(a);   
            }else{
                mul(a);
            }
            ops++;
        }


        cout<<num<<" "<<ops<<endl;
    }
    return 0;
}
