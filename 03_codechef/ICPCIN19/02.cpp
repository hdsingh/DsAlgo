#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        float xlarr[n],xrarr[n];
        int varr[n];
        bool flag=false;
        
        int maxv=-99;
        for(int i=0;i<n;i++){
            cin>>xlarr[i]>>xrarr[i]>>varr[i];
            if(varr[i]>maxv){
                maxv=varr[i];
                
            }
            
        }
        unordered_map<float,int> countdict;
        for(int i=0;i<n;i++){
           xlarr[i]=xlarr[i]*(maxv/varr[i]);
           xrarr[i]=xrarr[i]*(maxv/varr[i]);
           countdict[xlarr[i]]++;
           countdict[xrarr[i]]++;
           if(countdict[xlarr[i]]>2 || countdict[xrarr[i]]>2){
               cout<<"NO"<<endl;
               flag=true;
               break;
           }
           
           
        }
        if(!flag){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}