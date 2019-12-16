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
    string s;
    cin>>s;

    vi ones(n+1);
    vi zeros(n+1);
    vi req1s(n+1);
    

    // for(int i=1; i<n+1; i++){
    //     int t = s[i-1] - '0';
    //     zeros[i] = zeros[i-1] + !t;
    //     ones[i] = ones[i-1] + t;
    //     req1s[i] = zeros[i] - ones[i];
    // }

    // O(n^2) :TLE
    // int max_len = 0;
    // for(int i=0; i<n+1; i++){
    //     for(int j=i+1; j<n+1; j++){
    //         if(req1s[i] == req1s[j])
    //             max_len = max(max_len, j-i);
    //     }
    // }

    // better approach: Maintain a map<set> to store indexes for 
    // different req1s, and for each unique value of req1s, compare it 
    // with smallest and largest value;
    map<int, vi> req;
    req[0].push_back(0);
    for(int i=1; i<n+1; i++){
        int t = s[i-1] - '0';
        zeros[i] = zeros[i-1] + !t;
        ones[i] = ones[i-1] + t;
        // req1s[i] = zeros[i] - ones[i];
        int diff = zeros[i] - ones[i];
        req[diff].push_back(i);
    }

    int max_len = 0;
    for(auto m: req){
        // cout<<m.first<<": ";
        // print(m.second);

        int mini = m.second.front();
        int maxi = m.second.back();
        max_len = max(max_len, maxi-mini);
    }

    
    
    

    // print(zeros);
    // print(ones);
    cout<<max_len<<endl;

    return 0;
}