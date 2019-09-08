// https://leetcode.com/contest/biweekly-contest-8/problems/shortest-distance-to-target-color/

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int i,c, res;
        vector<int> out;
        for (int j=0; j<queries.size(); j++){
            i = queries[j][0];
            c = queries[j][1];
            res = find_distance(colors, i,c);
            out.push_back(res);
        }
        return out;
    }

    int find_distance(vector<int> colors, int i, int c){
        int l = colors.size();
        int L(i),R(i), dl, dr;

        while(L>=0 || R<l){
            dl=0;
            while(L>=0){
                if (colors[L--]==c)
                    return dl;
                dl++;
            }
            dr=0;
            while(R<l){
                if(colors[R++]==c)
                    return dr;
                dr++;
            }    
        }
        return -1;
    }
};


int main(){
    vector<int> colors {1,1,2,1,3,2,2,3,3};
    vector<vector<int>> queries = {{1,3},{2,2},{6,1}};
    Solution s;
    vector<int> out = s.shortestDistanceColor(colors, queries);
    for(int x: out)
        cout<<x<<" ";
}