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
    int n, k;
    string s;
    cin>>n>>k;
    cin>>s;


    if (n==1)
    {
        if (k==0) cout<<s<<endl;
        else cout<<0<<endl;
        return 0;
    }
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        if (cnt==k) break;
        if (i==0&&s[i]!='1')
        {
            s[i]='1';
            cnt++;
        }
        else if (i!=0&&s[i]!='0')
        {
            s[i]='0';
            cnt++;
        }
    }
    cout<<s<<endl;
    
    return 0;
}