#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9 + 5;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

int main(){
    int n; 
    while(cin>>n){
        set<int> idx;
        vi a(n+1);
        vi nums(n+1);
        
        int x;
        for(int i=1; i<n+1; i++){
            cin>>x;
            a[i] = x;
            nums[x] = 1;
            if(!x) idx.insert(i);
        }

        unordered_set<int> misn;

        for(int i=1; i<=n; i++){
            if(!nums[i])
                misn.insert(i);
        }


        vi same;
        vi todel;
        for(int num: misn){
            // cout<<num<<endl;
            if(idx.find(num)!=idx.end()){
                same.push_back(num);
                // misn.erase(num);
                todel.push_back(num);
                idx.erase(num);
            }
        }
        for(auto z: todel)
            misn.erase(z);

        if(same.size()==1){
            int s = *same.begin();
            int ix = *idx.begin();
            int num = *misn.begin();
            a[s] = num;
            a[ix] = s;
            misn.erase(num);
            idx.erase(ix);
            same.pop_back();
        }

        int sz = same.size();
        for(int i=0; i<sz; i++){
            a[same[i]] = same[(i+1)%sz ];
        }


        vi ixx(idx.begin(), idx.end());
        vi mis(misn.begin(), misn.end());

        sz = mis.size();
        for(int i=0; i<sz; i++){
            a[ixx[i]] = mis[i];
        }

        for(int i=1; i<=n; i++){
            printf("%d ", a[i]);
        }
        cout<<endl;
    }
    return 0;
}