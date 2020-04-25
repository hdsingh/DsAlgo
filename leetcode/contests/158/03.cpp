#include "cpp.h"
#include "extra.h"
using namespace std;

class Solution {
public:
     vector<vector<int>> dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<int>> sol;
        vector<int> sub;
        map<int, int> freq;
        for(int i=0; i<6; i++){
            freq.insert({i, 0});
        }
        dieHelper(n, freq, rollMax, sub, sol);
        // return sol.size();
        return sol;
    }

    void dieHelper(int level, map<int, int> &freq, vector<int> &rollMax, vector<int> &sub, vector<vector<int>> &sol){
        // tremination
        if(level==0){
            sol.push_back(sub);
            return;
        }
        if(level<0) return;

        // recurse
        for(int i=0; i<6; i++){
            if(freq[i]>=rollMax[i]) continue;
            else{
                freq[i]++;
                sub.push_back(i);
                dieHelper(level-1, freq, rollMax, sub, sol);
                sub.pop_back();
                freq[i]--;
            }
        }
    }
};

int main(){
    int n; 
    vi rollMax;
    Solution s;
    n = 2; rollMax = {1,1,2,2,2,3};
    n = 2; rollMax = {1,1,1,1,1,1};
    n = 3; rollMax = {1,1,1,2,2,3};
    auto out = s.dieSimulator(n, rollMax); 
    // cout<<out;
    print_vv(out);
}

// Is not correct