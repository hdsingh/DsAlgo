#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int diff;
        sort(all(arr));
        multimap<int,pii> m;
        vvi res;
        for(int i=0; i<n-1; i++){
            diff = arr[i+1]-arr[i];
            m.insert({diff, {arr[i], arr[i+1]}});
        }
        int min_diff = min_element(m.begin(), m.end())->first;
        auto it1 = m.lower_bound(min_diff);
        auto it2 = m.upper_bound(min_diff);

        while(it1!=it2){
            res.push_back({it1->second.first, it1->second.second});
            it1++;
        }

        return res;
    }
};

int main(){
    Solution s;
    vvi vs = {
        {4,2,1,3},
        {1,3,6,10,15},
        {3,8,-10,23,19,-4,-14,27},
    };
    for(int i=0; i<vs.size(); i++){
        vvi res = s.minimumAbsDifference(vs[i]);
        for(int j =0; j<res.size(); j++){
            print(res[j]);
        }
        cout<<endl;
    }
}