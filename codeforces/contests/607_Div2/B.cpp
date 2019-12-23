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

int main(){
    int t; cin>>t;
    string s, c;
    while(t--){
        cin>>s>>c;
        if(s<c)
            cout<<s<<endl;
        else{
            string ss = s; //sorted s
            sort(all(ss));
            
            int n = s.size();
            for(int i=0; i<n-1; i++){
                if(s[i]!=ss[i]){
                    char p = ss[i];
                    int j=n-1;
                    for(j; j!=i; j--){
                        if(s[j]==p)
                            break;
                    }
                    swap(s[i], s[j]);
                    break;
                }
            }

            if(s<c){
                cout<<s<<endl;
            }else{
                cout<<"---"<<endl;
            }
        }
    }
    return 0;
}