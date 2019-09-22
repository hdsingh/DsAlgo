#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef pair<int, int> pii;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

bool cmp(pii a, pii b){
    return a>b;
}

int main(){
    pair<int, int> a[1001];
    int i(1), n;
    scanf("%d\n", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a+1, a+1+n, cmp);
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans+=a[i].first*(i-1)+1;
    }
    cout<<ans<<endl;

    for(int i=1; i<=n; i++){
        cout<<a[i].second<<" ";
    }

}