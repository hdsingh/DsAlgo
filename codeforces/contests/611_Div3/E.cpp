#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

int main(){
    int n, x;
    while(cin>>n){
        map<int,int> cnt;
        vi a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
            cnt[a[i]-1]++;
        }

        int res=0;
        int dist = 0;
        int right = false;

        for(int i=0; i<n; i++){
            if(!cnt[i]){
                dist++;
                continue;
            }

            int j = i-1;
            int sum = 0;
            while(j+1<n && cnt[j+1]){
                j++;
                sum+=cnt[j];
            }
            res+=(j-i+1);
            if(sum> j-i+1 && (!right || dist>1)){
                --sum;
                ++res;
            }
            right = false;
            if(sum>j-i+1){
                right = true;
                res++;
            }
            i=j;
            dist = 0;
        }



        
        // Minimum
        int mincnt=0;
        int i=0;
        while(i<=n){
            if(cnt[i]){
                mincnt++;
                i+=3;
            }else 
                i++;
        }

        cout<<mincnt<<" "<<res<<endl;

    }
    return 0;
}