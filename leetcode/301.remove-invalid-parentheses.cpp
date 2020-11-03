#include <bits/stdc++.h>
using namespace std;

// Pruning by finding the left and right to remove
// + handling the (((((((((((( case by keeping track of 
// how many more '(' we have remaining and not removing only if
// there are sufficient rem, ie. rem_left>=left

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size(), left = 0, right = 0, bal = 0;
        int rem_left = 0;
        for(auto x: s){
            if(x=='('){
                ++bal;
                ++rem_left;
            }else if(x==')'){
                --bal;
                if(bal<0){
                    bal = 0;
                    ++right;
                }
            }
        }
        left = bal;
        
        unordered_set<string> out;
        string cur;
        dfs(0,0,left,right, s, cur, out, rem_left);
        return vector<string>(out.begin(), out.end());
    }
    
    void dfs(int pos, int bal, int left, int right, string &s, string &cur,  unordered_set<string> &out, int rem_left){
        if(pos==s.size()){
			if(bal==0)
				out.insert(cur);
			return;
		}
		if(left==0 && right==0){
			for(int i=pos; i<s.size(); ++i){
				if(s[i]=='(') ++bal;
				else if(s[i]==')') --bal;
				if(bal<0) return;
			}
			if(bal>0) return;
			out.insert(cur + s.substr(pos));	
			return;
		}

		if(s[pos]=='('){
            --rem_left;
            // I can afford not removing '(' only if the ')' on the right
            // are more
            
			// dont remove
            if(rem_left>=left){
                cur+=s[pos];
			    dfs(pos+1,bal+1,left,right,s,cur,out,rem_left);
			    cur.pop_back();
            }
			
			// remove
			if(left>0){
				dfs(pos+1,bal,left-1,right,s,cur,out,rem_left);
			}
		}else if(s[pos]==')'){
			// dont remove
			if(bal>0){
				cur+=s[pos];
				dfs(pos+1,bal-1,left,right,s,cur,out,rem_left);
				cur.pop_back();
			}
			// remove
			if(right>0){
				dfs(pos+1,bal,left,right-1,s,cur,out,rem_left);
			}
		}else{
			cur+=s[pos];
			dfs(pos+1,bal,left,right,s,cur,out,rem_left);
			cur.pop_back();	
		}
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}