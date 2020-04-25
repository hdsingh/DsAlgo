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

// starting from left side, if we find any num less then piviot,
// then swap it and bring it on right side of i, so that in resulting seq
// the nums less than piviot are on left of i
int partition(vi &A, int l, int r){
    int piviot = A[r]; // to place the piviot at its correct pos
    int i = l - 1;

    for(int j = l; j<r; j++){
        if(A[j]<piviot){
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i+1], A[r]);
    return i+1;
}

void quickSort(vi &A, int left, int right){
    if(left<right){
        int partition_pt = partition(A, left, right);
        quickSort(A, left, partition_pt-1);
        quickSort(A, partition_pt+1, right);
    }    

}


int main(){
    vi arr = {2,5,2,7,4,7,4,9,6,3};
    quickSort(arr, 0, arr.size());
    print(arr);
    
    return 0;
}