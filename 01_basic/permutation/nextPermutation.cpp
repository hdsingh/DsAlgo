#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
const int inf = 1e9 + 5;

template <typename T>void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>void print_vv(T v, bool same_line=true){for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

class PermutationGenerator{
    int size;
    vi base;

    void swap(vi::iterator a, vi::iterator b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
public:
    PermutationGenerator(int n){
        size = n;
    }

    vi operator() (){

        if(base.size()==0){
            forn(i, size)
                base.pb(i);
            return base;
        }

        vi::iterator decrease_iter = base.end()-2;
        while(decrease_iter>=base.begin() && *decrease_iter > *(decrease_iter+1)){
            if(decrease_iter==base.begin())
                return {}; //end of all permutations
            decrease_iter--;
        }

        vi::iterator next_large_iter = base.end() - 1;
        while(*next_large_iter < *decrease_iter)
            next_large_iter--;
        
        swap(decrease_iter, next_large_iter);

        // reverse the numbers in the suffix
        vi::iterator right = base.end()-1;
        vi::iterator left = decrease_iter + 1;

        while(left<right){
            swap(left, right);
            right--;
            left++;
        }

        return base;
    }
};


int main(){
    PermutationGenerator p(5);
    vi out = p();
    print(out);
    vi out1 = out;
    while(!out.empty()){
        next_permutation(all(out1));
        out = p();
        print(out);
        print(out1);
        cout<<(out1==out)<<endl;
    }

    return 0;
}