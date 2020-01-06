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
const int inf = 1e9 + 5;

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

set<string> was;
vl fact(20);
vi c0(10);
vi c(10);

void split(string &s, vi &c){
    forn(i, 10)
        c[i]= 0;
    
    for(char ch: s)
        c[ch-'0']++;
}

ll getCount(){
    ll ans = fact[accumulate(c.begin(), c.end(), 0)];
    forn(i,10)
        ans/=fact[c[i]];
    return ans;
}

ll getans(string s){
    split(s, c);

    // if subset is missing any letter dont process
    forn(i,10)
        if(c0[i] && !c[i])
            return 0;
    
    // if already processed such seq, dont process
    sort(s.begin(), s.end());
    if(was.count(s))
        return 0;
    
    was.insert(s);

    ll ans = getCount();
    if(c[0]>0){
        c[0]--;
        ans-=getCount();
    }

    return ans;

}


int main(){
    fact[0] = 1;
    fore(i,1, 20)
        fact[i] = fact[i-1] * i;

    string s;
    cin>>s;

    int n = s.size();
    split(s, c0);

    ll ans = 0;
    
    forn(i, (1<<n)){
        string x;
        forn(j, n){
            if(i&(1<<j))
                x+=s[j];
        }
        ans+= getans(x);
    }

    cout<<ans<<endl;

    return 0;
}