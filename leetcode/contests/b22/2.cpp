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


class Solution0 {
    const int mid = 120, left = 480, right = 30, al= 1023;   
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        vector<int> seats(n, al);
        for(auto x: res){
            int row = x[0]-1;
            int pos = x[1]-1;
            seats[row]^=(1<<pos);
        }

        int cnt = 0;
        for(auto r: seats){
            int m_avail = (r&mid) == mid;
            int l_avail = (r&left) == left;
            int r_avail = (r&right) == right;
    
            if(l_avail & r_avail)
                cnt+=2;
            else if(m_avail | l_avail | r_avail)
                cnt+=1;
        }
        return cnt;
    }
};

class Solution {
    const int mid = 120, left = 480, right = 30, al= 1023;   
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        int m =res.size();
        map<int, vi> save;
        for(auto r: res){
            save[r[0]].push_back(r[1]-1);
        }

        int tot = n*2;
        for(auto &p: save){
            int row = al;
            for(auto pos: p.second)
                row^=(1<<pos);
            
            int m_avail = (row&mid)==mid;
            int l_avail = (row&left)==left;
            int r_avail = (row&right)==right;

            if(l_avail & r_avail & m_avail)
                tot-=0;
            else if(l_avail | r_avail | m_avail)
                tot-=1;
            else 
                tot-=2;
        }

        return tot;
    }
};

int main(){
    Solution sol; vvi reservedSeats; int n, out;
    n = 3, reservedSeats = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
    out = sol.maxNumberOfFamilies(n, reservedSeats); deb(out);

    n = 2, reservedSeats = {{2,1},{1,8},{2,6}};
    out = sol.maxNumberOfFamilies(n, reservedSeats); deb(out);

    n = 4, reservedSeats = {{4,3},{1,4},{4,6},{1,7}};
    out = sol.maxNumberOfFamilies(n, reservedSeats); deb(out);

    return 0;
}