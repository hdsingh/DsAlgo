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
    vector<pair<string, int>> v ={{ "aaa", 10 },
                                  { "ddd", 41 },
                                  { "bbb", 62 },
                                  { "ccc", 13 }};

    // map<string, int> m1(v.begin(), v.end()); //equal to
    map<string, int, less<string>> m1(v.begin(), v.end());

    // Internal order (sorted by asc of keys)
    // aaa: 10
    // bbb: 62
    // ccc: 13
    // ddd: 41
    for(auto x: m1)
        cout<<x.first<<": "<<x.second<<endl;
    cout<<endl;

    // Sort by dsc of keys
    map<string, int, greater<string>> m2(v.begin(), v.end());
    for(auto x: m2)
        cout<<x.first<<": "<<x.second<<endl;
    cout<<endl;
        
    return 0;
}