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
        cout<<setw(2)<<*i<<" ";
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
    int n, a;
    while(cin>>n){
        map<int,int, greater<int>> m;
        for(int i=0; i<n*n; i++)
            cin>>a, m[a]++;
        
        vi nums;
        while(nums.size()!=n){
            int gr =m.begin()->first;
            m[gr]--;
            if(m[gr]==0) m.erase(gr);

            for(auto a: nums){
                int gcd = __gcd(a,gr);
                m[gcd]-=2;
                if(m[gcd]==0) m.erase(gcd);
            }
            nums.push_back(gr);
        }


        for(auto a: nums)
            cout<<a<<" ";
        cout<<endl;
    }
    
    return 0;
}