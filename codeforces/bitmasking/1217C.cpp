#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

ll f(const string &s){
    return bitset<18>(s).to_ulong();
}

const int N = 3e5;
int nxt[N];

int main(){
    int t;
    string s;

    cin>>t;
    while(t--){
        cin>>s;
        for(int i=0; i<s.size(); i++)
            if(s[i]=='1') nxt[i] = i;
            else nxt[i] = (i==0? -1 : nxt[i-1]);
        
        int res = 0;
        forn(r, s.size()){
            int sum=0;
            for(int l=r; l>=0 && r-l<20; l--){
                if(s[l]=='0') continue;
                sum+= (1<<(r-l));
                if(sum<=r-(l==0 ? -1 : nxt[l-1]))
                    res++;
            }
        }
        cout<<res<<endl;
    }
}



// int main(){
//     int t;
//     string s;
//     cin>>t;
//     while(t--){
//         cin>>s;
//         int n = s.size();
//         int cnt = 0;

//         vi zeros(n); //consecutive zeros before l
//         zeros[0] = 0;
//         fore(i, 1, n)
//             if(s[i-1]=='0')
//                 zeros[i] = zeros[i-1] + 1;

//         for(int l=0; l<n; l++){
//             if(s[l]=='1'){
//                 // deb(l);
//                 for(int r=l; r<=min(l+19, n-1); r++){
//                     // deb(r);
//                     ll a = f(s.substr(l, r-l+1));
//                     // deb(a);
//                     if(a <= (r-l+1) + zeros[l]){
//                         cnt++;
//                     }
//                 }
//             }
//         }

//         cout<<cnt<<endl;
//     }
//     return 0;
// }