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

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}


const int maxn = (int)3e5 + 3;
const int maxa = (1 << 20) + 3;
int cnt[2][maxa];

int main(){
    int n; cin>>n;
    int a;
    // vi x(n+1);

    int x = 0;
    ll res = 0;

    cnt[0][0] = 1; // for 0, since it has already appeared at 0th index
    for(int i=1; i<n+1; i++){
        cin>>a;
        x^=a;
        res+= cnt[i%2][x];
        cnt[i%2][x]++;
    }

    cout<<res;

    return 0;
}