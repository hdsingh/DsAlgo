#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
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

template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; string s;
    cin>>t;
    while(t--){
        cin>>s;
        int n = s.size();
        deque<char> q;
        map<char,bool> used;
        map<char,char> left;
        map<char,char> right;
        q.push_back(s[0]);
        used[s[0]] = true;
        
        bool valid = true;

        for(int i=1; i<n; ++i){
            if(used[s[i]]){
                if((right.count(s[i-1]) && right[s[i-1]]==s[i])) continue;
            
                if((left.count(s[i-1]) && left[s[i-1]]==s[i] )) continue;

                valid = false;
                break;
            }
            
            if(!right.count(s[i-1])){
                q.push_back(s[i]);
                right[s[i-1]] = s[i];
                left[s[i]] = s[i-1];
                used[s[i]] = true;
            }else if(!left.count(s[i-1])){
                q.push_front(s[i]);
                right[s[i]] =  s[i-1];
                left[s[i-1]] = s[i];
                used[s[i]] = true;
            }else{
                valid = false;
                break;
            }
        }        


        // print_m(left);
        // print_m(right);

        if(valid){
            cout<<"YES"<<endl;
            string out;
            while(!q.empty()){
                out+=q.front(); q.pop_front();
            }

            for(auto x: out) used[x] = true;
            cout<<out;
            for(char c='a'; c<='z'; ++c)
                if(!used[c]) cout<<c;
            cout<<endl;

        }else{  
            cout<<"NO"<<endl;
        }
        // cout<<endl;
    }
    return 0;
}