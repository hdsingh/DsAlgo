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
        vector<pii> a(n); // beauty, len

        forn(i, n){
            cin>>a[i].second>>a[i].first;
        }

        sort(all(a));

        ll res = 0;
        ll sum = 0;
        priority_queue<int, vi, greater<int>> pq;
        for(int i=n-1; i>=0; i--){
            ll beauty = a[i].first;
            sum += a[i].second;
            pq.push(a[i].second);

            if(pq.size()>k){
                int x = pq.top(); pq.pop();
                sum-=x;
            }
            res = max(sum*beauty, res);

        }

        cout<<res<<endl;

        

    }
    return 0;
}