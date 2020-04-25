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


class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vvi out(2, vi(n, 0));
        if(!n) return {};

        for(int i=0; i<n; i++){
            int s = colsum[i];

            if(s==1){
                if(upper && upper>=lower){
                    out[0][i] = 1;
                    upper--;
                }
                else if(lower && lower>=upper){
                    out[1][i] = 1;
                    lower--;
                }
                else
                    return {};
            }
            else if(s==2){
                if(upper && lower){
                    out[0][i] = 1;
                    out[1][i] = 1;
                    upper--;
                    lower--;
                }else{
                    return {};
                }
            }
        
        // deb(upper);
        // deb(lower);
        // print_vv(out);
        }

        vvi empty = {};
        return !upper && !lower ? out : empty;
        
    }
};

int main(){
    Solution sol;
    vi colsum = {1,1,1};
    vvi output = sol.reconstructMatrix(2,1,colsum);
    print_vv(output);

    vvi out;
    colsum= {2,2,1,1};
    out = sol.reconstructMatrix(2,1,colsum);
    print_vv(out);

    

    colsum= {2,1,2,0,1,0,1,2,0,1};
    out = sol.reconstructMatrix(5,5,colsum);
    print_vv(out);

    colsum = {2,1,2,2,1,1,1};
    out = sol.reconstructMatrix(4,7, colsum);
    print_vv(out);



    return 0;
}