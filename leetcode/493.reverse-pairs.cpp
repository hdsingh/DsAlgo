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
    int N;
    vi st;
public:
    int reversePairs(vector<int>& nums) {
        map<ll,int> m;
        for(auto x: nums) m[x] = 1;
        int id = 0;
        for(auto &p: m) p.second = id++;
        N = id;
        st.assign(4*N,0);

        int ans = 0;
        for(auto x: nums){
            auto pos = m.upper_bound(2LL*x);
            if(pos!=m.end()){
                int idx = pos->second;
                ans+=query(1,0,N-1,idx,N-1);
            }
            update(1,0,N-1,m[x]);
        }

        return ans;
    }

    int query(int pos, int sl, int sr, int l, int r){
        if(sr<l || r<sl) return 0;
        if (l<=sl && sr<=r) return st[pos];
        int mid = (sl+sr)/2;
        return query(2*pos, sl, mid, l, r) + query(2*pos+1, mid+1,sr, l, r);
    }

    void update(int pos, int sl, int sr, int idx){
        if(sl==sr){
            st[pos]++;
            return;
        }
        int mid = (sl+sr)/2;
        if(idx<=mid) update(2*pos,sl,mid,idx);
        else update(2*pos+1, mid+1, sr, idx);
        st[pos] = st[2*pos] + st[2*pos+1];
    }
};


// prev > 2*cur
// [l.. mid][mid+1..rt]

class Solution {
	int ans = 0;
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();	
		ans = 0;
		mergeSort(0,n-1,nums);
		return ans;
    }
	
	void mergeSort(int lt, int rt, vector<int> &nums){
		if(lt<rt){
			int mid = (lt+rt)/2;
			mergeSort(lt, mid, nums);
			mergeSort(mid+1,rt, nums);
			
			merge(lt, rt, nums);
		}
	}
	
	void merge(int lt, int rt, vector<int> &nums){
		int mid = (lt+rt)/2;
		int n1 = mid-lt+1;
		int n2 = rt-mid;
		
		vector<int> L(n1), R(n2);
		for(int i=0; i<n1; ++i)
			L[i] = nums[lt+i];
		for(int i=0; i<n2; ++i)
			R[i] = nums[mid+1+i];

		int ptr = 0;
		for(int i=0; i<n2; ++i){
			while(ptr<n1 && L[ptr]<=2LL*R[i])
				++ptr;
			ans+=(n1-ptr);
		}
		
		int i = 0, j = 0, k = lt;
		while(i<n1 && j<n2){
			if(L[i]<=R[j])
				nums[k++] = L[i++];
			else 
				nums[k++] = R[j++];
		}
		while(i<n1) nums[k++] = L[i++];
		while(j<n2) nums[k++] = R[j++];
	}
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution sol; vi a; int out;
    a = {2,4,3,5,1};
    a = {1,3,2,3,1};
    out = sol.reversePairs(a); deb(out);
    return 0;
}