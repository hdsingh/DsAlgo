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

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        if(n==1) return votes[0];
        int m = votes[0].size();

        if(m==1) return votes[0];

        unordered_map<char, unordered_map<int,int>> cnt;
        // letter, pos, times
        for(auto vote: votes){
            for(int i=0; i<m; ++i){
                cnt[vote[i]][i]++;
            }
        }

        string res = votes[0];
        sort(res.begin(), res.end(), [&](char a, char b){
            int pos = 0;
            while(pos<m && cnt[a][pos]==cnt[b][pos]){
                ++pos;
            }
            if(pos==m)
                return a<b;
            return cnt[a][pos]>cnt[b][pos];
        });
        

        return res;
    }
};

int main(){
    vs votes; Solution sol; string out;
    votes = {"ABC","ACB","ABC","ACB","ACB"};
    out = sol.rankTeams(votes); deb(out);

    votes = {"ZMNAGUEDSJYLBOPHRQICWFXTVK"};
    out = sol.rankTeams(votes); deb(out);

    votes = {"BCA","CAB","CBA","ABC","ACB","BAC"};
    out = sol.rankTeams(votes); deb(out);

    votes = { "M","M","M","M" };
    out = sol.rankTeams(votes); deb(out);

    votes = { "WXYZ","XYZW" };
    out = sol.rankTeams(votes); deb(out);

    return 0;
}

