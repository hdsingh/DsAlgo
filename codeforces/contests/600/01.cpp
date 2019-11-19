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
    int t,n,l,r,k,temp;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d\n", &n);
        vi a(n+1);
        vi b(n+1);
        vi diff(n+1);

        for(int i=1; i<=n; i++){
            scanf("%d ",&a[i]);
        }


        for(int i=1; i<=n; i++){
            scanf("%d ",&(b[i]));
            diff[i] = b[i]-a[i];
        }
        // print(diff);


        int start = 0;
        int end = 0;
        k = 0;
        bool end_found = false;
        bool out = true;
        for(int i=1; i<=n; i++){
            
            if(start==0 && diff[i]!=0){
                start = i;
                k = diff[i];
                if(k<0){
                    out = false;
                    break;
                }
            }else if(start && !end_found && diff[i]!=0){
                if(diff[i]!=k){
                    out = false;
                    break;
                }
            }
            else if(start && diff[i]==0){
                end_found = true;
            }else if(end_found && diff[i]!=0){
                out = false;
                break;
            }
        }

        if(out) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
}