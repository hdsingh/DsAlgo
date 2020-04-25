#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Refer : https://leetcode.com/explore/learn/card/binary-search/125/template-i/938/
int binarySearch(vi &a, int x){
    int n = a.size();
    if(n==0) return -1;

    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid]==x) 
            return mid;
        else if(a[mid]<x)
            l = mid + 1;
        else 
            r = mid -1;
    }
    // Post-processing:
    // End Condition: right + 1 == left
    return -1;
}

int binarySearchDec(vi &a, int x){
    int n = a.size();
    if(n==0) return -1;

    int l = 0;
    int r = n-1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(a[mid]==x) 
            return mid;
        else if(a[mid]<x)
            r = mid - 1;
        else 
            l = mid + 1;
    }
    return -1;
}

// Template 2
int binarySearch2(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size();
  while(left < right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid; }
  }

  // Post-processing:
  // End Condition: left == right
  if(left != nums.size() && nums[left] == target) return left;
  return -1;
}

// Template 3
int binarySearch3(vector<int>& nums, int target){
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;
    while (left + 1 < right){
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left + 1 == right
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    return -1;
}

double findRt(double n){
    double l=0, r=n, eps=0.01;
    while(r-l>eps){
        double mid = l+(r-l)/2;
        if(mid*mid<n)
            l = mid;
        else 
            r = mid;
    }
    double rt = l + (r-l)/2;
    deb(round(rt));
    return rt - round(rt)<eps;
}

int main(){
    vi a = {1,2,4,7,8,9};
    int foundAt = binarySearch(a, 4);
    deb(foundAt);
    vi b = {9,8,7,6,5,4,3,2,1};
    foundAt = binarySearchDec(b, 8);
    deb(foundAt);
    return 0;
}