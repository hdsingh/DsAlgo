#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}

int main(){
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