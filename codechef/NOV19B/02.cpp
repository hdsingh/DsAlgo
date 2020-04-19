#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}


int main(){
    int n = 128;
    vi seq(n+1);
    vvi rep(n);

    seq[1]=0;
    rep[0].push_back(1);

    for(int i=2; i<=n; i++){
        int l = i-1;
        int x = seq[l];

        if(rep[x].size()<2){
            seq[i] = 0;
            rep[0].push_back(i);
        }
        else{
            int k = rep[x].end()[-2];
            int next = l - k;
            seq[i] = next;
            rep[next].push_back(i);
        }
    }

    int t, N;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &N);
        
        int x = seq[N];
        int count = 0;

        for(int a: rep[x]){
            if(a<=N)
                count++;
            else break;
        }

        printf("%d\n", count);
    }

    return 0;
}