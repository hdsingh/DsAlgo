// Refer : https://www.geeksforgeeks.org/bucket-sort-2/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}

void bucketSort(vector<float> &arr){
    int n = arr.size();
    // Create buckets
    vector<vector<float>> buckets(10);

    // insert into buckets according to index
    for(int i=0; i<n; i++){
        int bucIndex = arr[i]*10; 
        buckets[bucIndex].push_back(arr[i]);
    }

    // Sort the individual buckets
    for(int i=0; i<10; i++){
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr
    arr.clear();
    for(int i=0; i<10; i++){
        for(int j=0; j<buckets[i].size(); j++){
            arr.push_back(buckets[i][j]);
        }
    }
}

int main(){
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucketSort(arr);
    print(arr);
    return 0;
}