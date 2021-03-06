#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) int((a).size())
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

#define _deb(x) cout<<x;
void _print() {cerr << "]\n";} template <typename T, typename... V>void _print(T t, V... v) {_deb(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
template <class T, class U> void print_m(const map<T,U> &m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}
template<class T, class U>void debp(const pair<T, U> &pr, bool end_line=1){cout<<"{"<<pr.first<<" "<<pr.second<<"}"; cout<<(end_line ? "\n" : ", ");}
template <class T> void print_vp(const T &vp, int sep_line=0){if(vp.empty()){cout<<"Empty"<<endl; return;}if(!sep_line) cout<<"{ ";for(auto x: vp) debp(x,sep_line);if(!sep_line) cout<<"}\n";cout<<endl;}
template <typename T>void print(const T &v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<sz(v); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<endl;}
template <typename T>void print_vv(const T &vv){if(sz(vv)==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<sz(*vv.begin()); j++)cout<<setw(w)<<j<<" ";cout<<endl;int i = 0;for(auto &v: vv){cout<<i++<<" {";for(auto &el: v) cout<<setw(w)<<el<<" ";cout<<"},\n";}cout<<endl;}

// Refer: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/discuss/779928/Simple-O(n)-stack-solution-with-detailed-explanation

class Solution {
public:
    int minInsertions(string s) {
        int n = sz(s);
        stack<int> stk; // represents ')' needed
        int ans = 0;
        for(auto x: s){
            if(x=='('){
                if(sz(stk)==0 || stk.top()==2)
                    stk.push(2);
                else{
                    stk.pop(); // prev seen () 
                    ++ans;
                    stk.push(2);
                }
            }else{
                if(sz(stk) && stk.top()==2){
                    stk.pop(); stk.push(1);
                }else if(stk.empty()){
                    stk.push(1); ++ans;
                }else if(sz(stk) && stk.top()==1){
                    stk.pop();
                }
            }
        }
        while(sz(stk)){
            ans+=stk.top(); stk.pop();
        }
        return ans;
    }
};

// upon encountering '(' push it in stack (l++);
// upon ')' 
// 1. next char = ')'
//  have some l, 
//           :pop it , add 0
//       else 
//           add +1 to ans to add a new '('
//     move to i+2
//  else 
//     have some l,
//         use it, add 1 for ')' at next pos
//     else 
//         add +2 for '(' at prev and ')' at next. 
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, l = 0, n = s.size();
        for(int i=0; i<n; ++i){
            if(s[i]=='(') ++l;
            else{
                if(i+1<n && s[i+1]==')'){
                    if(l==0){
                        ans+=1;
                    }else --l;
                    i+=1;
                }else{
                    if(l==0){
                        ans+=2;
                    }else 
                        ans+=1, --l;
                }
            }
        }
        return ans + 2*l;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol;
    vs ss = {
        "(()))",
        "())",
        "))())(", 
        "((((((", 
        ")))))))",
        "()()()()()(",
        "(()))(()))()())))",
        "(()((()((",
        } ;
    for(auto s: ss){
        int out = sol.minInsertions(s);
        deb(out); 
    }
    return 0;
}