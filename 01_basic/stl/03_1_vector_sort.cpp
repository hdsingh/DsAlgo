#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<setw(2)<<*i<<" ";
    cout<<endl; 
}

bool comp_by_asc_keys(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first;
}

bool comp_by_dsc_keys(const pair<int,int> &a, const pair<int,int> &b){
    return a.first > b.first;
}

bool comp_by_asc_vals(const pair<int,int> &a, const pair<int,int> &b){
    return a.second < b.second;
}

bool comp_by_dsc_vals(const pair<int,int> &a, const pair<int,int> &b){
    return a.second > b.second;
}


int main(){
    // sorting  // key, value
    vector<pair<int, int>> arr = {{600,7},{100, 10}, {200,5}};
    
    vector<pii> a1 = arr;
    sort(a1.begin(),a1.end(), comp_by_asc_keys);
    for(auto z: a1)
        cout<<z.first<<": "<<z.second<<endl;
    cout<<endl; 

    sort(a1.begin(),a1.end(), comp_by_dsc_keys);
    for(auto z: a1)
        cout<<z.first<<": "<<z.second<<endl;

    cout<<endl;

    sort(a1.begin(),a1.end(), comp_by_asc_vals);
    for(auto z: a1)
        cout<<z.first<<": "<<z.second<<endl;
    cout<<endl;

    sort(a1.begin(),a1.end(), comp_by_dsc_vals);
    for(auto z: a1)
        cout<<z.first<<": "<<z.second<<endl;
    cout<<endl;

    // Custom comparator
    sort(a1.begin(),a1.end(), [](pii &a, pii &b){return a.first < b.first;} );
    for(auto z: a1)
        cout<<z.first<<": "<<z.second<<endl;
    cout<<endl;


    return 0;
}