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
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    vi cnt(n);
    cnt[0] = arr[0];
    for(int i=1; i<n; i++)
        cnt[i]=(arr[i] + cnt[i-1]);

    // print(cnt);
    
    
    int max_1(0), cnt_1_prev(0), cur_1(0);
    for(int i=0; i<n; i++){
        cur_1 = 0;
        cnt_1_prev = i==0 ? 0: cnt[i-1];
        for(int j=i; j<n; j++){
            cur_1 += 1 - arr[j];
            int cnt_1_next = cnt[n-1] - cnt[j];
            max_1 = max(max_1,  cur_1 + cnt_1_prev + cnt_1_next );
        }
    }

    cout<<max_1<<endl;
    
    return 0;
}