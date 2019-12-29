#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 5;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> out;
        if(n&1){
            out.push_back(0);
            n--;
        }

        for(int i=1; i<=(n/2); i++){
            out.push_back(-i);
            out.push_back(i);
        }
    return out;
    }
};

int main(){
    Solution sol;
    vi out;
    out = sol.sumZero(5);
    print(out);
    out = sol.sumZero(3);
    print(out);
    out = sol.sumZero(1);
    print(out);
    out = sol.sumZero(0);
    print(out);
    
    return 0;
}