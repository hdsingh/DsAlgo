#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

int main(){
    int n; 
    cin>>n;
    int a;
    if(n%2) a = 0;
    else a = pow(2, n/2);
    cout<<a;
    return 0;
}