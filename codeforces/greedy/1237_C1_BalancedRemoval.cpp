#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define fo(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for (int i = int(a); i <=int(b); i++)
#define all(x) x.begin(), x.end()
typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

template <typename T>
void print_vv(T v, bool same_line=true){
    for(auto i= 0; i<v.size(); i++){
        cout<<"{";
        for(auto j = 0; j!=v[i].size(); j++){
            cout<<setw(3)<<v[i][j]<<",";
        }
        cout<<"},";
        if(same_line) cout<<endl;
    }
    cout<<endl;
}

typedef pair<pii, pii> pp;

int main(){
    int n; cin>>n;
    vector<pp> pts(n);
    for(int i=0; i<n; i++){
        cin>>pts[i].first.first>>pts[i].first.second>>pts[i].second.first;
        pts[i].second.second = i+1;
    }

    while(!pts.empty()){
        sort(pts.begin(), pts.end());
        pp pt = pts.back();
        pts.pop_back();

        int x = pt.first.first;
        int y = pt.first.second;
        int z = pt.second.first;
        int pos = pt.second.second;

        ll d = 1e10;
        int ind = 0;

        for(int i=0; i<pts.size(); i++){
            pp p = pts[i];
            ll dist = abs(x - p.first.first);
            dist += abs(y-p.first.second);
            dist += abs(z-p.second.first);

            if(dist<d){
                d = dist;
                ind = i;
            }
        }

        cout<<pos<<" "<<pts[ind].second.second<<endl;
        pts.erase(pts.begin()+ind);

    }
    return 0;
}