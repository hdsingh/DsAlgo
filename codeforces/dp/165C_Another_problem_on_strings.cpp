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

// Refer: https://www.geeksforgeeks.org/count-substrings-binary-string-containing-k-ones/
// if csum at s[i] = a+k, then the number of subtrings having sum k,
// are from next pos of s[j]=a till cur pos.
// In other words number of s[j]= a, is the number of substrings having sum k for pos
// where sum= k+a; 
// k = 2
//          1   2   3   4  5  6  7   8
// ex:      1   1   0   0  0  0  1   1  0  0
// csum: 0  1   2   2   2  2  2  3   4  4  4
// the substrings having csum=2 are (12), (32),
// atpos 8: csum=4, so all the sub where sum  4-k = 2
// ie  3..8, 4..8, 5..8, 6..8, 7..8
// ie. freq of 4-k
// 
int main(){
    // int t; cin>>t;
    // while(t--){
        int k; cin>>k;
        string s; cin>>s;
        int n = s.size();

        vi freq(n+1);
        ll csum = 0;
        ll res = 0;
        freq[0] = 1;

        for(auto a: s){
            csum+= a-'0';

            if(csum>=k)
                res+= freq[csum-k];
            
            freq[csum]++;
        }
        cout<<res<<endl;


    // }

    return 0;
}