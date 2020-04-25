#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> cnt;
        for(auto &a: nums){
            cnt[a]++;
        }

        for(auto x: cnt){
            int a = x.first;
            int c = x.second;

            if(c==0) continue;

            for(int i=0; i<k; i++){
                if(cnt[a+i]<c) return false;
                else cnt[a+i]-=c;
            }
        }

        return true;

    }
};

int main(){
    Solution sol;
    vi nums; int k;
    nums = {12,12,2,11,22,20,11,13,3,21,1,13};
    // sort(nums.begin(), nums.end());
    // print(nums);
    nums = {3,2,1,2,3,4,3,4,5,9,10,11};
    // nums = {1,2,3,4};
    // nums = { 16,5,15,15,20,16,20,14,21,20,19,20,12,17,13,15,11,17,18,18,11,13,13,14,14,9,20,18,10,4,4,6,15,19,8,15,7,17,15,9,24,2,23,22,26,8,21,22,14,13,16,2,25,23,17,19,17,3,22,23,19,12,21,12,16,27,28,10,13,8,24,3,22,6,10,9,14,7,11,22,11,5,16,19,21,2,8,24,16,21,7,29,18,9,10,18,6,17,21,20 };


    cout<<sol.isPossibleDivide(nums,3)<<endl;
    
    return 0;
}