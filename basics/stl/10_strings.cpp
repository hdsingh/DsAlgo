#include <bits/stdc++.h>
using namespace std;


typedef std::vector<string> vs;

int main(){
    string s1 = "abcabc";
    string s2 = "abc";
    
    // in case a string is found it returns index
    // if not found returns string::npos
    size_t found = s1.find(s2);
    if(found!=string::npos)
        cout<<"found at "<<found<<endl;
    else
        cout<<"not found"<<endl;
    
    // Second occurance can be found incrementing the index to start search from
    found = s1.find(s2, found+1);
    if(found!=string::npos)
        cout<<"found at "<<found<<endl;
    else
        cout<<"not found"<<endl;

    return 0;
}