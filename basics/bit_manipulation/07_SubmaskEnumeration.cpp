#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;

int main(){
    int mask = 7;
    bitset<5> b(mask);
    // deb(b);
    // for(int sub = mask; sub; sub = (sub-1)&mask){
    //     bitset<5> a(sub);
    //     deb(a);
    // }
    
    // If zero is also required, then better implementation
    for(int sub = mask; ; sub = (sub-1)&mask){
        bitset<5> a(sub);
        deb(a);
        
        if(sub==0) break;
    }
    return 0;
}

// https://leetcode.com/problems/minimum-incompatibility/