#include <bits/stdc++.h>
using namespace std;

#define deb(x) std::cout << #x <<  " " << x << '\n';
#define fo(i,n) for(i=0;i<n;i++)
#define REP(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        std::cout<<*i<<" ";
    std::cout<<'\n'; 
}

template <typename T>
void print1(T m){
    for(auto i = m.begin(); i!=m.end(); i++){
        cout<<i->first<<" : "<<i->second<<", ";
    }
    cout<<endl;
}

void print_vvi(vector<vi> v){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<v[i][j]<<",";
        }
        cout<<"},";
    }
    cout<<endl;
}