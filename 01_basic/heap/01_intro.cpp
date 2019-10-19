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

class MinHeap {
public:
    vector<int> harr;
    int capacity;
    int heap_size;

    MinHeap(int capacity);

    void MinHeapify(int r);

    int parent(int i) {return (i-1)/2; }

    int left(int i) {return 2*i+1;}
    
    int right(int i) {return 2*i+2;}

    int extractMin(); // to extract the root which is minimum

    void decreaseKey(int i, int new_val); // decreases the val to new_val

    int getMin() {return harr[0];}

    void deleteKey(int i);//deletes key stored at i

    void insertKey(int k);// Insert a new key k
};

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

MinHeap::MinHeap(int cap){
    heap_size = 0;
    capacity = cap;
    harr = vector<int>(cap, 0);
}

void MinHeap::insertKey(int k){

    if(heap_size==capacity){
        cout<<"OverFlow: Could not insert key"<<endl;
    }

    harr[heap_size] = k;
    int i = heap_size;

    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(harr[parent(i)], harr[i]);
        i = parent(i);
    }
    heap_size++;
}

void MinHeap::decreaseKey(int i, int key){
    harr[i] = key;

    while(i!=0 && harr[parent(i)] > harr[i]){
        swap(harr[parent(i)], harr[i]);
        i = parent(i);
    }
}

int MinHeap::extractMin(){
    if(heap_size<=0) return INT_MAX;

    if(heap_size==1){
        heap_size--;
        return harr[0];
    }

    // Store the minimum value and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1]; //bring last value to top
    heap_size--;
    MinHeapify(0); // position top element to correct pos;

    return root;
}

void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<heap_size && harr[l]<harr[smallest]) smallest = l;
    if(r<heap_size && harr[r]<harr[smallest]) smallest = r;
    if(smallest!=i){
        swap(harr[smallest], harr[i]);
        MinHeapify(smallest);
    }
}

void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}

int main(){
    MinHeap mh(7);
    mh.insertKey(40);
    mh.insertKey(5);
    print(mh.harr);
    mh.insertKey(30);
    print(mh.harr);
    mh.insertKey(15);
    print(mh.harr);
    mh.insertKey(15);
    print(mh.harr);

    mh.insertKey(16);

    print(mh.harr);

    mh.decreaseKey(5, -10);
    print(mh.harr);

    mh.extractMin();
    print(mh.harr);

    mh.extractMin();
    print(mh.harr);

    mh.deleteKey(1);
    print(mh.harr);

    mh.deleteKey(1);
    print(mh.harr);

    cout<<mh.getMin();
    
}