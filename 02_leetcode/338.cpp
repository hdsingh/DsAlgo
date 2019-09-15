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
    vector<int> countBits(int num) {
        vi out;
        for(int i=0; i<=num; i++){
            out.push_back(__builtin_popcount(i));
        }
        return out;
    }
};


int main(){
    Solution s;
    p_vec(s.countBits(50));
    int i;
    fo(i, 50)
        cout<<i%10<<" ";
}