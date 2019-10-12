#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

void heapify(vi &arr, int start, int end){
    int largest = start;
    int l = start*2+1;
    int r = start*2+2;

    if(l<end && arr[l]>arr[largest]) largest = l;
    if(r<end && arr[r]>arr[largest]) largest = r;

    if(largest!=start){
        deb(largest);
        swap(arr[start], arr[largest]);
        heapify(arr, largest, end);
    }
}

void heapSort(vi &arr){
    int n = arr.size();
    
    for(int i= n/2-1; i>=0; i--)
        heapify(arr, i, n);

    for(int i = n-1; i>=0; i--){
        swap(arr[0], arr[i]);

        heapify(arr, 0, i);
    }

}

int main(){
    vi v ={9,3,5,1,6,4};
    heapSort(v);
    print(v);    

}