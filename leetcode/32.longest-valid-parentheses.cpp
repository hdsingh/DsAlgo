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

// Refer: https://leetcode.com/problems/longest-valid-parentheses/solution/

// TLE
class Solution0 {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int mxlen = 0;
        // print(s,1);

        for(int i=0; i<n; ++i){
            if(s[i]==')') continue;
            string stk;
            int len =  0; bool valid = 1;

            for(int j=i; j<n; ++j){
                if(s[j]=='(') stk.push_back('(');
                else{
                    if(stk.size() && stk.back()=='('){
                        stk.pop_back(), len+=2;
                    }else{
                        valid = false; 
                        break;
                    }

                    if(valid && stk.empty() && len>mxlen)
                        mxlen = len;
                }

            }
        }
    
        return mxlen;
    }
};

// Using dp + observation:
class Solution1 {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int mxlen = 0;
        vi dp(n); // len of longest valid seq ending at i
        for(int i=1; i<n; ++i){
            if(s[i]=='(') continue;
            if(s[i-1]=='('){
                dp[i] = (i-2>=0 ? dp[i-2] : 0) + 2;
            }else{
                // s[i-1]==')', check if the char just before the corresponding
                // start of s[i-1] is a '(' and pair it with s[i] to make '( (....) )'
                // and also add the prev len before start
                if(i-dp[i-1] - 1>=0 && s[i - dp[i-1] - 1]=='('){
                    int prev = (i- dp[i-1] - 2>=0) ? dp[i - dp[i-1] - 2] : 0;
                    dp[i] =  prev + dp[i-1] + 2;
                }
            }
            mxlen = max(mxlen, dp[i]);
        }

        // print(s,1);
        // print(dp);

        return mxlen;
    }
};

// Simple stack based
// not useful index -> which can't be paired with any char
// Always keep a most recent not useful index.
// when we encounter a '(', save its index.
// Upon encountering ')', pop out the top most index, 
// assuming it to be a valid '(' index, and take the
// difference with stack's top.
// If the stack becomes empty, then push cur index.
class Solution2 {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        stk.push(-1);

        int mxlen = 0;
        for(int i=0; i<n; ++i){
            if(s[i]=='(')
                stk.push(i);
            else{
                stk.pop();
                if(stk.empty()) stk.push(i);
                mxlen = max(mxlen, i - stk.top());
            }
        }

        return mxlen;
    }
};

// Simple traversal and stack conditions
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int left = 0, right = 0, mxlen = 0;
        for(int i=0; i<n; ++i){
            if(s[i]=='(') ++left;
            else ++right;
            
            if(left==right)
                mxlen = max(mxlen, 2*left);
            else if(right>left)
                left = 0, right =0;
        }

        left = 0, right = 0;
        
        for(int i=n-1; i>=0; --i){
            if(s[i]==')') ++right;
            else ++left;
            
            if(left==right)
                mxlen = max(mxlen, 2*left);
            else if(left>right)
                left = 0, right = 0;
        }

        return mxlen;
    }
};


int main(){
    Solution sol; 
    vs ss = {
        "(()",
        ")()())",
        "()((((()))()",
    };
    for(auto s: ss){
        int out = sol.longestValidParentheses(s); deb(out);
        cout<<"\n\n";
    }
    return 0;
}