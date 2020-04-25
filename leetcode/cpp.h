#include <bits/stdc++.h>
using namespace std;
#include <unistd.h> //for usleep()

#define deb(x) std::cout << #x <<  " " << x << '\n';
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<vector<string>> vvs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
const int inf = 1e9;

template <typename T>
void print(T v){
    if(!v.size()) {
        cout<<"Empty"<<endl;
        return;
    }
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

void print_pq(priority_queue<int> pq){
    while(pq.size()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}