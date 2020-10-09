#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<int> len(n+2), cnt(n+2);
        int at = -1;
        for(int i=0; i<n; ++i){
            int a = arr[i], lt = len[a-1], rt = len[a+1];
            len[a] = len[a-lt] = len[a+rt] = 1 + lt + rt;
            cnt[lt]--, cnt[rt]--, cnt[len[a]]++;
            if(cnt[m]>0){
                at = i+1;
            }
        }
        return at;
    }
};

class Solution0 {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        set<pair<int,int>> segs = {{1,n}};
        if(m==n) return n;
        
        for(int step=n-1; step>=0; --step){
            pair<int,int> req = {arr[step], n+1};
            auto pos = segs.upper_bound(req);
            --pos;
            int lt = pos->first, rt = pos->second;
            segs.erase(pos);
            int rt1 = arr[step]-1, lt2 = arr[step]+1;
            if(lt<=rt1){
                segs.insert({lt,rt1});
                if(rt1-lt+1==m) return step;
            }
            
            if(lt2<=rt){
                segs.insert({lt2,rt});
                if(rt-lt2+1==m) return step;
            }
        }
        
        return -1;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}