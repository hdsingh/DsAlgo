// @lc app=leetcode id=350 lang=cpp
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

class Solution {
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
    sort(all(v1));
    sort(all(v2));
    int l1 = v1.size();
    int l2 = v2.size();
    int p1(0), p2(0);
    vector<int> out;
    // unordered_set<int> cache;

    if (!l1 || !l2) return out;

    while(p1<l1 && p2<l2){

        if (v1[p1]==v2[p2]){
            int x = v1[p1];
            // if (cache.find(x)==cache.end()){
            //     cache.insert(x);
            out.push_back(x);
            // }
            p1++; p2++;
        }
        else if (v1[p1]<v2[p2])
            p1++;
        else p2++;
    }

    return out;

    }
};

// int main(){
//     vi v1, v2;
//     v1 = {1,2,2,1};
//     v2 = {2,2};
//     // v1 = {4,9,5};
//     // v2 = {9,4,9,8,4,};
//     // v1 = {3,1,2};
//     // v2 = {1};
//     Solution s;
//     print(s.intersection(v1, v2));
// }