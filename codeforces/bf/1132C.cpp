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

// Approach: Try removing all the possible pairs in O(n^2)
int main(){
    int n, q;
    while(cin>>n>>q){
        vector<pii> intervals(q);
        vi cnt(n); // times a section is painted
        for(auto &p: intervals){
            cin>>p.first;
            cin>>p.second;
            --p.first;
            --p.second;

            fore(i, p.first, p.second+1)
                ++cnt[i];
        }

        int ans = 0;
        forn(A, q){
            // Remove the painter A
            fore(i, intervals[A].first, intervals[A].second+1)
                --cnt[i];
            
            int cnt_positive = 0; // painted area after removing A
            vi ones(n);

            forn(i, n){
                if(cnt[i]>0)
                    ++cnt_positive;
                if(cnt[i]==1)
                    ++ones[i];
            }

            // Accumulate ones
            fore(i,1, n){
                ones[i] += ones[i-1];
            }

            auto get_sum = [&](int l, int r){
                return ones[r] - (l ? ones[l-1] : 0);
            };

            // Remove B and check the painted area
            fore(B, A+1, q){
                int lost_ones = get_sum(intervals[B].first, intervals[B].second);
                ans = max(ans, cnt_positive - lost_ones);
            }

            // Restore the painter A
            fore(i, intervals[A].first, intervals[A].second+1)
                ++cnt[i];
        }

        cout<<ans<<endl;
    }
    
    return 0;
}