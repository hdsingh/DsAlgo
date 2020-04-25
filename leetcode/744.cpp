// @lc app=leetcode id=744 lang=cpp

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
    char nextGreatestLetter(vector<char> letters, char t) {
        // int n = letters.size();
        // int i=0;
        // while(i<n){
        //     if (t < letters[i])
        //         return letters[i];
        //     i++;
        // }
        // return letters[0];
        // Sol 2
        // auto it = upper_bound(letters.begin(), letters.end(), t);
        // return it == letters.end()? letters[0]: *it;

        // Sol3
        if (letters.back()<=t) return letters.front();
        int l = 0;
        int r = letters.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if (t<letters[mid]) r = mid;
            else l = mid+1;
        }
        return letters[l];
    }
};

// int main(){
//     Solution s;
//     map<vector<char>, char> ex = {
//         // {{'c','f','j'}, 'a'},
//         // {{'c','f','j'}, 'c'},
//         // {{'c','f','j'}, 'd'},
//         {{'c','f','j'}, 'g'},
//         {{'c','f','j'}, 'j'},
//         {{'c','f','j'}, 'k'},
//     };

//     for(auto x = ex.begin(); x!=ex.end(); x++){
//         cout<<x->second<<": "<<s.nextGreatestLetter(x->first, x->second)<<endl;
//     }
// }