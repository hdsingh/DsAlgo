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
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();
        vector<int> isPalA(n), isPalB(n);
        int lt = n/2, rt = n/2;
        if(n%2==0) --lt;
        while(lt>=0 && rt<n){
            if(a[lt]==a[rt])
                isPalA[lt--] = isPalA[rt++] = 1;
            else break;
        }
        lt = n/2, rt = n/2;
        if(n%2==0) --lt;

        while(lt>=0 && rt<n){
            if(b[lt]==b[rt])
                isPalB[lt--] = isPalB[rt++] = 1;
            else break;
        }
        
        if(isPalA.back() || isPalB.back()) return 1;
        
        // A,   sufB + B
        for(int i=0; i<n/2; ++i){
            if(a[i]==b[n-1-i]){
                if(i+1<n/2){
                    if(isPalB[i+1] || isPalA[i+1])
                        return true;
                }else 
                    return true;
            }else break;
        }
        
        for(int i=0; i<n/2; ++i){
            if(b[i]==a[n-1-i]){
                if(i+1<n/2){
                    if(isPalA[i+1] || isPalB[i+1])
                        return true;
                }else 
                    return true;
            }else break;
        }
    
        return false;
    }
};

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a,b) || check(b,a);
    }
    
    bool check(string &a, string &b){
        int i = 0, j = a.size()-1;
        while(i<j && a[i]==b[j])
            ++i, --j;
        return isPal(a,i,j) || isPal(b,i,j);
    }
    
    bool isPal(string &a, int i, int j){
        while(i<j && a[i]==a[j])
            ++i, --j;
        return i>=j;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; string a, b; int out;
    // a = "x", b = "y";
    // out = sol.checkPalindromeFormation(a,b); deb(out);
    // a = "abdef", b = "fecab";
    // out = sol.checkPalindromeFormation(a,b); deb(out);
    // a = "ulacfd", b = "jizalu";
    // out = sol.checkPalindromeFormation(a,b); deb(out);
    // a = "xbdef", b = "xecab";
    a = "xbftdef", b = "oedrfbx";
    a = "pvhmupgqeltozftlmfjjde", b = "yjgpzbezspnnpszebzmhvp";
    a = "aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd", b = "uvebspqckawkhbrtlqwblfwzfptanhiglaabjea";
    out = sol.checkPalindromeFormation(a,b); deb(out);
    return 0;
}