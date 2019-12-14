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
    int t;
    cin>>t;
    while(t--){
        string in, out;
        int n, r,p,s, w;

        cin>>n;
        cin>>r; cin>>p; cin>>s;

        cin>>in;
        
        map<char,int> cnt;
        for(char c: in){
            cnt[c]++;
        }

        w = min(cnt['R'], p) + min(cnt['P'], s) + min(cnt['S'], r);

        if(2*w < n){
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;

        for(auto &c: in){
            if(c=='R' && p){
                out+='P'; 
                p--;
            }else if(c=='P' && s){
                out+='S'; 
                s--;
            }else if(c=='S' && r){
                out+='R';
                r--;
            }else{
                out+='_';
            }
        }

        for(auto &c: out){
            if(c!='_')
                continue;
            else{
                if(r){
                    c = 'R'; r--;
                }else if(p){
                    c = 'P'; p--;
                }else if(s){
                    c = 'S'; s--;
                }
            }
        }
        
        cout<<out<<endl;


    }
    return 0;
}