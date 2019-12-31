#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

int main(){
    int n, k;
    while(cin>>n>>k){
        int mi = __builtin_popcount(n);
        bool yes = (mi<=k &&  k<= n) ? true : false;

        if(yes){
            cout<<"YES"<<endl;
            map<int,int> m;
            for(int i=0; i<=32; i++){
                if(n & (1<<i)){
                    // cout<<(1<<i)<<endl;
                    m[(1<<i)] = 1;
                }
            }
            
            int cnt = m.size();
            while(cnt!=k){
                // deb(m.size());
                auto a = max_element(m.begin(), m.end());
                if(a->second == 0){
                    m.erase(a);
                }
                int mx = a->first;
                int half = (mx>>1);
                m[half]+=2;
                m[mx]--;
                cnt++;
                if(m[mx]==0)
                    m.erase(a);
            }

            for(auto a: m){
                int x = a.first;
                int c = a.second;

                forn(i, c)
                    printf("%d ", x);
            }
            cout<<endl;

        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}