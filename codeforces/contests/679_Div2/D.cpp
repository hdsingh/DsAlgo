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


// Solve greedily
// 1. upon encountering a '+', add the largest unplaced number.
// 2. upon '-', the smallest placed num is  S
// a. if x==s, remove (sell it);
// b. if x<S, add S back to unplaced and remove x from unplaced and sell it.
//     exchanging their ids
// c. if x>S, this is invalid because the smaller num should have been sold.
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    while(cin>>n){
        vector<pii> inp(2*n);
        forn(i,2*n){
            char c; cin>>c;
            if(c=='+'){
                inp[i].first = 1;
            }else{
                int x; cin>>x;
                inp[i].second = x;
            }
        }

        set<int> notPlaced;
        fore(i,1,n+1) notPlaced.insert(i);
        

        set<int> placed;
        vector<int> loc(n+1,-1);
        int id = 0;
        bool valid = true;
        forn(i,2*n){
            if(inp[i].first){ // '+'
                if(notPlaced.empty()){
                    valid = false;
                }else{
                    loc[*notPlaced.rbegin()] = id++;
                    placed.insert(*notPlaced.rbegin());
                    notPlaced.erase(*notPlaced.rbegin());
                }
            }else{
                int x = inp[i].second;
                if(placed.empty() || *placed.begin()<x){
                    valid = false;
                }else{
                    if(*placed.begin()==x){
                        // sell
                        placed.erase(placed.begin());
                    }else{ // >X
                        // place and sell
                        int top = *placed.begin();
                        placed.erase(top);

                        loc[x] = loc[top];
                        loc[top] = -1; 
                        assert(notPlaced.count(x));
                        notPlaced.erase(x);
                        
                        notPlaced.insert(top);
                    }
                }
            }
        }

        vector<int> order(n);
        fore(i,1,n+1){
            if(loc[i]==-1){
                valid = false;
            }else{
                order[loc[i]] = i;
            }
        }

        if(valid){
            id = 0;
            // verify
            placed.clear();
            forn(i,2*n){
                if(inp[i].first){
                    placed.insert(order[id++]);
                }else{
                    int x = inp[i].second;
                    if(placed.empty() ||  x!=*placed.begin()){
                        valid = false; break;
                    }
                    placed.erase(placed.begin());
                }
            }
        }

        if(valid){
            cout<<"YES\n";
            print(order);
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}


// O(n) Stack
int main1(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n){
        bool valid = 1;
        stack<int> stk;
        vector<int> order;
        vector<pii> inp(2*n);
        forn(i,2*n){
            char c; cin>>c;
            if(c=='+'){
                inp[i].first = 1;
            }else{
                int x; cin>>x;
                inp[i].second = x;
            }
        }

        for(int i=2*n-1; i>=0; --i){
            if(inp[i].first){
                if(stk.empty()){
                    valid = false;
                    break;
                }else{
                    order.pb(stk.top());
                    stk.pop();
                }
            }else{
                int x = inp[i].second;
                if(!stk.empty() && stk.top()<x){
                    valid =  false; break;
                }else{
                    stk.push(x);
                }
            }
        }
        reverse(all(order));
        if(valid){
            cout<<"YES\n";
            print(order);
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}