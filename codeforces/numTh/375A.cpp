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
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

vi md7 = {9681, 8961, 9816, 6891, 8691, 9861, 8196};

// Main Property: (a+b)%mod = (a%mod + b%mod)%mod
// so form the numbers such that after removing 1689 
// form a number xxxx0000, (0000 for 1689) -> xxx0000%7 = a;
// so only  if we place md7[b] such that a+b=7 ->mod0 
int main(){
    // string a = "1689";
    // vi md7(7);
    // while(next_permutation(all(a))){
    //     int b = stoi(a);
    //     md7[b%7] = b;
    // }
    // print(md7);
    
    const int m = 7;
    string s;
    while(cin>>s){
        int rem = 0;
        int n = s.size();
        map<int, int> cnt;
        for(char c: s){
            cnt[c-'0']++;
        }
        for(int x : {1,6,8,9})
            cnt[x]--;
        // print_m(cnt);

        fore(i, 1, 10){
            forn(j, cnt[i]){
                rem = (rem*10%m + i%m)%m;
                cout<<i;
            }
        }

        forn(j, 4){
            rem = (rem*10%m + 0%m)%m;
        }
        // deb(rem);

        if(rem==0) rem = 7;
    
        cout<<md7[7 - rem];
        
        // since 7, 70, 700, or any number divisible by 7
        // will remain divisibel by 7 even upon multiplying by 10, 100, 1000
        // So print the end
        forn(i, cnt[0]) 
            cout<<0;
        cout<<endl;



        // cout<<rem<<endl;
    }

    
    return 0;
}