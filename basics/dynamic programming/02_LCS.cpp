// Find the lenght of longest common subsequence
// https://www.youtube.com/watch?v=ASoaQq66foQ
#include <bits/stdc++.h>
using namespace std;

// i,j: track pos of a,b
int LcsRec(int i, int j, string &a, string &b){
    if(i==a.size() || j==b.size())
        return 0;
    else if (a[i]==b[j])
        return 1 + LcsRec(i+1, j+1, a, b);
    else
        return max(LcsRec(i+1, j, a, b), LcsRec(i, j+1, a, b));
}
// if both match add 1
// else try finding in left side or right side

// https://www.youtube.com/watch?v=ASoaQq66foQ
int LCS(string a, string b){
    int a_size = a.size();
    int b_size = b.size();

    vector<vector<int>> dp(a_size+1, vector<int>(b_size+1, 0));

    for(int i=1; i<=a_size; i++)
        for(int j=1; j<=b_size; j++)
            if(a[i-1]==b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        
    return dp[a_size][b_size];    
}
// a |  b->
// if chars don't match skip the char in 'a' once(i-1) and in 'b' once (j-1)
// by moving back,
// if both match, skip both (i-1)(j-1) and add 1

int main(){
    string a = "ace";
    string b = "abcde";
    cout<<LcsRec(0, 0, a, b)<<endl;
    cout<<LCS(a,b)<<endl;
}