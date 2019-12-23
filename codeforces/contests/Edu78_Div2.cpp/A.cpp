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
    int t;
    cin>>t;
    string p, h;

    
    // Sliding window app
    // Compare chars
    while(t--){
        cin>>p>>h;

        bool yes = false;

        unordered_map<char, int> mp;
        unordered_map<char, int> mh;
        int lp = p.size();
        int lh = h.size();

        if(lh<lp){
            cout<<"NO"<<endl;
        }else{
            for(int i=0; i<lp; i++)
                mp[p[i]]++;
        
            for(int i=0; i<lp-1; i++){
                mh[h[i]]++;
            }

            for(int i=lp-1; i<lh; i++){
                mh[h[i]]++;

                if(mh==mp){
                    yes = true;
                    cout<<"YES"<<endl;
                    break;
                }

                mh[h[i-lp+1]]--;
                if(mh[h[i-lp+1]]==0) mh.erase(h[i-lp+1]);
            }

            if(!yes) cout<<"NO"<<endl;
        }

        
    }
    
    return 0;
}