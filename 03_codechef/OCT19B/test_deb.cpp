#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define sc1(x) cin>>x;
#define sc(x) scanf("%d\n" , &x);

int main(){

    ifstream cin("in.in");
    ofstream cout("out.in");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t , n , m , q, r , c;
    cin>>t;

    while(t--){
        // cin>>n;
        sc1(n);
        cin>>m;
        cin>>q;

        // initialize to 0
        int mat[n][m] = { };

        map<int, int> row_times; // row_times[1] = 5 i.e row 1 has appeared 5 times
        map<int, int> col_times;

        while(q--){
            cin>>r;
            cin>>c;
            r-=1; c-=1;
            row_times[r]++;
            col_times[c]++;
        }

        // iterate over all the row and increment their respectiev cols
        for(auto it = row_times.begin(); it!=row_times.end(); it++){
            int c_row = it->first;
            int times = it->second;
            // increment all cols of a row by times
            for(int j=0; j<m; j++) mat[c_row][j]+=times;
        }

        for(auto it = col_times.begin(); it!=col_times.end(); it++){
            int c_col = it->first;
            int times = it->second;
            // increment all row of a col by times
            for(int j=0; j<n; j++) mat[j][c_col]+=times;
        }

        // find total odd elements
        int odd_vals = 0;
        for(int i = 0; i<n; i++){
            for(int j=0 ; j<m; j++){
                // printf("%d ", mat[i][j]);/
                if (mat[i][j]%2) odd_vals+=1;
            }
            // cout<<endl;
        }
        // printf("%d\n", odd_vals);
        cout<<odd_vals;

    }

}