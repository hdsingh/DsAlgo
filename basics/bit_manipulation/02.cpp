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