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
    vector<int> sequentialDigits(int low, int high) {
        vi arr;
        for(int i=1; i<=9; i++){
            int val= 0;
            for(int j=i; j<=9; j++){
                val = val*10 + j;
                if(val>=low && val<=high)
                    arr.push_back(val);
            }
        }

        sort(arr.begin(), arr.end());
        return arr;
    }
};

int main(){
    Solution sol;
    vi arr = sol.sequentialDigits(100, 300);
    print(arr);

    arr = sol.sequentialDigits(1000, 13000);
    print(arr);


    
    return 0;
}