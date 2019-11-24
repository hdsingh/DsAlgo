// REfer: https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/tutorial/
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

void bubbleSort(vi &arr){
    int n = arr.size();

    for(int k=0; k<n-1; k++)
        for(int i=0; i<n-k-1; i++)
            if(arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
}

int main(){
    vi arr = {2,5,2,7,4,7,4,9,6,3};
    bubbleSort(arr);
    print(arr);
    
    return 0;
}