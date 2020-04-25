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

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int n = arr.size();
        if(n<=2) return arr;
        bool changed = true;

        // print(arr);
        while(changed){
            vector<int> new_arr = arr;
            changed = false;
            for(int i=1; i<n-1; i++){
                if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
                    new_arr[i]+=1;
                    changed=true;
                }
                else if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                    new_arr[i]-=1;
                    changed=true;
                }
            }
            // print(new_arr);
            arr = new_arr;
        }
        
        return arr;
    }
};

int main(){
    Solution s;
    vi arr = {1,6,3,4,3,5};
    // arr = {6,2,3,4};
    // arr = {3,1,2};
    // arr = {2,1,2,1,1,2,2,1};
    // arr = {6,5,8,6,7,7,3,9,8,8,3,1,2,9,8,3}; //[6,6,7,7,7,7,7,8,8,8,3,2,2,8,8,3]
    s.transformArray(arr);
    // print(arr);
    return 0;
}