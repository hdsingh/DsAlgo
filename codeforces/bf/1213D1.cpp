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
void showpq(priority_queue<int, vector<int>, greater<int>> pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main(){
    int n, k, x;
    while(cin>>n>>k){
        vi a(n);

        forn(i, n)
            cin>>a[i];
        
        sort(all(a));

        int min_ops = INT_MAX;
        fore(i,0, a[n-1]+1){
            priority_queue<int, vi, greater<int>> pq;
            fore(j, 0, n){
                int ops = 0;
                int cur = a[j];
                while(cur>i){
                    cur>>=1;
                    ops++;
                    // deb(cur);
                }

                if(cur==i){
                    // deb(cur);
                    pq.push(ops);
                    // showpq(pq);
                }
            }


            int tot_ops = 0;
            if(pq.size()>=k){
                forn(t, k){
                    tot_ops+=pq.top();
                    pq.pop();
                }
                min_ops = min(min_ops, tot_ops);
            }

        }
        cout<<min_ops<<endl;
    } 
    return 0;
}