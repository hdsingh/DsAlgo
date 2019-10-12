#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
#define line() cout<<endl;
typedef vector<int> vi;

void p_vec(vi v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

class Solution {
public:
    int findPeakElement(vector<int> num) {
        int low = 0;
        int high = num.size()-1;
        
        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(num[mid1] < num[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;

    }
};

int main(){
    Solution s;
    map<vi, int> ex = {
        // {{3,2,1}, 0},
        {{4,2,3,1}, 0},
        // {{1},0},
        // {{1,2},1},
        // {{2,1},0},
        // {{1,2,3,1}, 2},
        // {{1,2,1,3,5,6,4}, 5},
    };
    int all_pass = 1;
    for(auto e= ex.begin(); e!=ex.end(); e++){
        p_vec(e->first);
        int out = s.findPeakElement(e->first);
        string res = (e->second ==out) ? "p ":"f ";
        if (res=="f ") all_pass=0;
        cout<<res<<" a:"<<e->second<<"  o:"<<out<<endl;
        line();
    }
        cout<<"all_pass:"<<all_pass<<endl;

}