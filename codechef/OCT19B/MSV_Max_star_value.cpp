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

int main(){
    int t, n;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        vi A(n);
        for(int i=0; i<n; i++) scanf("%d ", &A[i]);

        int max_star = 0;
        int cur_star;
        for(int i=1; i<n; i++){
            cur_star=0;
            for(int j=0; j<i; j++){
                if(!(A[j]%A[i])) cur_star++;
            }
            max_star = max(cur_star, max_star);
        }
        printf("%d\n", max_star);
    }
}