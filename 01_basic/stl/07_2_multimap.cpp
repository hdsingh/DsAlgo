#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout<<#x<<" "<<x<<endl;

template <class T, class U> void print_m(multimap<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

int main(){
    multimap<int,int> m;
    m.insert({1,10});
    m.insert({2,20});
    m.insert({2,100});
    m.insert({3,40});

    print_m(m);
    auto it = m.equal_range(2);
    for(auto nit = it.first; nit!=it.second; nit++){
        int val = nit->second;
        deb(val);
    }
    cout<<endl;

    // delete a particular key,val
    for(auto nit = it.first; nit!=it.second; nit++){
        if(nit->second==100)
            m.erase(nit);
    }
    print_m(m);

    return 0;
}