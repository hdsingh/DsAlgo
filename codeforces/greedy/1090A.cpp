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
    int n,m,sal;
    cin>>n;

    ll sz[n];
    ll mx[n];

    for(int i=0; i<n; i++){
        cin>>m;
        sz[i] = m;

        int m_sal = INT_MIN;
        for(int j=0; j<m; j++){
            cin>>sal;
            m_sal = max(m_sal, sal);
        }

        mx[i] = m_sal;
    }

    ll inc = 0;
    ll prev_m_sal = mx[0];
    ll prev_sz = sz[0];
    for(int i=1; i<n; i++){
        if(prev_m_sal<mx[i]){
            inc += (mx[i] - prev_m_sal) * prev_sz;
        }else if(prev_m_sal > mx[i]){
            inc += (prev_m_sal - mx[i]) *  sz[i];
        }
        prev_sz +=sz[i];
        prev_m_sal = max(prev_m_sal,mx[i]);
    }

    cout<<inc<<endl;

    return 0;
}