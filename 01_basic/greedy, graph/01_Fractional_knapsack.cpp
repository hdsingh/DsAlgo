#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;


struct Item 
{ 
    int value, weight; 

    // Constructor 
    Item(int value, int weight) : value(value), weight(weight) 
    {} 
};

bool cmp(Item a, Item b){
    return (double)a.value/a.weight > (double)b.value/b.weight;
}

int fractionalKnapsack(int capacity, vector<Item> arr){
    int n = arr.size();
    int max_value = 0;

    // sort based on profit
    sort(arr.begin(), arr.end(), cmp);


    // keep adding item till its weight < capacity
    // if weight > capacity add fraction and break
    for(int i=0; i<n; i++){
        if(arr[i].weight<capacity){
            max_value+=arr[i].value;
            capacity-=arr[i].weight;
        }
        else{ //i.weight>capacity
            double fraction = (double)capacity/arr[i].weight;
            max_value+= fraction*arr[i].value;
            break;
        }
    }
    return max_value;
}

int main(){
    int capacity = 50;   //    Weight of knapsack 
    vector<Item> arr = {{60, 10}, {100, 20}, {120, 30}}; 
  
    cout << fractionalKnapsack(capacity, arr)<<endl; 
    return 0; 
}