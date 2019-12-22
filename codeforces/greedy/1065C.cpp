#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}

const int N = 2e5+10;

int main(){
    int n,k; 
    cin>>n>>k;
    int mi = INT_MAX;
    int mx = -1;

    vi C(N);
    int a;
    for(int i=1; i<=n; i++){
        cin>>a;
        mi = min(mi, a);
        mx = max(mx, a);
        C[a]++;
    }
    if(mi==mx){
        cout<<0<<endl;
        return 0;
    }
    for(int i=N-2; i>=1; i--){
        C[i] += C[i+1];
    }

    long long c = 0;
    int res = 1;

    for(int i=N-1; i>=mi+1; i--){
        if(c + C[i] > k){
            res++;
            c = 0;
        }
        c += C[i];
    }

    cout<<res<<endl;

    return 0;
}