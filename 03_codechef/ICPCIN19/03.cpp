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
        int n, k;
        scanf("%d ", &n);
        scanf("%d", &k);
        string s;
        cin>>s;
        unordered_map<char, unordered_set<int>> um;
        for(int p=1; p<=k; p++){
            string sub;
            cin>>sub;
            
            for(char c: sub){
                if(um.find(c)==um.end()){
                    um.insert({c, {p}});
                }else{
                    um[c].insert(p);
                }
            }

        }

        int prev = -1;

        for(char c: s){
            if(um[c].find(prev)!=um[c].end()) printf("%d ", prev);
            else{
                printf("%d ", *um[c].begin());
                prev = *um[c].begin();
            }
        }


        printf("\n");
    }
    return 0;
}