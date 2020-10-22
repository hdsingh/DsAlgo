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
    vector<int> last, out;
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        last.assign(logs.size(),0);
        out.assign(n,0);
        stack<int> stk;
        for(int i=0; i<logs.size(); ++i){
            if(is_start(logs[i])){
                stk.push(i);
            }else{
                last[stk.top()] = i;
                stk.pop();
            }
        }
        
        dfs(0,logs.size()-1, logs);
        return out;
    }
    
    int dfs(int st, int ed, vector<string> &logs){
        if(st>ed) return 0;
        int st_time = find_time(logs[st]);
        int ed_time = find_time(logs[ed]);
        int id = find_id(logs[st]);
        
        if(last[st]==ed){
            assert(find_id(logs[ed])==id);
            int inside = dfs(st+1, ed-1, logs);
            out[id]+= ed_time - st_time + 1 - inside;
            return ed_time - st_time + 1;
        }
        
        return dfs(st, last[st], logs) + dfs(last[st]+1, ed, logs);
    }
    
    bool is_start(string &s){
        for(int i=0; i<s.size(); ++i){
            if(i+1<s.size() && s[i]==':' && s[i+1]=='s')
                return true;
        }
        return false;
    }
    
    int find_id(string &s){
        string out;
        for(int i=0; i<s.size(); ++i){
            if(s[i]!=':')
                out+=s[i];
            else break;
        }
        return stoi(out);
    }
    
    int find_time(string &s){
        string out;
        for(int i=s.size()-1; i>=0; --i){
            if(s[i]!=':')
                out = s[i] + out;
            else break;
        }
        return stoi(out);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}