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
    const int P = 10;
    const vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<int> pw;
public:
    const int TARGET = 876543210;
    int solve(vector<vector<int>>& board){
        pw.resize(9);
        pw[0] = 1;
        for(int i=1; i<9; ++i)
            pw[i] = pw[i-1]*P;
        
        if(encode(board)==TARGET){
            return 0;
        }
    
        queue<pair<vector<vector<int>>, int>> q; // board, pos of 0
        int cur = -1;
        for(int i=0; i<3; ++i)
            for(int j=0; j<3; ++j)
                if(board[i][j]==0){
                    cur = 3*i+j;
                    break;
                }    
    
        if(cur==-1) return -1;
        
        q.push({board, cur});
        set<int> seen;
        seen.insert(encode(board));
        
        int dist = 1;
        while(!q.empty()){
            queue<pair<vector<vector<int>>, int>> nq;
            
            while(!q.empty()){
                auto [board, cur] = q.front();
                q.pop();
                int x = cur/3, y = cur%3;
                assert(board[x][y]==0);
                
                for(auto dir: dirs){
                    int nx = x + dir[0], ny = y + dir[1];
                    if(nx<0 || nx>=3 || ny<0 || ny>=3)  continue;
                    
                    swap(board[x][y], board[nx][ny]);
                    int hash = encode(board);
                    if(hash==TARGET) return dist;
                    if(!seen.count(hash)){
                        seen.insert(hash);
                        assert(board[nx][ny]==0);
                        nq.push({board, nx*3+ny});
                    }
                    swap(board[x][y], board[nx][ny]);
                }
            }
            
            q = nq;
            ++dist;
        }
        
        return -1;
    }
    
    int encode(vector<vector<int>> &board){
        int ans = 0;
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                ans += pw[3*i+j]*board[i][j];
            }
        }
        return ans;
    }
    
    vector<vector<int>> decode(long long hash){
        vector<vector<int>> board(3,vector<int>(3));
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                board[i][j] = hash%P;
                hash/=P;
            }
        }
        return board;
    }
};

int solve(vector<vector<int>>& board) {
    Solution sol; return sol.solve(board);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}