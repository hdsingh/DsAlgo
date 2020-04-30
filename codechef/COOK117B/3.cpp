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

// Gap = places where s[i]==t[i]
// find the gaps, sort them in ascending order
// add the min gap each time and find the ans
// gaps can't be just at the beg and just at the end, 
// sice they are bw any two places where s[i]!=t[i]
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; string s,t;
    cin>>T;
    while(T--){
        cin>>s>>t;
        int n = s.size();


    // each time pick the min gap and add it

    ll ops = 0, tot_len = 0;
    int i = 0;

    while(i<n){
        while(i<n && s[i]==t[i])
            ++i;

        int l = i;
        bool set = false;
        while(i<n && s[i]!=t[i]){
            ++i;
            set = true;
        }
        if(set){
            tot_len+= i - l;
            ++ops;
        }
    }

    ll ans = tot_len*ops;

    // gap refers eq_pos, bw two uneq_locs
    vi uneq_locs;
    forn(i,n)
        if(s[i]!=t[i])
            uneq_locs.pb(i);
    
    vi gaps;
    forn(i,sz(uneq_locs)-1){
        int gap = uneq_locs[i+1] - uneq_locs[i] - 1;
        if(gap>0)
            gaps.pb(gap);
    }
    
    // print(uneq_locs);
    sort(all(gaps));
    // print(gaps);
    // deb2(tot_len, ops);


    for(auto x: gaps){
        tot_len+=x;
        --ops;
        ans = min(ans, tot_len*ops);
    }

    cout<<ans<<endl;

    }
    return 0;
}

// So gap is always bw two pos, where s[i]==t[i];
// abbbccbarrsfa
// axxxccxarrrka
// |   || |   


// adefb
// bdefa
// |   | 

