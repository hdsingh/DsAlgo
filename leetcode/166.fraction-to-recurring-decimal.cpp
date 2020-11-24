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
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)

class Solution {
public:
    string fractionToDecimal(long N, long D) {
        if(N==0) return "0";
		string ans;
		if((N<0)!=(D<0))
			ans+="-";
		N = abs(N); D = abs(D);
		ans+=to_string(N/D);
		long rem = N%D;
		if(rem==0) return ans;

		ans+='.';
		unordered_map<long, int> seen;
		while(rem>0){
			if(seen.count(rem)){
				ans.insert(seen[rem], "(");
				ans+=")";
				break;
			}
			// position at which this rem has been seen
			seen[rem] = ans.size(); 
			rem *=10;
			ans+=to_string(rem/D);
			rem = rem%D;
		}
		return ans;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; string out;
    out = sol.fractionToDecimal(-22,7000); deb(out);
    return 0;
}