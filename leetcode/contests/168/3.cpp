#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size(); 
        unordered_map<string, int> ans;

        for(int sz = minSize; sz<=maxSize; sz++){
            
            unordered_map<char, int> cnt;
            int ncnt = 0;
            for(int i=0; i<sz-1; i++){
                if(!cnt[s[i]]++) ncnt++;
                // cnt[s[i]]++;
            }

            for(int i=sz-1; i<n; i++){
                // add in the end while entering
                if(!cnt[s[i]]++) ncnt++;
                // cnt[s[i]]++;

                if(ncnt<=maxLetters)
                    ans[s.substr(i-sz+1, sz)]++;
                
                // remove from beg while going, so that len is sz-1;
                // cnt[s[i-sz+1]]--;
                if(!--cnt[s[i-sz+1]]) ncnt--;
            }
        }

        // High complexity
        // for(int sz = min(minSize, n); sz<=min(maxSize, n); sz++){
        //     for(int beg = 0; beg< n-sz+1; beg++){
        //         string sub = s.substr(beg, sz);
        //         set<char> un;

        //         for(auto b: sub)
        //             un.insert(b);

        //         int uniq = un.size();
        //         if(uniq<=maxLetters)
        //             ans[sub]++;
        //     }
        // }
        
        int mfreq = 0;
        for(auto a: ans){
            mfreq = max(a.second, mfreq);
        }

        return mfreq;
    }
};

int main(){
    string s;
    int maxLetters, minSize, maxSize;
    Solution sol;
    s = "aababcaab";
    maxLetters = 2; minSize = 3; maxSize = 4;
    cout<<sol.maxFreq(s,maxLetters, minSize, maxSize)<<endl;

    s = "aaaa";
    maxLetters = 1; minSize = 3; maxSize = 3;
    cout<<sol.maxFreq(s,maxLetters, minSize, maxSize)<<endl;

    s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3;
    cout<<sol.maxFreq(s,maxLetters, minSize, maxSize)<<endl;

    s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3;
    cout<<sol.maxFreq(s,maxLetters, minSize, maxSize)<<endl;
    

    return 0;
}