#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

class Solution {
public:
    void prefixes(string s, int n){
        int op(0);
        for(int i=0; i<n; i+=2){
            if(s[i]==s[i+1]){
                s[i] = s[i]=='a'? 'b':'a';
                op++;
            }
        }
        printf("%d\n", op);
        cout<<s<<'\n';
    }
    
};

int main(){
    string st;
    int t, n;
    Solution s;
    scanf("%d\n", &n);
    getline(cin, st);
    s.prefixes(st, n);
}