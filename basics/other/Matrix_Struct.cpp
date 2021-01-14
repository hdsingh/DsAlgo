#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
const int mod = 1e9 + 7;

class Matrix{
public:
    int n; // size of Matrix
    vector<vector<ll>> a;
    Matrix(int N){
        n = N;
        a.assign(n, vl(n));
    }

    void makeIdentity(){
        a.assign(n, vl(n));
        forn(i,n) a[i][i] = 1;
    }

    Matrix operator*(const Matrix &oth) const{
        Matrix res(n);
        forn(i,n) forn(k,n) forn(j,n){
            res.a[i][j] = (res.a[i][j] + a[i][k]*oth.a[k][j])%mod;
        }
        return res;
    }

    Matrix operator+(const Matrix &oth) const{
        Matrix res(n); 
        forn(i,n) forn(j,n){
            res.a[i][j] = a[i][j] + oth.a[i][j];
            if(res.a[i][j]>=mod) res.a[i][j]-=mod;
        }   
        return res;
    }
};

Matrix pow(Matrix a, ll p){
    Matrix c(a); c.makeIdentity();
    while(p){
        if(p&1) c = c*a;
        a = a*a;
        p>>=1;
    }
    return c;
}


// https://codeforces.com/gym/102644/ (by Errichto)
// https://codeforces.com/problemset/problem/678/D
// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/B