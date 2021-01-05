#include <bits/stdc++.h>
using namespace std;

template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }
const int inf = 1e9;
array<int,2> dfs(int st, int ed, string &s, vector<int> &end, vector<int> &div){
    array<int,2> out = {inf,inf};
    if(st==ed){
        // assert(s[st]=='1' || s[st]=='0');
        out[0] = (s[st]=='1'); out[1] = (s[st]=='0');
        return out;
    }
    
    int sym = div[st];
    if(!sym){
        return dfs(st+1,ed-1,s,end,div);
    }
    auto lt = dfs(st+1,sym-1,s,end,div);
    auto rt = dfs(sym+1,ed-1,s,end,div);
    char op = s[sym];

    for(int i=0; i<=1; ++i){
        for(int j=0; j<=1; ++j){
            min_self(out[i|j], (lt[i] + rt[j]) + (op!='|'));
            min_self(out[i&j], (lt[i] + rt[j]) + (op!='&'));
        }
    }
    
    return out;
};

int solve(string s) {
    s = "(" + s + ")";
    int n = s.size(); 
    stack<int> stk;  
    
    vector<int> end(n), div(n);
    // pos of ')' , operator
    for(int i=0; i<n; ++i){
        if(s[i]=='(' || s[i]=='|' || s[i]=='&'){
            stk.push(i);
        }else if(s[i]==')'){
            if(s[stk.top()]=='('){
                end[stk.top()] = i;
                stk.pop();
            }else{
                int sym = stk.top(); stk.pop();
                int st  = stk.top(); stk.pop();
                end[st] = i;
                div[st] = sym;
            }
        }
    }

    auto arr = dfs(0,n-1,s,end,div);
    // assert(arr[0]==0 || arr[1]==0);
    return max(arr[0], arr[1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}