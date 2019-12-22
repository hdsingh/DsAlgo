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
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;

        int mcut = INT_MIN;
        int mdown = INT_MIN;
        for(int i=0; i<n; i++){
            int a, b;
            cin>>a>>b;
            mdown = max(a, mdown);
            int cut = a-b;
            mcut = max(cut, mcut);
        }
        // deb(mcut);
        // deb(mdown);

        if(x<=mdown)
            cout<<1<<endl;
        else if(mcut<=0)
            cout<<-1<<endl;
        else{
            int slay = (x-mdown)/mcut;
            x-= slay*mcut;
            if(x>mdown) slay++;
            slay++;

            cout<<slay<<endl;
        }
    }
    return 0;
}