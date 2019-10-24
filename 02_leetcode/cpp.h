#include <bits/stdc++.h>
using namespace std;
#include <unistd.h> //for usleep()

#define deb(x) std::cout << #x <<  " " << x << '\n';
#define fo(i,n) for(i=0;i<n;i++)
#define REP(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;

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


template <typename T>
void print_vv(T v){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<v[i][j]<<",";
        }
        cout<<"},"<<endl;
    }
    cout<<endl;
}
