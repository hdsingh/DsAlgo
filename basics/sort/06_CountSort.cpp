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

void countSort(vi &arr){
    int n = arr.size();

    int max_num = *max_element(arr.begin(), arr.end());

    // intialize count arr having max_num elements to track the count of nums
    vi count(max_num+1, 0);

    // Do the count
    for(int i: arr)
        count[i]++;
    
    // Start from begining of count arr and place elements acc to count

    int i = 0; //to track location in arr
    for(int j = 0; j<count.size(); j++){
        int c = count[j];
        while(c--){
            arr[i] = j;
            i++;
        }
    }
    
}

int main(){
    vi arr = {8,0,2,5,2,7,4,7,4,9,6,3};
    countSort(arr);
    print(arr);
    
    return 0;
}