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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";}cout<<endl;for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

int ceilIndex(vi &tail, int l, int r, int key){
    while(l+1<r){
        int m = l + (r-l)/2;
        if(tail[m]>=key)
            r = m;
        else 
            l = m;
    }
    return r;
}


int LIS_simple(vi &v){
    int n = v.size();
    if(n==0) return 0;
    
    int len = 1;
    vi tail(n);
    tail[0] = v[0];

    fore(i, 1, n){
        
        // new smallest value
        if(v[i]<tail[0])
            tail[0] = v[i];
        
        // v[i] extends largest segment
        else if(v[i]>tail[len-1])
            tail[len++] = v[i];
        
        // do binary search and find the ceilIndex for v[i]
        // ex: 1 3 7 9 5
        // Here for 5 the lis will have any element lesser than 5 in it before adding 5
        // So search for 4,3,2, what ever is the greatest element smaller than v[i];
        // and add the v[i] at its ceil/next index;

        else 
            tail[ceilIndex(tail, 0, len-1, v[i])] = v[i];
        
        // print(tail);
    }
    
    // forn(i, len)
    //     cout<<tail[i]<<" ";
    // cout<<endl;
    return len;    
}

// with STL
int LIS1(vi &a){
    int n = a.size();
    vi tail(n);

    tail[0] = a[0];
    int len = 1;
    fore(i, 1, n){
        auto b = tail.begin(), e = tail.begin()+len;
        auto it = lower_bound(b, e, a[i]); //first eq or greater than
                // upper_bound for longet non decreaing sub seq

        
        if(it==e) // if not found inc len and insert at end
            tail[len++] = a[i];
        else 
            *it = a[i]; // change to new lesser element a[i]       
    }

    return len;
}

// With better implementation using vector
int LIS(vi &a){
    int n = a.size();
    vi tail;

    fore(i, 0, n){
        auto it = lower_bound(all(tail), a[i]);
        if(it==tail.end())
            tail.pb(a[i]);
        else 
            *it = a[i];
    }
    print(tail);
    return tail.size();
}

int LIS2(vi &a){
    int n = a.size();

    multiset<int> S;
    fore(i, 0, n){
        S.insert(a[i]);
        auto it = S.lower_bound(a[i]); // will point to inserted element
        it++;
        if(it!=S.end())
            S.erase(it);
    }
    for(auto x: S)
        cout<<x<<" ";
    cout<<endl;
    return S.size();
}


int LIS3(vi &a){
    int n = a.size();

    multiset<int> S;
    fore(i, 0, n){
        auto it = S.lower_bound(a[i]); // will point to inserted element
        if(it==S.end()){
            S.insert(a[i]);
        }else{

        }

    }
    for(auto x: S)
        cout<<x<<" ";
    cout<<endl;
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

    print_vv(history);
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
    cout<<LISwithSeq(seq)<<endl;
    return 0;
}