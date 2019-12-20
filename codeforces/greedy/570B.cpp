#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9;


int main(){
    int n, m; cin>>n>>m;

    int out;
    int half = (n+1)/2;
    if(n&1){
        if(m>=half){
            out = m-1;
        }else{
            out = m+1;
        }
    }else{ //even
        if(m<=half)
            out = m+1;
        else
            out = m-1;

    }

    out = max(1, out);
    out = min(out, n);
    cout<<out<<endl;

    return 0;
}

// int main(){
// 	ll n, m;
// 	cin >> n >> m;
// 	if(n == 1){
// 		cout << 1;
// 		return 0;
// 	}
// 	if(m - 1 < n - m){
// 		cout << m + 1;
// 	}
// 	else{
// 		cout << m - 1;
// 	}
// }