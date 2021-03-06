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

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        multiset<int> window(a.begin(), a.begin()+k);
        auto mid = next(window.begin(), k/2);
        int n = a.size();
        vector<double> medians;
        for(int i=k; ; ++i){
            double med = ((double)*mid + *prev(mid, 1 - k%2))/2;
            medians.push_back(med);

            if(i==n) return medians;
            // insert first because incase of single element we need sth to shift to
            window.insert(a[i]);
            if(a[i]<*mid)
                --mid;
            
            if(a[i-k]<=*mid)
                ++mid;
            window.erase(window.lower_bound(a[i-k]));
        }

    }
};

class Solution {
    multiset<int> lo, hi;
public:
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        int n = a.size();
        vector<double> out;

        for(int i=0; i<=n; ++i){
            if(i>=k){
                out.push_back(median());
                remove(a[i-k]);
            }
            if(i==n) break;
            add(a[i]);
        }

        return out;
    }

    void add(int x){
        if(lo.empty()){
            lo.insert(x);
            return;
        }
        
        if(x<*lo.rbegin()){
            lo.insert(x);
        }else{
            hi.insert(x);
        }

        balance();
    }

    void remove(int x){
        if(x<=*lo.rbegin()){
            assert(lo.find(x)!=lo.end());
            lo.erase(lo.find(x));
        }else{
            assert(hi.find(x)!=hi.end());
            hi.erase(hi.find(x));
        }
        balance();
    }

    void balance(){
        if(lo.size()){
            hi.insert(*lo.rbegin());
            lo.erase(lo.find(*lo.rbegin()));
        }

        while(hi.size()>lo.size()){
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    }

    double median(){
        if(lo.size()>hi.size())
            return *lo.rbegin();
        return ((double)*lo.rbegin() + *hi.begin())/2;
    }
};

int main(){
    
    return 0;
}