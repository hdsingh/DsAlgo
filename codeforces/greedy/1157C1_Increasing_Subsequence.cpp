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
        cout<<setw(2)<<*i<<" ";
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
    int n;
    // cin>>n;
    while(cin>>n){
        vi arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        int l = 0, r = n-1;

        vi ans = {0};
        string lr;
        while(l<=r){
            if(arr[l]>ans.back() && arr[r]>ans.back()){
                if(arr[l]==arr[r] && l!=r){
                    int ll = l+1, rr =r-1;
                
                    int back = arr[l];
                    
                    int lcnt = 1;
                    while(arr[ll]>back && ll!=r){
                        back = arr[ll]; ll++; lcnt++;
                    }
                

                    back = arr[r];
                    int rcnt = 1;
                    while(arr[rr]>back && rr!=l){
                        back = arr[rr]; rr--; rcnt++;
                    }

                    // deb(lcnt); deb(rcnt);

                    if(lcnt>rcnt){
                        for(int i=0; i<lcnt; i++)
                            lr+='L';
                    }else{
                        for(int i=0; i<rcnt; i++)
                            lr+='R';
                    }


                    // cout<<lr.size()<<endl;
                    // cout<<lr<<endl;

                    // return 0;
                    break;
                    
                    
                }
                if(arr[l]<arr[r]){
                    ans.push_back(arr[l++]);
                    lr+='L';
                }else{
                    ans.push_back(arr[r--]);
                    lr+='R';
                }
            }else if(arr[l] > ans.back() || arr[r]>ans.back()){
                if(arr[l]>ans.back()){
                    ans.push_back(arr[l++]);
                    lr+='L';
                }else{
                    ans.push_back(arr[r--]);
                    lr+='R';
                }
            }else break;
        }

        cout<<lr.size()<<endl;
        cout<<lr<<endl;
        
    }

    return 0;
}