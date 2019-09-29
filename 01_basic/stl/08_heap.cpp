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


int main(){
    vi v = {6,1,4,2,9,7,3,5};
    make_heap(v.begin(), v.end());
    sort_heap(all(v));
    print(v);
    v.push_back(11);
    push_heap(all(v));
    print(v);
    is_heap(all(v))? cout<<"yes": cout<<"no";
    cout<<endl;
    sort_heap(all(v));
    print(v);

    // pop_heap(v.begin(), v.end());
    // push_heap(all(v));
    // print(v);

    // min heap
    v = {6,1,4,2,9,7,3,5};
    make_heap(v.begin(), v.end(), greater<int>());
    print(v);
}