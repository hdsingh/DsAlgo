#include <bits/stdc++.h>
using namespace std;

template <typename T>
void show(T X){
    for(auto i: X)
        cout<<i<<" ";
    cout<<endl;
}


int main(){
    map<char, int> m;
    m['c'] = 1;
    m['d'] = 2;
    for(auto i = m.begin(); i!=m.end(); i++)
        cout<<i->first<<" : "<<i->second<<endl;

    // multimap<char, greater<int>> m;
	// string x  = "aaa bb ccccc a";
	
	// for(char c: x){
	// 	m[c]++;
	// }
    // cout<<endl;
    // for(auto i = m.begin(); i!=m.end(); i++)
    //     cout<<i->first<<" : "<<i->second<<endl;


}