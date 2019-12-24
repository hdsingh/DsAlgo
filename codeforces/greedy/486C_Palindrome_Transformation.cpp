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
        cout<<setw(2)<<*i<<" ";
    cout<<endl; 
}

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}

// int main(){
//     int n, pos; string s;
//     cin>>n>>pos>>s;

// }

int main(){
    int n, pos; string s;
    cin>>n>>pos>>s;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }

    int half = n/2;
    if(pos>half){
        pos = n-pos+1;
        reverse(all(s));
    }
    

    s = " " + s;

    vi chg(half+2);
    for(int i=1; i<pos; i++){
        chg[i] = chg[i-1];
        if(chg[i]==0 && s[i]!=s[n-i+1]) chg[i]++;
        else if(chg[i]!=0) chg[i]++; 
    }

    for(int i=half; i>pos; i--){
        // cout<<"i: "<<i<<" __ "<<s[i]<<" _ "<<s[n-i+1]<<endl;
        chg[i] = chg[i+1];
        if(chg[i]==0 && s[i]!=s[n-i+1]) chg[i]++;
        else if(chg[i]!=0) chg[i]++;
    }

    int lchg = chg[pos-1];
    int rchg = chg[pos+1];

    int moves = 0;
    if(lchg<rchg)
        moves = lchg*2+rchg;
    else
        moves = rchg*2+lchg;
    

    for(int i=1; i<=half; i++){
        if(s[i]!=s[n-i+1]){
            int diff = abs(s[i] - s[n-i+1]);
            diff = min(diff, 26-diff);
            moves+=diff;
        }
    }

    cout<<moves<<endl;
    
    return 0;
}