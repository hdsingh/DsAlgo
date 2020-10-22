#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}


void merge(vi &arr, int l, int m, int r){
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

    vi L(n1), R(n2);

    for(int i=0; i<n1; i++)
        L[i] = arr[l+i];

    for(int j=0; j<n2; j++)
        R[j] = arr[m+1+j];
    
    i=0; j=0; k=l;
    while(i<n1 && j<n2){

        if(L[i]<=R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i<n1)
        arr[k++] = L[i++];
    
    while(j<n2)
        arr[k++] = R[j++];
    
}


void mergeSort(vi &arr, int l, int r){
    if(l<r){
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
}

int main(){
    vi arr = {12, 11, 13, 5, 6, 7};
    arr =  {8,2,1,4,5,69,20,2,1,};
    int n = arr.size(); 
    mergeSort(arr,0, n-1);
    print(arr);
    return 0;
}