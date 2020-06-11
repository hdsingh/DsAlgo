#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)

string to_binary(int x) {
	string s;
	while(x > 0) {
		s += (x % 2 ? '1' : '0');
		x /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

ll binToDec(string s){
    ll out = 0;
    int n = s.size();
    for(int i=0; i<n; ++i){
        if(s[i]=='1')
            out|=(1LL<<(n-i-1));
    }
    return out;
}

// for base>10 use vi to store remainders insted of string
string to_nary1(int x, int base){
    string s;
    while(x){
        s+= to_string(x%base);
        x/=base;
    }
    reverse(all(s));
    return s;
}


vi to_nary(ll x, int base){
    vi out;
    while(x){
        out.pb(x%base);
        x/=base;
    }
    out.pb(0);
    out.pb(0);
    reverse(all(out)); // if need to print
    return out;
}

int main(){
    
    return 0;
}

// Ex:
// 1. https://codeforces.com/contest/1249/problem/C2