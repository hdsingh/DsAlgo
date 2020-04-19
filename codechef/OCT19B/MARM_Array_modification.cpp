#include <bits/stdc++.h>
using namespace std;

void custom_xor(int n, int k, vector<int> &A){
    
    // cout<<"n:"<<n<<" k:"<<k<<endl;
    // for(int x: A) cout<<x<<" ";
    // cout<<endl;
    
    
}

int main(){
    int t, n, k;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d ", &n);
        scanf("%d ", &k);
        vector<int> A(n);
        for(int i=0; i<n; i++) scanf("%d ", &A[i]);
        
        for(int i=0; i<k; i++)
        A[i%n] = A[i%n] ^ A[n-(i%n)-1];
    
        for(int i=0; i<n; i++) printf("%d ", A[i]);

    }
}

// int main(){
//     cout<<132<<endl;
//     for(int i=2; i<10; i++){
//         vector<int> A(i);
//         for(int k=1; k<=i; k++) A[k] = rand()%9 + 1;
//         for(int j = 1; j<=i*3; j++){
//             cout<<i<<" "<<j<<endl;
//             for(int k=1; k<=i; k++) cout<<A[k]<<" ";
//             cout<<endl;
//         }
//     }
// }