#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}

int main1(){
    auto cmp1 = [](int a, int b){
        return a>b;
    };
    vi a = {5,2,5,3,1,4};
    set<int, decltype(cmp1)> s(cmp1);
    s.insert(all(a));
    print(vi(all(s)));

    auto cmp2 = [](pair<int, char> p1, pair<int,char> p2){
        return p1.first>p2.first;
    };

    // Sort based on greater freq
    set<pair<int, char>, decltype(cmp2)> info(cmp2);
    info.insert({10,'a'});
    info.insert({1,'b'});
    info.insert({8,'z'});

    for(auto p: info)
        cout<<p.first<<": "<<p.second<<"  ";
    cout<<endl;

    return 0;
}

// method 1
struct cmp1{
    bool operator()(const pii &p1, const pii &p2) const{
        int len1 = p1.second - p1.first + 1;
        int len2 = p2.second - p2.first + 1;
        if(len1==len2)
            return p1.first<p2.first;
        return len1>len2;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    
        n = 10;
        vi a(n+1);

        int val = 1;

        // method 1
        // set<pii, cmp1> s;

        // method 2
        auto cmp = [&](const pii &p1, const pii &p2){
            int len1 = p1.second - p1.first + 1;
            int len2 = p2.second - p2.first + 1;
            if(len1==len2)
                return p1.first<p2.first;
            return len1>len2;
        };

        set<pii, decltype(cmp)> s(cmp);


        s.insert({1,n});
        
        while(!s.empty()){
            pii top = *s.begin(); s.erase(s.begin());
            int mid = (top.first + top.second)/2;
            a[mid] = val++;
            int l1,r1,l2,r2;
            l1 = top.first; r1 = mid - 1;
            l2 = mid + 1; r2 = top.second;
            if(l1<=r1) s.insert({l1,r1});
            if(l2<=r2) s.insert({l2,r2});
        }
        fore(i,1,n+1) cout<<a[i]<<" ";
        cout<<endl;

    return 0;
}

// ref:
// https://codeforces.com/contest/1353/problem/D