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

#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ret(1 << n);

        REP(i, (1 << n)) ret[i] = i ^ (i >> 1);
        print(ret);

        REP(i, 1 << n) ret[i] ^= start;

        return ret;
    }
};

int main(){
    Solution s;
    vi out = s.circularPermutation(3, 2);
    // print(out);

    int i =1, n=10;
    fo(i, n) cout<<i<<" "<<(i^(i>>2))<<" "<<endl;
    cout<<endl;

    // i =1, n=10;
    // fo(i, n) cout<<i<<" "<<(3^i)<<" "<<endl;
    
}
