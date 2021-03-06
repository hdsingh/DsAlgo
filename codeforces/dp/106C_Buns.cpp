#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define deb4(t, x, y, z) cout<<#t<<" "<<t<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
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

int main(){
	int n,m,c0,d0;
	while(cin>>n>>m>>c0>>d0){
		vi tot_stuf(m+1), b(m+1), c(m+1), d(m+1); // tot stuffing, stuf/bun, dough/bun, $
		fore(i,1,m+1)
			cin>>tot_stuf[i]>>b[i]>>c[i]>>d[i];

		vvi dp(n+1, vi(m+1));
		// max profit with i grams of dough and till jth stuffing type

		for(int j=1; j<=m; ++j){
			for(int dough=n; dough>=0; --dough){
				for(int buns=0; buns<=tot_stuf[j]/b[j]; ++buns){
					int req_dough = buns * c[j];
					if(req_dough<=dough)
						max_self(dp[dough][j], dp[dough - req_dough][j-1] + d[j]*buns);
				}
			}
		}
		
		int mx = 0;
		fore(dough, 0, n+1)
			max_self(mx, dp[dough][m] + (n-dough)/c0 * d0);

		cout<<mx<<endl;

	}
	return 0;
}

// Let create array dp by size n x m.
//  dp[i][j] means maximum number of tugriks that the baker 
//  can earn if he used i grams of dough and cook buns with 
//  stuffings of types 1..j.

// Initially dp[i][0] is 0 for all i.

// You can easily calculate this dp:
// for every k from 0 to a[j]/b[j], for which i-c[j]*k>=0
// dp[i][j] = max{ dp[i-c[j]*k][j-1] + d[j]*k } 

// The answer will be 
// max{ dp[k][m] + ((n-k)/c0)*d0 } for every k from 0 to n.
