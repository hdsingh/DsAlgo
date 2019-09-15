#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

void p_vec(vi v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        vi res;
        if  (!arr.size()) return 0;
        int i;
        fo(i, k)
            res.insert(res.end(), all(arr));
        
        p_vec(res);
        
        int c_max = res[0];
        int max_sf = res[0];
            
        for(int i=1; i<res.size(); i++){
            c_max = max(res[i], c_max+res[i]);
            max_sf = max(max_sf, c_max);
            deb(i);
            deb(c_max);
            deb(max_sf);
            cout<<'\n';
        }

        return max_sf>0 ? max_sf:0;

    }
};

int main(){
    Solution s;
    vi v = {-1,-2};
    int k = 3;
    cout<<s.kConcatenationMaxSum(v, k);

}