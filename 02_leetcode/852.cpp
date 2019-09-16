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
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int cmax(INT_MIN), imax(0);
        for(int i=1; i<n-1; i++){
            if (A[i-1]<A[i] && A[i]>A[i+1]){
                if(A[i]>cmax){
                    cmax=A[i];
                    imax = i;
                }
            }
        }
        return imax;
    }
};

int main(){
    Solution s;
    vi v = {1,2,3,1};
    cout<<s.peakIndexInMountainArray(v);
}