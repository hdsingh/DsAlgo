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

int n;
vs inps;
vs big;
string res;

bool check(const string &pref, const string &suf){
    res.clear();

    string s = pref + suf.back();
    multiset<string> inps2, sufs, prefs;
    for(int i=0; i<n-1; ++i){//n-1 bec we dont want full string
        string pr = s.substr(0,i+1);
        string sf = s.substr(i+1);
        prefs.insert(pr), sufs.insert(sf);
        inps2.insert(pr), inps2.insert(sf);
    }

    if(inps2 == multiset<string>(all(inps))){
        for(int i=0; i<2*n-2; ++i){
            if(prefs.count(inps[i])){
                res+= 'P';
                prefs.erase(prefs.find(inps[i]));
            }else if(sufs.count(inps[i])){
                res+='S';
                sufs.erase(sufs.find(inps[i]));
            }else 
                assert(false);
        }
        return true;
    }
    return false;
}

int main(){
    while(cin>>n){
        inps.resize(2*n-2); big.clear();
        forn(i, 2*n-2){
            cin>>inps[i];
            if((int)inps[i].size() == n-1)
                big.push_back(inps[i]);
        }

        if(check(big[0], big[1]))
            cout<<res<<endl;
        else{
            check(big[1], big[0]);
            cout<<res<<endl;
        }
    }
    return 0;
}