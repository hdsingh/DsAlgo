#include <bits/stdc++.h>
using namespace std;

template<class T, class U> inline void min_self(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void max_self(T &x, U y) { if (y > x) x = y; }


class Solution {
    vector<int>  lt, rt,up,dn;
public:
    bool isPrintable(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_set<int> rem;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                rem.insert(grid[i][j]);
            }
        }
        lt.assign(61,m), rt.assign(61,0), up.assign(61,n), dn.assign(61,0);
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int val = grid[i][j];
                min_self(lt[val], j); max_self(rt[val], j);
                min_self(up[val], i); max_self(dn[val], i);
            }
        }
        
        return can(grid, rem);
    }
    
    // rect with a color to be removed
    bool can(vector<vector<int>> &grid, unordered_set<int> &rem){
        int n = grid.size(), m = grid[0].size();
        if(rem.empty()) return true;
        bool found = false;
        
        for(auto num: rem){
            bool good = true;
            for(int i=up[num]; i<=dn[num]; ++i){
                for(int j=lt[num]; j<=rt[num]; ++j){
                    if(grid[i][j]!=num && grid[i][j]!=0){
                        good = false;
                        break;
                    }
                }
            }
            if(good){
                found = true;
                rem.erase(num);
                for(int i=up[num]; i<=dn[num]; ++i){
                    for(int j=lt[num]; j<=rt[num]; ++j){
                        grid[i][j] = 0;
                    }
                }
                
                break;
            }
        }
        
        if(!found) return false;
        return can(grid, rem);
    };
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}