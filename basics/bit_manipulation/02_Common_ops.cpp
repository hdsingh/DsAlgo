#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;

int setbit(int num, int pos){
    return num | (1<<pos);
}

int clearbit(int num, int pos){
    return num & (~(1<<pos));
}

int togglebit(int num, int pos){
    return num ^ (1<<pos);
}

// msb(0) = -1; msb(1) = 1; msb(4) = 2;
int msb(int x){
    int pos = -1;
    while(x){
        x>>=1;
        ++pos;
    }
    return pos;
}

// lsb(0) = -1, lsb(1) = 0
int lsb(int x){
    int pos = 0;
    while(x){
        if(x&1) return pos;
        x>>=1;
        ++pos;
    }
    return -1;
}

int main(){
    cout<<setbit(16, 3)<<endl; // 10000-> 11000(24)
    cout<<setbit(4, 1)<<endl;
    cout<<clearbit(7, 0)<<endl;
    cout<<clearbit(7, 1)<<endl;
    cout<<togglebit(4, 1)<<endl;
    cout<<togglebit(6, 1)<<endl;


    int num = 4; 
    int twos_complement = -num; 
    cout << "This is two's complement " << twos_complement << endl; 
    cout << "This is also two's complement " << (~num+1) << endl;
    cout << "This is one's complement " << (~num) << endl; 

    return 0; 
}