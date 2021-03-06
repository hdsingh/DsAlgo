#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;

bool next_permutation1(string &a){
    int n = a.size();
    if(n==1) return false;
    // find the location of decreasing seq starts
    int i = n-1;
    while(i && a[i-1]>=a[i]) --i;
    
    if(i==0){
        reverse(all(a));
        return false;
    }
    --i;

    // find the element next to i from end, greater than a[i]
    int j = n-1;
    while(a[j]<=a[i]) --j;
    swap(a[i], a[j]);    

    reverse(a.begin()+i+1, a.end());
    return true;
}


void prev_perm(vi &a){
    int n = a.size();
    if(n==0) return;
    int pos = n-1;
    while(pos-1>=0 && a[pos-1]<=a[pos])
        --pos;
    if(pos==0){
        reverse(a.begin(), a.end());
        return;
    }
    --pos; // first point where seq is not inc.
    int next_smaller = n-1;
    while(pos<next_smaller && a[next_smaller]>=a[pos])
        --next_smaller;
    assert(a[next_smaller]<a[pos]);
    swap(a[pos], a[next_smaller]);
    reverse(a.begin()+pos+1, a.end());
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s = "aabac";
    
    sort(all(s));

    vs res;
    do{
        res.pb(s);
    }while(next_permutation1(s));
    cout<<sz(res)<<endl;
    for(auto x: res) cout<<x<<"\n";
    
    return 0;
}