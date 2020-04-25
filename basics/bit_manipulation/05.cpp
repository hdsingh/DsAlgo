#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

// Get  rightmost significant bit in a num

int main(){
    int a = 20;
    cout<<bitset<16>(a)<<endl;

    // 1. Using ffs
    cout<<ffs(a)-1<<endl;

    // 2.
    int pos_set = 0; // rightmost pos which is set in xor
        while(!(a&1)){
            pos_set++;
            a>>=1;
        }
    
    cout<<pos_set<<endl;
 

}