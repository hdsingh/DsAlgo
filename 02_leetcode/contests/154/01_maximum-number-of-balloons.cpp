#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string balloon = "balloon";
        int count =0;
        map<char, int> t; //times
        for(char c: text){
            t[c]++;
        }

        // for(auto i = t.begin(); i!=t.end(); i++)
        //     cout<<i->first<<" : "<<i->second<<endl;

        while (true)
        {
            if(t['b']>=1 && t['a']>=1 && t['l']>=2 && t['o']>=2 && t['n']>=1){
                count+=1;
                for(char c: balloon){
                    t[c]--;

                }
            }
            else break;
        }

        return count;

    }
};

int main(){
    Solution s;
    set<string> ss = {
        "nlaebolko",
         "leetcode",
        "loonbalxballpoon"
    };

    for( string x: ss)
        cout<<s.maxNumberOfBalloons(x);
}