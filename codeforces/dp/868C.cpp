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

bool comp(vi a, vi b){
    return accumulate(all(a), 0) < accumulate(all(b),0);
}

int main(){
    int n; int k;
    cin>>n; cin>>k;

    int t;
    set<vi> s;
    for(int i=0; i<n; i++){
        vi p;
        for(int j=0; j<k; j++){
            cin>>t;
            p.push_back(t);
        }
        s.insert(p);
    }

    vi all_0(k);
    if(s.find(all_0)!=s.end()){
        cout<<"YES";
    }else{
        
        for(auto i=s.begin(); i!=s.end(); i++){
            for(auto j=s.begin(); j!=s.end(); j++)
                if(i!=j){
                    int out = 0;
                    for(int z=0; z<k; z++)
                        out+= (*i)[z] & (*j)[z];
                    if(!out){
                        cout<<"YES";
                        return 0;
                    }
                }
        }
        cout<<"NO";
    }

    

    

    

    return 0;
}