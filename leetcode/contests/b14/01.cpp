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
    string toHexspeak(string num) {
        unsigned long long  n = stoull(num);
        std::stringstream sstream;
        sstream << std::hex << n;
        std::string res = sstream.str();

        set<char> valid = {'a','b','c','d','e','f','i','o'};

        bool err = false;
        for(char &c: res){
            if(c=='0') 
                c='o';
            else if(c=='1')
                c='i';

            if(valid.find(c)==valid.end()){
                err = true;
                break;
            }
            c = toupper(c);
        }

        // uppercase(res);

        return err ? "ERROR" : res;
    }
};


int main(){
    Solution sol;
    string out = sol.toHexspeak("257");
    deb(out);

    
    return 0;
}