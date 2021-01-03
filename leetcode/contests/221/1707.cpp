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

struct Node{
    Node* bit[2] = {};  
};

class Solution {
    Node* root;
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& qs) {
        int n = nums.size(), k = qs.size(); // [xi, mi]
        for(int i=0; i<k; ++i) qs[i].push_back(i);
        sort(qs.begin(), qs.end(), [&](vector<int> &v1, vector<int> &v2){
            return v1[1]<v2[1];  
        });
        
        sort(nums.begin(), nums.end());
        root = new Node();
        
        vector<int> ans(k);
        
        int idx = 0;
        for(int i=0; i<k; ++i){
            int xi = qs[i][0], mi = qs[i][1], qid = qs[i][2];
            while(idx<n && nums[idx]<=mi)
                insert(nums[idx++]);
            
            ans[qid] = maxXor(xi);
        }
        return ans;
        
    }
    
    void insert(int num){
        Node* cur = root;
        for(int i=31; i>=0; --i){
            int b = (num>>i)&1;
            if(!cur->bit[b]) cur->bit[b] = new Node();
            cur = cur->bit[b];
        }
    }
    
    int maxXor(int num){
        int ans = 0;
        Node* cur = root;
        for(int i=31; i>=0; --i){
            int b = (num>>i)&1;
            if(cur->bit[!b]){
                ans|=(1LL<<i);
                cur = cur->bit[!b];
            }else if(cur->bit[b]){
                cur = cur->bit[b];
            }else return -1;
        }
        return ans;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}