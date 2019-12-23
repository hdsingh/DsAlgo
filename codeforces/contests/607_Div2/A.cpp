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
typedef long long ll;
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

// If a sentence ends with "po" the language is Filipino.
// If a sentence ends with "desu" or "masu" the language is Japanese.
// If a sentence ends with "mnida" the language is Korean.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        if(n>=2 && s.substr(n-2, 2)=="po"){
            cout<<"FILIPINO"<<endl;
        }else if(n>=4 && (s.substr(n-4, 4)=="desu" || s.substr(n-4, 4)=="masu")){
            cout<<"JAPANESE"<<endl;
        }else 
            cout<<"KOREAN"<<endl;
    }
    
    return 0;
}