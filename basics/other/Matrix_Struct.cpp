#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
typedef long long ll;
typedef vector<int> vi;
const int mod = 1e9 + 7;


const int N = 2; // size of matrix
struct matrix{
    ll arr[N][N];  
    void reset(){
        memset(arr, 0, sizeof(arr));
    }

    void makeIdentity(){
        reset();
        forn(i,N) arr[i][i] = 1;
    }

    matrix operator+(const matrix &oth) const{
        matrix res; 
        forn(i,N) forn(j,N){
            res.arr[i][j] = arr[i][j] + oth.arr[i][j];
            if(res.arr[i][j]>=mod) res.arr[i][j]-=mod;
        }   
        return res;
    }

    matrix operator*(const matrix &oth) const{
        matrix res; res.reset();
        forn(k,N) forn(i,N) forn(j,N){
            (res.arr[i][j]+=arr[i][k]*oth.arr[k][j]%mod)%=mod;
        }
        return res;
    }
};

matrix pow(matrix a, ll p){
    matrix c; c.makeIdentity();
    while(p){
        if(p&1) c = c*a;
        a = a*a;
        p>>=1;
    }
    return c;
}


int main(){
    ll a,b,n,x;
    while(cin>>a>>b>>n>>x){
        matrix ans;
        ans.arr[0][0] = a, ans.arr[0][1] = b;
        ans.arr[1][0] = 0, ans.arr[1][1] = 1;
        ans = pow(ans,n);
        ll res = (ans.arr[0][0]*x + ans.arr[0][1])%mod;
        cout<<res<<endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/678/D
// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/B