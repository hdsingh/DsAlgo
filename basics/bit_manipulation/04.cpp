#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

int countSetBits(unsigned int x){
    // int count = 0;
    // while(x){
    //     count += x&1;
    //     x >>=1;
    // }
    // return count;
    return std::bitset<8>(x).count(); //<32> for 32 bit uint
}

int mlog2(int x) 
{ 
	int res = 0; 
	while (x >>= 1) 
		res++; 
	return res; 
} 

int isPowerof2(int x) 
{ 
	return (x && !(x & x-1)); 
} 

void printBinary(int n){
    for(int i= 1<<16; i>0; i=i/2){
        (n&i)? cout<<"1" : cout<<"0";
    }
    cout<<endl;
}

int main(){
    int c = countSetBits(15);
    deb(c);
    int a = 0b1011; 
    cout<<a<<endl;
    cout<<mlog2(17)<<endl;
    cout<<mlog2(2)<<endl;

    cout<<"isPowerof2 "<<isPowerof2(32)<<endl;
    cout<<"isPowerof2 "<<isPowerof2(31)<<endl;

    for(int i=0; i<8; i++){
        cout<<"pow(4,"<<i<<"): ";
        printBinary((pow(4,i)));
    }
    printBinary(240);


    return 0;
}