#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        if(num>3999) return "";
        map<int,char> to_char = {
            {1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'}
        };
        
        string out;
        int pw = 1;
        while(num>0){
            int d = num%10;
            num/=10;
            
            if(1<=d && d<=3){
                for(int times=0; times<d; ++times)
                    out+=to_char[pw];
            }else if(d==4){
                out+=to_char[5*pw];
                out+=to_char[pw];
            }else if(d==5){
                out+=to_char[5*pw];
            }else if(6<=d && d<=8){
                for(int times=0; times<d-5; ++times)
                    out+=to_char[pw];
                out+=to_char[5*pw];
            }else if(d==9){
                out+=to_char[10*pw];
                out+=to_char[pw];
            }
        
            pw*=10;
        }

        reverse(out.begin(), out.end());
        return out;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}