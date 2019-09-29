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

// start from index 1 and keep swapping till the value(child) is
// greater than its parent
void makeHeap(vi &arr, int n){

    for(int i=1; i<n; i++){

        // if child is greater than parent
        if(arr[i] > arr[(i-1)/2]){
            int j = i;

            // swap child and parent while parent is smaller
            while(arr[j] > arr[(j-1)/2]){
                swap(arr[j], arr[(j-1)/2]);
                j = (j-1)/2; //parent becomes child

            }
        }
    }
}

void heapSort(vi &arr){
    int n = arr.size();
    makeHeap(arr, n);
    cout<<"Heap: ";print(arr);
    for(int i = n-1; i>0; i--){
        swap(arr[0], arr[i]);

        int j=0;
        int child;
        do{
            child = 2*j+1;
            
            //find the greater child
            if(arr[child]<arr[child+1] && child<i-1) child++;
            
            //if parent is less than child
            if(arr[j]<arr[child] && child<i)
                swap(arr[j], arr[child]);
            
            j = child;
        }while(child<i);
    }
}

int main(){
    vi v = {6,1,8,2,9,4};
    heapSort(v);
    print(v);
}