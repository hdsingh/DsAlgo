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
template <typename T> ostream& operator<<(ostream &os, const vector<T> &v){print(v); return os;};
template <typename T> ostream& operator<<(ostream &os, const vector<vector<T>> &vv){print_vv(vv); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const map<T,U>  &m){print_m(m); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const pair<T, U> &pr){debp(pr); return os;};
template <class T, class U> ostream& operator<<(ostream &os, const vector<pair<T, U>> &vp){ print_vp(vp); return os;};

class Solution {
public:
    int calculate(string s) {
        int ans = 0, n = s.size();
        // 1. Convert to postfix
		// 2. Evaluate  Postfix

		vector<string> postfix;
		vector<char> operators;
		for(int i=0; i<n; ++i){
			if(s[i]==' ') continue;
			if(s[i]=='+' || s[i]=='-' || s[i]==')'){
				while(!operators.empty() && operators.back()!='('){
				    string bk;
                    bk+=operators.back();
                    postfix.push_back(bk);
                    operators.pop_back();
                }
    
                if(s[i]==')')
                    operators.pop_back();
                else 
				    operators.push_back(s[i]);
                
			}else if(s[i]=='('){
				operators.push_back('(');
			}else{
				int j = i;
				string num; num+=s[i];
				while(j+1<n && isdigit(s[j+1]))
					num+=s[j+1], ++j;	
				postfix.push_back(num);
				i = j;
			}
		}

		while(operators.size()){
			string cur;
			cur+=operators.back();
            operators.pop_back();
			assert(cur!="(");
			postfix.push_back(cur);
		}
        // print(postfix,1);
		stack<string> stk;
		for(auto val: postfix){
			if(val=="+" || val=="-"){
				int b = stoi(stk.top()); stk.pop();
				int a = stoi(stk.top()); stk.pop();
				if(val=="+") stk.push(to_string(a+b));
				else stk.push(to_string(a-b));
			}else 
				stk.push(val);
		}

		return stoi(stk.top());
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; string s; int out;
    s =  "1 + 1";
    s = " 2-1 + 2 ";
    s = "(1+(4+5+2)-3)-(6+8)+(59)";
    out = sol.calculate(s); deb(out);
    return 0;
}
