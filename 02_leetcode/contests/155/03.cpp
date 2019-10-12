#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;


template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        sort(all(pairs));

        
        for(int i=0; i<pairs.size(); i++){
            print(pairs[i]);
        }
        cout<<endl;
        
        int done;
        while(true){
            done=1;
            for(int i=0; i<pairs.size(); i++){
                int f = pairs[i][0];
                for(int k =0; k<pairs.size(); k++){
                    if(pairs[k][0]==f && pairs[k][1]<pairs[i][1])


                }

                if(s[pairs[i][0]] > s[pairs[i][1]]){
                    swap(s[pairs[i][0]], s[pairs[i][1]]);
                    done = 0;
                }
            }
            if(done==1) break;
        }
        return s;
    }
};

int main(){
    Solution s;
    string st = "dcab";
    vvi ps = {{0,3},{1,2}};
    cout<<s.smallestStringWithSwaps(st, ps)<<endl;

    st = "dcab";
    ps = {{0,3},{1,2}, {0,2}};
    cout<<s.smallestStringWithSwaps(st, ps)<<endl;

    st = "cba";
    ps = {{0,1}, {1,2}};
    cout<<s.smallestStringWithSwaps(st, ps)<<endl;
}