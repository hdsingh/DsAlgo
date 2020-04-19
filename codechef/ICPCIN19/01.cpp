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



int main(){
    int times;
    scanf("%d", &times);
    while(times--){
        int n;
        scanf("%d\n", &n);
        unordered_map<string, unordered_map<int, int>> word;
        while(n--){
            string s;
            int a;
            cin>>s;
            cin>>a;
            if(word.find(s)==word.end()){
                unordered_map<int,int> count;
                count[a]++;
                word.insert({s, count});
            }else{
                word[s][a]++;
            }
        }
        
        int c = 0;
        for(auto x: word){
            int c0 = 0;
            int c1 = 1;
            if(x.second.find(0)!=x.second.end()) c0 = x.second[0];
            if(x.second.find(1)!=x.second.end()) c1 = x.second[1];
            // cout<<c0<<" "<<c1<<endl;
            c+= c0>c1 ? c0:c1;
        }
        printf("%d\n", c);
    }
}