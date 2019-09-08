// https://leetcode.com/contest/weekly-contest-153/problems/distance-between-bus-stops/
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        int i = start;
        int df(0), db(0);

        // Forward distance
        while(i!=destination){
            df+=distance[i];
            i = (i+1)%n;
        }

        // Backward distance
        i=start;
        while(i!=destination){
            i = (i-1+n)%n;
            db+=distance[i];
        }
        return min(df, db);
    }
};

int main(){
    vector<int> distance = {1,2,3,4};
    int start = 0;
    int destination = 3;

    Solution s;
    cout<<s.distanceBetweenBusStops(distance, start, destination);
}