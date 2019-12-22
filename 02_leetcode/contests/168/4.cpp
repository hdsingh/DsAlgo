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

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<int> usedBox(n, 0);
        set<int> newBox;
        int totcandies = 0;
        for(auto box: initialBoxes)
            newBox.insert(box);
        
        bool all_used = false;
        while(!all_used){
            all_used = true;
            for(auto nb: newBox){
                if(!usedBox[nb] && status[nb]){
                    usedBox[nb] = 1;
                    all_used = false;
                    totcandies+=candies[nb];

                    for(auto cb: containedBoxes[nb])
                        newBox.insert(cb);

                    for(auto k: keys[nb])
                        status[k] = 1;
                }
            }
        }

        return totcandies;
    }
};


int main(){
    vector<int> status;
    vector<int> candies; vector<vector<int>> keys; 
    vector<vector<int>> containedBoxes;
    vector<int> initialBoxes;
    Solution sol;
    status = {1,0,1,0}, candies = {7,5,4,100}, keys = {{},{},{1},{}}, containedBoxes = {{1,2},{3},{},{}}, initialBoxes = {0};
    cout<<sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes)<<endl;


    status = {1,0,0,0,0,0}, candies = {1,1,1,1,1,1}, keys = {{1,2,3,4,5},{},{},{},{},{}}, containedBoxes = {{1,2,3,4,5},{},{},{},{},{}}, initialBoxes = {0};
    cout<<sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes)<<endl;


    status = {1,1,1}, candies = {100,1,100}, keys = {{},{0,2},{}}, containedBoxes = {{},{},{}}, initialBoxes = {1};
    cout<<sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes)<<endl;


    status = {1}, candies = {100}, keys = {{}}, containedBoxes = {{}}, initialBoxes = {};
    cout<<sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes)<<endl;;


    status = {1,1,1}, candies = {2,3,2}, keys = {{},{},{}}, containedBoxes = {{},{},{}}, initialBoxes = {2,1,0};
    cout<<sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes)<<endl;;

    return 0;
}