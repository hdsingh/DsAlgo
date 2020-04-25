//Refer: https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/tutorial/
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

void insertionSort(int arr[], int n ){

    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i;

        while(j > 0 && arr[j-1]>temp){
            arr[j] = arr[j-1];
            j--;
        }

        arr[j] = temp;
    }

}

int main(){
    int arr[] = {2,5,2,7,4,7,4,9,6,3};
    // int arr[] = {7,4,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);

    // print(arr);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    
    return 0;
}