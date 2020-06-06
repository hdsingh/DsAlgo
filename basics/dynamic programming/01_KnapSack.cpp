// Refer: https://www.youtube.com/watch?v=xCbYmUPvc2Q
// Refer: https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int knapSack(int W, int wt[], int val[], int n){

    int i,w;
    int K[n+1][W+1]; //KnapSack table

    for(i=0; i<=n; i++){
        for(w=0; w<=W; w++){
            if(i==0 || w==0)
                K[i][w]=0;
            else if(wt[i-1]<=w)
                K[i][w] = max(K[i-1][w], val[i-1] + K[i-1][ w - wt[i-1] ]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

// wt[i-1] is w[i] (0 indexing)
// val[i-1] is val[i] (0 indexing)
// Include the element or not
// if not to include then use the value at previous weight
// else use the value at its weight and value of remaining weight

// max(K[i-1][w],               
// vals of previous weight,

// val[i-1] + K[i-1][ w - wt[i-1] ]);
// value of item i + value remaining after using weight of item i

int knapSackwithSTL(int W, vi &wt, vi &val, int n){

    int i,w;
    vector<vi> dp(n+1, vi(W+1, 0));
    // int K[n+1][W+1]; //KnapSack table

    for(i=0; i<=n; i++){
        for(w=0; w<=W; w++){
            if(i==0 || w==0)
                dp[i][w]=0;
            else if(wt[i-1]<=w)
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][ w - wt[i-1] ]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

// O(nW) time, O(nW) space
int knapSackwithSTL2(int W, vi &wt, vi &val, int n){

    int i,w;
    vector<vi> dp(n+1, vi(W+1, 0));

    for(i=1; i<=n; i++){
        for(w=1; w<=W; w++){
            dp[i][w] = dp[i-1][w];
            if(wt[i-1]<=w)
                dp[i][w] = max(dp[i][w], val[i-1] + dp[i-1][ w - wt[i-1] ]);                
        }
    }
    return dp[n][W];
}

// O(nW) time, O(W) space
int knapSackwithSTL3(int W, vi &wt, vi &val, int n){

    int i,w;
    vi dp(W+1, 0);

    for(i=0; i<n; i++){
        for(w=W; w>=wt[i]; w--){
            dp[w] = max(dp[w], val[i] + dp[ w - wt[i] ]);                
        }
    }
    return dp[W];
}

int main(){
    // int val[] = {60, 100, 120};
    // int wts[]  = {10, 20,  30 };
    // int W = 50;

    // int val[] = {60, 50, 70, 30};
    // int wts[]  = {5, 3, 4, 2};
    // int W = 5;

    vi val = {1,2,5,6};
    vi wts  = {2,3,4,5};
    int n = val.size();
    int W = 8;

    // int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSackwithSTL3(W, wts, val, n)<<endl;
    return 0;
}

// Example: 
// 1. https://codeforces.com/problemset/problem/741/B
