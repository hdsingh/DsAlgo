#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d\n", &t);
    while(t--){
        int n;
        scanf("%d\n", &n);

        string s;
        int res = 0;
        while(n--){
            getline(cin, s); 
            res^=bitset<10>(s).to_ulong();
        }

        int final = bitset<10>(res).count();
        printf("%d\n", final);

    }
    return 0;
}