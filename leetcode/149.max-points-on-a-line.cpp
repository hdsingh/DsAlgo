#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i=0; i<n; ++i){
            int count = 1; // (duplicate points)
            int other_count = 0; // max_points out of all slopes
            unordered_map<string, int> seen_slopes;
            for(int j=i+1; j<n; ++j){
                if(points[j]==points[i]){
                    ++count;
                }else{
                    string sl = slope(points[i][0], points[i][1], points[j][0], points[j][1]);
                    seen_slopes[sl]++;
                    other_count = max(other_count, seen_slopes[sl]);
                }
            }
            ans = max(ans, count + other_count);
        } 
        
        return ans;
    }

        // s.y/s.x
    string slope(int x1, int y1, int x2, int y2){
        int y = (y2-y1), x = (x2-x1);
        if(x==0) return "inf";
        else if(y==0) return "0";
        else if(x<0){
            x = -x;
            y = -y;
        }
        int gc = gcd(x,y);
        return to_string(x/gc) + "_" + to_string(y/gc);
    }
};

class Solution0 {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i=0; i<n; ++i){
            int count = 1; // (duplicate points)
            int other_count = 0; // max_points out of all slopes
            map<pair<int,int>,int> seen_slopes;
            for(int j=i+1; j<n; ++j){
                if(points[j]==points[i]){
                    ++count;
                }else{
                    pair<int,int> sl = slope(points[i][0], points[i][1], points[j][0], points[j][1]);
                    seen_slopes[sl]++;
                    other_count = max(other_count, seen_slopes[sl]);
                }
            }
            ans = max(ans, count + other_count);
        } 
        
        return ans;
    }
    
    pair<int,int> slope(int x1, int y1, int x2, int y2){
        int y = (y2-y1), x = (x2-x1);
        if(x==0) return {INT_MAX, INT_MAX};
        else if(y==0) return {0,0};
        else if(x<0){
            x = -x;
            y = -y;
        }
        int gc = gcd(x,y);
        return {x/gc, y/gc};
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}