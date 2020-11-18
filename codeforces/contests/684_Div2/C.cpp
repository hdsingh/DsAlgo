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

vvi out;

// .. 00
void p1(int x, int y, vvi &a){
    out.pb({x+0,y+1, x+1,y+1, x+1,y+0}); 
    for(int i=0; i<6; i+=2){
        int x = out.back()[i], y = out.back()[i+1];
        a[x][y]^=1;
    }
    // cout<<a;
}

// 0 1
void p2(int x, int y, vvi &a){
    out.pb({x+0,y+0, x+1,y+0, x+1,y+1});
    for(int i=0; i<6; i+=2){
        int x = out.back()[i], y = out.back()[i+1];
        a[x][y]^=1;
    }
    // cout<<a;
}

// 11
void p3(int x, int y, vvi &a){
    out.pb({x+1,y+0, x+0,y+1, x+0,y+0});
    for(int i=0; i<6; i+=2){
        int x = out.back()[i], y = out.back()[i+1];
        a[x][y]^=1;
    }
    // cout<<a;/
}

// 1,0
void p4(int x, int y, vvi &a){
    out.pb({x+0,y+0, x+0,y+1, x+1,y+1});
    for(int i=0; i<6; i+=2){
        int x = out.back()[i], y = out.back()[i+1];
        a[x][y]^=1;
    }
    // cout<<a;
}

void is_23(int x, int y, vvi &a){
    int sum = a[x][y] + a[x+1][y] + a[x][y+1] + a[x+1][y+1] + a[x][y+2] + a[x+1][y+2];
    if(sum!=6) return;
    p3(x,y,a); p1(x,y+1,a);
};

void is_32(int x, int y, vvi &a){
    int sum = a[x][y] + a[x+1][y] + a[x][y+1] + a[x+1][y+1] + a[x+2][y] + a[x+2][y+1];
    if(sum!=6) return;
    p3(x,y,a); p1(x+1,y,a);

};

void is_3mask(int x, int y, vvi &a){
    int sum = a[x][y] + a[x+1][y] + a[x][y+1] + a[x+1][y+1];
    if(sum!=3) return; 
    if(a[x][y]==0){
        p1(x,y,a);
    }else if(a[x+1][y]==0){
        p4(x,y,a);
    }else if(a[x][y+1]==0){
        p2(x,y,a);
    }else if(a[x+1][y+1]==0){
        p3(x,y,a);
    }
};

void is_2mask(int x, int y, vvi &a){
    int sum = a[x][y] + a[x+1][y] + a[x][y+1] + a[x+1][y+1];
    // deb(sum);
    if(sum!=2) return;
    if(a[x+0][y+0] && a[x+1][y+0]){
        p4(x,y,a); p1(x,y,a);
    }else if(a[x+0][y+0] && a[x+0][y+1]){
        p2(x,y,a); p1(x,y,a);
    }else if(a[x+0][y+1] && a[x+1][y+1]){
        p3(x,y,a); p2(x,y,a);
    }else if(a[x+1][y+0] && a[x+1][y+1]){
        p3(x,y,a); p4(x,y,a);
    }else if(a[x+0][y+0] && a[x+1][y+1]){
        p3(x,y,a); p1(x,y,a);
    }else if(a[x+0][y+1] && a[x+1][y+0]){
        p4(x,y,a); p2(x,y,a);
    }
};

void is_1mask(int x, int y, vvi &a){
    int sum = a[x][y] + a[x+1][y] + a[x][y+1] + a[x+1][y+1];
    if(sum!=1) return;
    if(a[x+0][y+0]){
        p2(x,y,a); p4(x,y,a); p3(x,y,a);
    }else if(a[x+0][y+1]){
        p1(x,y,a); p4(x,y,a); p3(x,y,a);
    }else if(a[x+1][y+0]){
        p3(x,y,a); p2(x,y,a); p1(x,y,a);
    }else if(a[x+1][y+1]){
        p4(x,y,a); p2(x,y,a); p1(x,y,a); 
    }
};

void is_full(int x, int y, vvi &a){
    int sum = a[x][y] + a[x+1][y] + a[x][y+1] + a[x+1][y+1];
    if(sum!=4) return;
    p2(x,y,a); p3(x,y,a); p1(x,y,a);p4(x,y,a);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        out.clear();
        int n, m; cin>>n>>m;
        vvi a(n, vi(m));
        forn(i,n){
            forn(j,m){
                char c; cin>>c;
                a[i][j] = (c=='1');
            }
        }
        
        // slide 2*3
        for(int i=0; i<=n-2; ++i){
            for(int j=0; j<=m-3; ++j){
                is_23(i,j,a);
            }
        }


        // slide 3*2
        for(int i=0; i<=n-3; ++i){
            for(int j=0; j<=m-2; ++j){
                is_32(i,j,a);
            }
        }

        // slide 2*2 start
        // 3 mask
        for(int i=0; i<=n-2; ++i){
            for(int j=0; j<=m-2; ++j){
                if(i==n-2 || j==m-2){
                    is_3mask(i,j,a);
                    is_2mask(i,j,a);
                    is_1mask(i,j,a);
                    is_full(i,j,a);
                }
            }
        }

        for(int i=0; i<=n-2; ++i){
            for(int j=0; j<=m-2; ++j){
                is_3mask(i,j,a);
                is_2mask(i,j,a);
                is_1mask(i,j,a);
                is_full(i,j,a);
            }
        }
        // 2 mask

        // 1 mask

        // 4 mask
        cout<<out.size()<<"\n";
        // deb(out.size()<3*n*m);
        // cout<<a;

        for(auto o: out){
            for(auto x: o){
                cout<<x+1<<" ";
            }
            cout<<"\n";
        }

    }
    return 0;
}