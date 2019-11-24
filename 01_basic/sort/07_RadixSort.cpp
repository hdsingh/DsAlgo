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

void countSort(vi &arr, int exp){
    int n = arr.size();
    vi output(n);

    // int max_num = *max_element(arr.begin(), arr.end());

    // intialize count arr having max_num elements to track the count of nums
    vi count(10, 0);

    // Do the count
    for(int i: arr)
        count[(i/exp)%10]++;
    
    // Cumulative count
    for(int i=1; i<10; i++)
        count[i]+=count[i-1];
    
    // Build output arr
    for(int i = n-1; i>=0; i--){
        int c = count[(arr[i]/exp)%10];
        output[c-1] = arr[i]; // count start form 1 but index from 0
        count[(arr[i]/exp)%10]--;
    }

    // copy output into arr
    for(int i=0; i<n; i++)
        arr[i] = output[i];
    
    // swap(arr, output);
}

void radixSort(vi &arr){
    int n = arr.size();

    int max_num = *max_element(arr.begin(), arr.end());

    for(int exp = 1; max_num/exp>0; exp*=10)
        countSort(arr, exp);
}

int main(){
    vi arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    print(arr);
    
    return 0;
}