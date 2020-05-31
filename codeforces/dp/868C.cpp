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

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k,x;
    while(cin>>n>>k){
        bool found = false;
        set<int> s;
        forn(i,n){
            int mask = 0;
            forn(j,k){
                cin>>x;
                if(x) mask|=(1<<j);
            }

            if(mask==0)
                found = true;
            
            for(auto prev: s){
                if((prev&mask)==0){
                    found = true;
                }
            }

            s.insert(mask);
        }

        cout<<(found ? "YES\n" : "NO\n");

    }
    return 0;
}