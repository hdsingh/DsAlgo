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

struct Point {
    double x=0, y=0;
    Point(){};
    Point(double X, double Y):  x(X), y(Y) {};
};


class Solution {
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<Point> pts;
    double sqr(double x){
        return x*x;
    }

    double dist(Point a, Point b){
        return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));
    }

    double tot_dist(Point a){ // from all other points
        double sum = 0;
        for(auto p: pts)
            sum+=dist(p, a);
        return sum;
    }

public:
    double getMinDistSum(vector<vector<int>>& positions) {
        pts.clear();
        int n = positions.size();
        for(auto p: positions){
            pts.push_back(Point(p[0], p[1]));
        }

        Point best;
        for(auto p: pts)
            best.x+=p.x, best.y+=p.y;

        best.x/=n; best.y/=n;

        // for a particular steps try to minimise in all the directions,
        // in case no minimisation happens, reduce the step.
        for(double step = 50; step>1e-6; ){
            bool found = 0;
            for(auto dir: dirs){
                Point nbest = {best.x + step*dir[0], best.y +  step*dir[1]};
                if(tot_dist(nbest)<tot_dist(best)){
                    best = nbest;
                    found = 1;
                }
            }

            if(!found) step/=2;
        }

        return tot_dist(best);
    }
};

int main(){
    Solution sol; 
    vector<vvi> ps = {
        {{0,1},{1,0},{1,2},{2,1}},
        {{1,1},{3,3}},
        {{1,1}},
        {{1,1},{0,0},{2,0}},
        {{0,1},{3,2},{4,5},{7,6},{8,9},{11,1},{2,12}},

    };
    for(auto p: ps){
        double out = sol.getMinDistSum(p);
        cout<<setprecision(7)<<out<<"\n";
    }
    return 0;
}