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

class Solution{
    int ans;
public:
    int countInv(vi &a){
        int n = a.size();
        ans = 0;
        mergeSort(0,n-1,a);
        return ans;
    }

    void mergeSort(int lt, int rt, vi &a){
        if(lt<rt){
            int mid = lt + (rt-lt)/2;
            
            mergeSort(lt,mid,a);
            mergeSort(mid+1,rt,a);

            merge(lt,rt,a);
        }
    }

    void merge(int lt, int rt, vi &a){
        int mid = (lt+rt)/2;
        int n1 = mid - lt + 1;
        int n2 = rt - mid;

        vi larr(n1), rarr(n2);
        for(int i=0; i<n1; ++i)
            larr[i] = a[lt+i];
        for(int j=0; j<n2; ++j)
            rarr[j] = a[mid+1+j];

        int i = 0, j = 0, k = lt;
        while(i<n1 && j<n2){
            if(larr[i]<=rarr[j]){
                a[k++] = larr[i++];
            }else{
                ans+=(n1-i);
                a[k++] = rarr[j++];
            }
        }

        while(i<n1) a[k++] = larr[i++];
        while(j<n2) a[k++] =  rarr[j++];
    }

};

void getinv(vi a){
    int n = a.size();
    int ans = 0;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(a[i]>a[j])
                ++ans;
        }
    }
    deb("inv:", ans);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vi a = {8,2,1,4,5,69,20,2,1,};
    getinv(a);
    Solution sol; int out = sol.countInv(a);
    deb(out);
    cout<<a;
    return 0;
}