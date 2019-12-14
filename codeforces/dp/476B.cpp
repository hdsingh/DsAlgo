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

int main(){
    string a, b;
    cin>>a;
    cin>>b;

    int orig = 0;
    for(auto &c: a)
        orig += c=='+' ? 1 : -1;

    vi dists;
    
    for(auto &c: b){
        if(c!='?'){
            int x = c=='+' ? 1:-1;
            if(dists.empty()){
                dists.push_back(x);
            }else{
                for(auto &dist: dists)
                    dist+=x;
            }
        }else{
            if(dists.empty()){
                dists.push_back(1);
                dists.push_back(-1);
            }else{
                vi ndists;
                for(auto &dist: dists){
                    ndists.push_back(dist+1);
                    ndists.push_back(dist-1);
                }
                swap(dists, ndists);
            }
        }
    }

    // print(dists);
    int cnt = 0;
    for(auto &d: dists){
        if(d==orig) cnt++;
    }

    float p = cnt/(float)dists.size();
    printf("%.12f",p);

    return 0;
}