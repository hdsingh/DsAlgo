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
    int minimumSwap(string a, string b) {
        if(a.length()!=b.length()) return -1;

        int n = a.length();
        map<char, int> count;

        for(auto c: a)
            count[c]++;
        
        for(auto c: b)
            count[c]++;
        
        if(count['x']%2 || count['y']%2) return -1;


        int xy = 0;
        int yx = 0;

    
        for(int i=0; i<n; i++){

            if(a[i]=='x' && b[i]=='y') xy++;
            if(a[i]=='y' && b[i]=='x') yx++;
        }


        int swaps = 0;
        swaps+= xy/2;
        swaps+= yx/2;
        xy%=2; yx%=2;


        swaps+=xy;
        swaps+=yx;

        return swaps;

    }
};

int main(){
    Solution s;
    cout<<s.minimumSwap("xx", "yy")<<endl;
    cout<<s.minimumSwap("xy", "yx")<<endl;
    cout<<s.minimumSwap("xx", "yx")<<endl;


    string s1, s2;
    s1 = "xxyyxyxyxx"; 
    s2 = "xyyxyxxxyx";

    cout<<s.minimumSwap(s1, s2)<<endl;

    return 0;
}