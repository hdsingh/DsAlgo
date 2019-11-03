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
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string out1;
        int count=0;
        // Forward pass
        for(auto c: s){
            if(c!='(' && c!=')'){
                out1+=c;
            }
            else if(c=='('){
                out1+=c;
                count++;
            }else{ // ')'
                if(count){
                    out1+=c;
                    count--;
                }
            }
        }

        // print(out1);
        count=0;
        string out2;
        for(auto it = out1.rbegin(); it!=out1.rend(); it++){
            char c = *it;
            if(c!='(' && c!=')')
                out2+=c;
            else if(c==')'){
                out2+=c;
                count++;
            }else{
                if(count){
                    out2+=c;
                    count--;
                }
            }
        }

        reverse(out2.begin(), out2.end());
        return out2;        
    }
};