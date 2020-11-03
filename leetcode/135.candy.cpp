#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        int ans = 0, prev = 0;
        for(int i=0; i<n; ++i){
            if(i+1<n && a[i]>a[i+1]){
                // if decreasing seq exists then find its len
                // the candies at cur pos will be max of prev+1 if a[i-1]<a[i] 
                // else depends on len of dec seq;
                // the remaing elements will be assigned X, X-1, X-2....1
                // hence --len. len*(len+1)/2;
                int j = i;
                while(j+1<n && a[j]>a[j+1]) ++j;
                int len = j-i+1;

                ans+=max((i-1>=0 && a[i-1]<a[i] ? prev + 1: 0), len);

                --len;
                ans+=len*(len+1)/2;
                prev = 1;
                i = j;
            }else if(i-1>=0 && a[i-1]<a[i]){
                // prev was less so inc it
                prev++;
                ans+=prev;
            }else{
                prev = 1;
                ans+=prev;
            }
        }
        return ans;
    }
};

class Solution0 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> order(n);
        for(int i=0; i<n; ++i) order[i] = i;
        sort(order.begin(), order.end(), [&](int idx1, int idx2){
            return ratings[idx1]<ratings[idx2]; 
        });
        
        int ans = 0;
        vector<int> candies(n,0);
        for(int idx: order){
            int lt = 0, rt = 0;
            if(idx-1>=0 && ratings[idx-1]<ratings[idx]) 
                lt = candies[idx-1];
            if(idx+1<n && ratings[idx+1]<ratings[idx]) 
                rt = candies[idx+1];
            candies[idx] = 1 + max(lt,rt);
            ans+=candies[idx];
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}