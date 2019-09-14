#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    int x;
    cin>>x;
    while( x>=0 and x!=42){
        cout<<x<<" "<<typeid(x).name()<<endl;
        cin>>x;
    }
}