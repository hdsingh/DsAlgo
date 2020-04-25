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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

// lower_bound: first_equal_to_or_greater_than (not less)
// upper_bound: first greater than

template<typename ForwardIterator, typename T>
ForwardIterator first_less_than(ForwardIterator first, ForwardIterator last, T value){
    auto it = lower_bound(first, last, value);
    return (it!=first ? --it : last);
}

int main(){
    vi a = {1,3,3,5,7};
    auto it = lower_bound(all(a), 3);
    cout<<(it !=a.end() ? to_string(*it) : "Not Found")<<endl;
    cout<<distance(a.begin(), it)<<endl<<endl; // ) based indexing

    it = lower_bound(all(a), 6);
    cout<<(it !=a.end() ? to_string(*it) : "Not Found")<<endl;
    cout<<distance(a.begin(), it)<<endl<<endl;

    it = upper_bound(all(a), 3);
    cout<<(it !=a.end() ? to_string(*it) : "Not Found")<<endl;
    cout<<distance(a.begin(), it)<<endl<<endl;
    
    // First less than
    it = first_less_than(all(a), 3);
    cout<<(it !=a.end() ? to_string(*it) : "Not Found")<<endl;
    cout<<distance(a.begin(), it)<<endl<<endl;

    return 0;
}