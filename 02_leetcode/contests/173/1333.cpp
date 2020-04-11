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
                  //   0     1        2              3        4
// restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& rest, int veg, int mPrice, int mDist) {
        vector<int> good;
        // sort(rest.begin(), rest.end(), )
        map<int,int> idPos;
        
        int i = 0;
        for(auto &x: rest){
            idPos[x[0]] = i++;
            if(x[4]<=mDist && x[3]<=mPrice){
                if(veg==1){
                    if(x[2]){
                        good.push_back(x[0]);
                    }
                }else{
                    good.push_back(x[0]);
                }
            }
        }

        // print(good);

        sort(good.begin(), good.end(), [&](int id1, int id2){
            if(rest[idPos[id1]][1]==rest[idPos[id2]][1]){
                return id1>id2;
            }
            return rest[idPos[id1]][1]>rest[idPos[id2]][1];
        });
           
        return good;
    }
};

int main(){
    vvi restaurants; 
    int veganFriendly, maxPrice, maxDistance; vi out;
    restaurants = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}}, 
    veganFriendly = 1, maxPrice = 50, maxDistance = 10;
    Solution sol;
    out = sol.filterRestaurants(restaurants,veganFriendly,maxPrice,maxDistance); print(out);

    restaurants = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}}, veganFriendly = 0, maxPrice = 50, maxDistance = 10;
    out = sol.filterRestaurants(restaurants,veganFriendly,maxPrice,maxDistance); print(out);

restaurants = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}}, veganFriendly = 0, maxPrice = 30, maxDistance = 3;
    out = sol.filterRestaurants(restaurants,veganFriendly,maxPrice,maxDistance); print(out);

    return 0;
}