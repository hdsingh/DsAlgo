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
    int  t; cin>>t;
    string s,c, ss; //ss: sorted_s
    while(t--){
        cin>>s>>c;
        ss = s;
        // Find the shortest possible word by sorting s
        // and comparing sorted s with orig s,
        // if a greater char is found, find the corresponding
        // char in s and swap
        // APPLE  s
        // AEPPL  ss
        // AEPLE  swaped P with E
        // AAPAAA -> AAAAAP -(swapping should be made with the last equal element)

        sort(ss.begin(), ss.end());

        for(int i=0; i<s.size(); i++){
            if(s[i]>ss[i]){
                // find ss[i] in s;
                int j = s.size()-1;
                while(s[j]!=ss[i]){
                    j--;
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
    return 0;
}