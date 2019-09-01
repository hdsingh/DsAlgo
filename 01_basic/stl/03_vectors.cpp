#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int> v;
    for (int i=1; i<5; i++)
        v.push_back(i*5);

    for(int x: v)
        cout<<x<<" ";
        cout<<endl;

    for(auto i=v.begin(); i!=v.end(); i++)
    {   int j = *i*100;
        cout<<j<<" ";
    }
    cout<<endl;

    for(auto i=v.begin(); i!=v.end(); i++)
    {   *i = *i*100;
        cout<<*i<<" ";
    }
    cout<<endl;

    for(auto i=v.rbegin(); i!=v.rend(); i++)
        cout<<*i<<" ";
        cout<<endl;

    for(auto i=v.crbegin(); i!=v.crend(); i++)
        cout<<*i<<" ";
        cout<<endl;
    
    vector<int> r;
    for (int i=1; i<=17; i++)
        r.push_back(i*5);

    cout<<"Loc 12: "<<r[12]<<endl;

    cout<<"Size: "<<r.size()<<endl;
    cout<<"Max Size: "<<r.max_size()<<endl;
    cout<<"Capacity: "<<r.capacity()<<endl;

    r.resize(5);
    for (int x: r) cout<<x<<" "; 
    cout<<endl;
    cout<<"Empty: "<<r.empty()<<endl;
    cout<<r.size()<<" "<<r.capacity()<<endl;
    r.shrink_to_fit();
    cout<<r.size()<<" "<<r.capacity()<<endl;

    cout<<r.front()<<endl;
}