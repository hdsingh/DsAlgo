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

// Print binary representation of number using bits
void printBinary(unsigned n){
    cout<<"Binary rep of "<<n<<" is: ";
    for(unsigned i= 1<<31; i>0; i=i/2){
        (n&i)? cout<<"1" : cout<<"0";
    }
    cout<<endl;
}

void printBinary1(unsigned n){
    cout<<bitset<32>(n)<<endl;
}

// dec to bin
unsigned long bin(int n){
    return stoul(bitset<32>(n).to_string());
};

// dec to bin
string bins(int n){
    return bitset<20>(n).to_string();
}

int main(){
    int n = INT_MIN;
    printBinary1(n);
    // Write in binary
    int a = 0b1111; 
    cout<<a<<endl;

    a = 5;
    deb(a); 
    cout<< bitset<3>(a).to_string() <<endl;
    cout<<endl;

    a = a<<1;
    deb(a); 
    cout<< bitset<8>(a).to_string() <<endl;
    cout<<endl;


    // Find odd or even
    int x = 19; 
    (x & 1)? printf("Odd"): printf("Even"); // x & 1
    (x | 0)? printf("Odd"): printf("Even"); // x | 0

    x = 5;
    cout<<~x<<endl;
    cout<<endl;


    int k = 100001;
    int s = bitset<6>(to_string(k)).to_ulong();
    cout<<s<<endl;

    
    string ab = bitset<6>(33).to_string();
    cout<<ab<<endl;

    // decimal to binary long
    int l = bitset<6>(33).to_ulong();
    cout<<l<<endl;

    return 0;
    
}

// Refer: https://www.geeksforgeeks.org/c-bitset-and-its-application/