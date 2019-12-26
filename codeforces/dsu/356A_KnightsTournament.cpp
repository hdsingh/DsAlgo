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
const int inf = 1e9;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

int main(){
    int n, m;
    while(cin>>n>>m){
        set<int> alive;
        for(int i=1; i<=n; i++)
            alive.insert(i);
        
        vector<int> ans(n+1);

        int l,r,w;
        for(int i=0; i<m; i++){
            cin>>l>>r>>w;

            auto lt = alive.lower_bound(l);
            auto rt = alive.upper_bound(r);

            for(auto it = lt; it!=rt; it++){
                int cur = *it;
                if(cur!=w)
                    ans[cur] = w;
            }

            alive.erase(lt,rt);
            alive.insert(w);
        }


        // for(int i=0; i<m; i++){
        //     cin>>l>>r>>w;

        //     auto it = alive.lower_bound(l);
        //     vi toErase;
        //     while(it!=alive.end()){
        //         int cur = *it;
        //         if(cur>r) break;

        //         if(cur!= w){
        //             toErase.push_back(cur);
        //             ans[cur] = w;
        //         }

        //         it++;
        //     }

        //     for(int x: toErase)
        //         alive.erase(x);
        // }

        for(int i=1; i<=n; i++)
            cout<<ans[i]<<" \n"[i==n];

    }
    
    return 0;
}