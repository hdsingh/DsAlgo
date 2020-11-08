// Refer: CLRS, https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/tutorial/
#include <bits/stdc++.h>
using namespace std;
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

int partition(int l, int r, vi &a){
    int pivot = a[r];
    int i = l-1;

    for(int j=l; j<r; ++j){
        if(a[j]<pivot){
            ++i;
            swap(a[i], a[j]);
        }
    }

    swap(a[i+1], a[r]);
    return i+1;
}

void quick(int l, int r, vi &a){
    if(l<r){
        int pt = partition(l,r,a);
        quick(l,pt-1,a);
        quick(pt+1,r,a);
    }
}

int selectRec(int l, int r, int K, vi &a){
    if(l==r) return a[l];
    int pt = partition(l,r,a);

    if(pt==K)
        return a[K];
    else if(K<pt)
        return selectRec(l,pt-1,K,a);
    return selectRec(pt+1,r,K,a);
}

// https://en.wikipedia.org/wiki/Quickselect
// To select the Kth element 
// Best: O(n), Average : O(n), worst: O(n*n);
int select(int l, int r, int K, vi &a){
    while(l<=r){
        if(l==r) return a[l];
        int pt = partition(l,r,a);
        if(K==pt) return a[K];
        if(K<pt)
            r = pt - 1;
        else
            l = pt + 1;
    }
    return -1;
}

int main(){
    vi arr = {2,5,2,7,4,7,4,9,6,3};
    quick(0, arr.size()-1, arr);
    print(arr);
    
    return 0;
}