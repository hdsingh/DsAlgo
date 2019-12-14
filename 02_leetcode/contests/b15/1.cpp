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

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int m = n/4;
        int ans;
        map<int,int> count;
        for(auto &a: arr){
            count[a]++;
            if(count[a]>m){
                ans=a;
                break;
            }

        }
        return ans;

    }
};

int main(){
    Solution sol;
    vi arr = {1,2,2,6,6,6,6,7,10};
    cout<<sol.findSpecialInteger(arr);
    return 0;
}