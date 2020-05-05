// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

int LIS1(vi &a){
    vi tail;
    for(auto x: a){
        auto it = lower_bound(all(tail), x);
        if(it==tail.end())
            tail.push_back(x);
        else 
            *it = x;
    }
    print(tail);
    return tail.size();
}

int LIS2(vi &a){
    multiset<int> S;
    for(auto x: a){
        S.insert(x);
        auto it = S.lower_bound(x); // will point to inserted element
        ++it;
        if(it!=S.end())
            S.erase(it);
    }
    print(S);
    return S.size();
}

// With better implementation using vector
int LISwithSeq(vi &a){
    int n = a.size();
    vi tail;
    vvi history;

    for(auto x: a){
        auto it = lower_bound(all(tail), x);
        if(it==tail.end()){
            tail.pb(x);
            history.pb(vi(1, x)); // opt
        }
        else{
            *it = x;
            history[it - tail.begin()].push_back(x); //opt
        }
    }
    // print(tail);

    int llen = tail.size(); //longest length

    print_vv(history); // each row will be in descending (non-inc) order
    // Optional to find seq;
    if(true){
        a.resize(llen);
        a.back() = tail.back();
        for (int i=llen-2; i>=0; i--) {
            auto it = lower_bound(history[i].rbegin(), history[i].rend(), a[i+1]);
            it --;
            a[i] = *it;
        }
        
        print(a); // longest inc sub seq
    }
    return llen;
}

int main(){
    vi seq;
    // seq = {2, 5, 3, 7, 11, 8, 10, 13, 6 };
    seq = {4,2,5,8,3,6,1,7,9};
    // seq = {0, 30, 16};
    seq = {8, 1, 9, 8, 3, 4, 6, 1, 5, 2};
    cout<<LISwithSeq(seq)<<endl;
    // deb(LIS2(seq));
    return 0;
}

// Ref:
// http://lightoj.com/article_show.php?article=1000&language=english&type=pdf

// Ex:
// https://atcoder.jp/contests/abc165/tasks/abc165_f