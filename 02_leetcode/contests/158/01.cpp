#include "cpp.h"
#include "extra.h"
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int out=0;
        map<char, int> count;
        for(auto c: s){
            count[c]++;
            if(count['L']==count['R']){
                out++;
                count.clear();
            }
        }

        return out;
    }
};

int main(){
    Solution sol;
    vs ss = {"RLRRLLRLRL", "RLLLLRRRLR", "LLLLRRRR", ""};
    for(auto x: ss) cout<<sol.balancedStringSplit(x)<<" ";
}
