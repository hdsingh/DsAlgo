#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ": " << x << endl;

template<typename... T>
void write(T&&... args) { //rvalue reference is new to C++ 
	((cout << args << " "), ...);
}


class Solution {
public:
    string longestPalindrome(string s) {
        int c, reach, max_len(1), len;
        string out = s.substr(0,1);

        int n = s.length();

        for(c=1; c<n-1; c++){
            deb(c);
            deb(s[c]);
            reach = min(c, n-1-c);
            deb(reach);
            len=1;
            int j = 1;
            while(j<=reach){
                if(s[c-j]==s[c+j]){
                    cout<<s[c-j]<<" "<<s[c]<<" "<<s[c+j]<<endl;
                    len+=2;
                    deb(len);
                    if (len>max_len){
                        max_len = len;
                        out = s.substr(c-j, c+j+1); 
                    }
                    j++;
                    // max_len= max(len, max_len);
                }else break;
            }
            cout<<"---------"<<endl;
            
        }
        return out;
    }
};

int main(){
    Solution *s = new Solution();
    
    set<string> ss = {"cbbd"};
    for(string x : ss)
        cout<<s->longestPalindrome(x)<<endl;
}