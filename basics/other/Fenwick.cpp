#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
typedef vector<int> vi;

class Fenwick{
public:
    int n;
    vi ft;

    Fenwick(int _n){
        n = _n+1;
        ft.assign(n,0);
    }

    void update(int idx, int val){
        while(idx<n){
            ft[idx]+=val;
            idx+= idx & -idx;
        }
    }

    int pref(int idx){
        int ans = 0;
        while(idx>0){
            ans+=ft[idx];
            idx-= idx & -idx;
        }
        return ans;
    }

    int query(int l, int r){
        return pref(r) - pref(l-1);
    }

    int lowerBound(int req){
        int cur = 0, prevsum = 0;
        for(int i=log2(n); i>=0; --i){
            int next = cur + (1<<i);
            if(next < n && ft[next] + prevsum < req){
                cur = next;
                prevsum+=ft[cur];
            }
        }
        return (cur+1);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    while(cin>>n>>q){
        vi a(n); forn(i,n) cin>>a[i];
        Fenwick ft(n);
        forn(i,n){
            ft.update(a[i],1);
        }
        // print(ft.ft,1);
        while(q--){
            int x; cin>>x;
            if(x<0){
                int idx = ft.lowerBound(abs(x));
                ft.update(idx,-1);
            }else{
                ft.update(x, 1);
            }
        }
        int idx = ft.lowerBound(1);
        if(idx>n) idx = 0;

        cout<<idx<<"\n";
    } 
    return 0;
}

// https://codeforces.com/problemset/problem/1354/D
// https://atcoder.jp/contests/abc174/tasks/abc174_f
