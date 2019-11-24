// Refer: https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/tutorial/
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

void SelectionSort1(vi &arr){ // using max_element_pos
    int n = arr.size();

    for(int k=0; k<n-1; k++){
        int max_element_pos = 0;
        for(int i=1; i<n-k; i++){
            if(arr[i] > arr[max_element_pos])
               max_element_pos = i;
        }
        swap(arr[max_element_pos],arr[n-k-1]);
    }
        
}

void SelectionSort(vi &arr){
    int n = arr.size();
    
    for(int i = 0; i<n; i++){
        int minimum = i;

        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minimum]){
                minimum = j;
            }
        }
        swap(arr[minimum], arr[i]);
    }
}

int main(){
    vi arr = {2,5,2,7,4,7,4,9,6,3};
    SelectionSort(arr);
    print(arr);
    
    return 0;
}