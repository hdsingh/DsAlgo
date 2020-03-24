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
ll s;
ll lsum;
vector<pii> p;

bool medianCanbe(int mid){
    ll sum = 0;
    int cnt = 0;
    
    vi v;
    for(auto &x: p){
        if(x.second<mid)
            sum+=x.first;
        else if(mid<=x.first)
            sum+=x.first, ++cnt;
        else 
            v.push_back(x.first);
    }

    assert(is_sorted(all(v)));

    int req = max(0, (n+1)/2 - cnt);
    if(req>(int)v.size()) return false;


    for(int i=0; i<v.size(); ++i){
        if(i<v.size() - req)
            sum+=v[i];
        else 
            sum+=mid;
    }
    
    return sum<=s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; 
    cin>>t;
    while(t--){
        cin>>n>>s;
        p.clear(); p.resize(n);
        lsum = 0;

        forn(i,n){
            cin>>p[i].first>>p[i].second;
            lsum+=p[i].first;
        }

        sort(all(p));

        int lt = 0, rt = 1e9 + 100;
        while(lt+1<rt){
            int mid = lt + (rt-lt)/2;

            if(medianCanbe(mid))
                lt = mid;
            else 
                rt = mid;
        }

        cout<<lt<<endl;
    }
    return 0;
}