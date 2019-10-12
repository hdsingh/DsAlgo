#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

class Solution {
public:
    string reverseParentheses(string s) {
        int l = s.find_last_of('(');
        int r = s.find_first_of(')');
        while (r<l)
            r = s.find(')', r+1);
        
        while(l>=0 && r<s.length()){
            string temp;
            for(int i=r-1; i>l; i--)
                temp+=s[i];

            s.replace(l, r-l+1, temp);

            l = s.find_last_of('(');
            r = s.find_first_of(')');
            while (r<l)
                r = s.find(')', r+1);
        }

        return s;

    }
};

int main(){
    Solution s;
    set<string> ss = {
        "f(ul)ao(t(y)qbn)()sj",                
        "ta()usw((((a))))",
                    "(u(love)i)",
                    "(abcd)",
                    "(ed(et(oc))el)",
                    "a(bcdefghijkl(mno)p)q",
    };

    for( string x: ss)
        cout<<s.reverseParentheses(x)<<endl;
}