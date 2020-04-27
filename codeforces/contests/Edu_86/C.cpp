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

ll a,b,lc, gc, beg;

ll find_cnt(ll pos){
    ll cnt = 0;
    if(pos<0) return 0;
    ll per_period = lc - beg;

    ll t = pos/lc;
    cnt+= t*per_period;
    ll rem = pos%lc;
    // deb2(gc, lc);
    // deb2(rem, cnt);
    rem+=1;
    rem-=beg;


    if(rem>0)
        cnt+=rem;
    return cnt;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t,q,l,r;
    cin>>t;
    while(t--){
        cin>>a>>b>>q;

        // a = 5, b = 8;

        beg = max(a,b);
        gc = __gcd(a,b);
        lc = (a*b)/gc;

        bool spl = false;
        if(a==1 || b==1 || gc==a || gc==b)
            spl = true;

        // deb(find_cnt());        


        while(q--){
            cin>>l>>r;
            if(spl){
                cout<<0<<" ";
                continue;
            }
            ll cntl = find_cnt(l-1);
            ll cntr = find_cnt(r);
            cout<<cntr - cntl<<" ";

        }



        cout<<endl;
        
    }
    return 0;
}