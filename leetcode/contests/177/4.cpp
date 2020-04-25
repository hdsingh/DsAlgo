#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
template<class T, class U> inline void add_self(T &a, U b){a += b;if (a >= mod) a -= mod;if (a < 0) a += mod;}
template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Think of number in terms of mod of 3, so any number  in digits
// could only be 0,1,2. 
// if the sum is div by 3 then ok else try deleting some elements
// if sum%3 i.e. mod , could be 1 or 2
// we are never going to delete 0,3,6,9
// but can mod 1 (1,4,7) or mod 2(2,5,8)
// in case of mod 1 if mod 1 elements (1,4,7) are not present in digits,
// we can delete 2*(any of 2,5,8) (2*2=4%3 = 1, 5*2=10%3=1, 8*8=16%3 = 1, 2+5=7%3=1, mod1+mod1 = mod2)
// same in case when moo 2 are not present, so will delete 2 element of 1st type
// will delete smallest element of a mod
class Solution {
    vvi mods = {{}, {1,4,7}, {2,5,8}};
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vi cnt(10);
        for(auto &d: digits)
            cnt[d]++;
        
        int sum = accumulate(all(digits), 0);
        int mod = sum%3; 
        if(mod==0) return formString(cnt);
        int othmod = mod==1 ? 2 : 1;

        if(Delete(mod, cnt)){
            return formString(cnt);
        }else if(Delete(othmod, cnt) && Delete(othmod, cnt)){
            return formString(cnt);
        }

        return "";
    }

    bool Delete(int mod, vi &cnt){
        for(int i=1; i<10; i++){
            if(i%3==mod && cnt[i]){
                cnt[i]--;
                return true;
            }
        }
        return false;
    }

    string formString(vi &cnt){
        string s;
        for(int i=9; i>=0; i--){
            int times = cnt[i];
            if(i==0 && cnt[i] && s.size()==0) return "0";
            for(int t=0; t<times; t++){
                s+=to_string(i);
            }
        }
        return s;
    }
};

int main(){
    Solution sol; vi digits; string out;
    digits = {8,1,9};
    digits = {8,1,2,7,9};
    out = sol.largestMultipleOfThree(digits); deb(out);
    digits = {8,6,7,1,0};
    out = sol.largestMultipleOfThree(digits); deb(out);
    digits = {1};
    out = sol.largestMultipleOfThree(digits); deb(out);
    digits = {0,0,0,0,0,0};
    digits = {8,5};
    digits = {9,8,6,8,6};
    out = sol.largestMultipleOfThree(digits); deb(out);

    return 0;
}