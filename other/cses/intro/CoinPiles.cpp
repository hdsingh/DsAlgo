#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        ll a, b; cin>>a>>b;
        ll x = 2*a - b, y =  2*b - a;
        if(x<0 || y<0 || x%3 || y%3){
            cout<<"NO\n"; continue;
        }else{
            cout<<"YES\n";
        }
    }
    return 0;
}