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
const int inf = 1e9;

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

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

// Recursive
class Solution1{
public:
    int maxProfit(vi prices){
        int n =prices.size();
        return profit(0, n-1, prices, n);
    }

    int profit(int l, int r, vi &prices, int &n){
        if(l>r) return 0;

        int year = n-r+l;

        return max(year*prices[l] + profit(l+1, r, prices, n),
                   year*prices[r] + profit(l, r-1, prices, n));

    }
};

// Recursive + Memo
class Solution2{
public:
    int maxProfit(vi prices){
        int n =prices.size();
        vvi cache(n, vi(n,-1));
        return profit(0, n-1, prices, n, cache);
    }

    int profit(int l, int r, vi &prices, int &n, vvi &cache){
        if(l>r) return 0;

        if(cache[l][r]!=-1) return cache[l][r];

        int year = n-r+l;

        return cache[l][r] = max(year*prices[l] + profit(l+1, r, prices, n, cache),
                   year*prices[r] + profit(l, r-1, prices, n, cache));

    }
};

int main(){
    Solution2 sol;
    vi prices;
    cout<<sol.maxProfit({2, 4, 6, 2, 5 })<<endl;
    return 0;
}