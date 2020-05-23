#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

vi getRandSeq(int l, int r, int len){
    vi a(len);
    for(int i=0; i<len; ++i)
        a[i] = getRand(l,r);
    return a;
}

// not optimal
vi getUniqRandSeq(int l, int r, int len){
    if(r-l+1<len) return {};
    vi a(len);
    set<int> seen;
    for(int i=0; i<len; ++i) {
        a[i] = getRand(l,r);
        if(seen.count(a[i])) --i;
        else seen.insert(a[i]);
    }
    return a;
}

int main(){
    int n = 10;
    vi a = getUniqRandSeq(1,10,10);
    for(auto x: a) cout<<x<<" "; 
    cout<<"\n";
    return 0;
}