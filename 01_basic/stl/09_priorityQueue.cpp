#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

void showpq(priority_queue<int, vector<int>, greater<int>> pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}


int main(){
    vi v = {6,8,4,3,7,5};
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int x: v){
        pq.push(x);
        showpq(pq);
    }

}