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

int main(){
    int n, k;
    cin>>n>>k;
    vi a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    int cnt = 0; int j=0, ansl=0, ansr=0;

    for(int i=0; i<n; i++){
        if(j<i){
            cnt = 0; j=i;
        }

        while(j<n){
            int ncnt = cnt + !a[j];
            if(ncnt>k) break;
            cnt += !a[j];
            j++;
        }

        if(j-i > ansr - ansl){
            ansl = i; ansr = j;
        }

        if(cnt>0) cnt-= !a[i];
    }

    cout<<ansr-ansl<<endl;

    for(int i=ansl; i<ansr; i++)
        a[i] = 1;

    print(a);

    return 0;
}