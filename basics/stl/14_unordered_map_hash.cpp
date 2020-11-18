#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct myhash {
    int operator()(const pair<int,int>& p) const {
        return p.first ^ p.second * 3; // define custom hash
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unordered_map<pii, int, myhash> cnt;
    vector<pii> a = {{1,1},{2,2},{3,3},{1,1},{1,1}};
    for(auto p: a){
        cnt[p]++;
    }
    for(auto [p,c]: cnt){
        cout<<p.first<<" "<<p.second<<" :"<<c<<"\n";
    }
    return 0;
}