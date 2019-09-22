#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        if(mat.size()==0) return -1;
        vi mat_0 = mat[0];
        int found;
        for(int i=0; i<mat_0.size(); i++){
            found =1;
            for(int j= 0; j<mat.size(); j++){
                found*= binary_search(all(mat[j]), mat_0[i]);
                if(!found) break;
            }
            if(found) return mat_0[i];
        }

        return -1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {
        {1,2,3,4,5},
    };
    cout<<s.smallestCommonElement(mat);
}