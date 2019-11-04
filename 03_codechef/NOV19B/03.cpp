// https://www.codechef.com/NOV19B/problems/PHCUL
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
const int inf = 1e9;

template <typename T>
void print(T v){
    for(auto i= v.begin(); i!=v.end(); i++)
        cout<<*i<<" ";
    cout<<endl; 
}

#define INF DBL_MAX 

float find_weight(pii a, pii b){
    return sqrt(pow((a.first-b.first), 2) + pow((a.second-b.second), 2));
}

int main(){
    int t,n,m,k,x,y,x1,y1;
    scanf("%d\n", &t);
    while(t--){
        scanf("%d ", &x);
        scanf("%d\n", &y);
        scanf("%d ", &n);
        scanf("%d ", &m);
        scanf("%d\n", &k);
        vi sizes = {1,n,m,k};
        // print(sizes);
        
        // sets of points
        vector<vector<pair<int,int>>> sets(4);
        sets[0].push_back({x,y});      

        for(int sz_num=1; sz_num<sizes.size(); sz_num++){
            for(int i=0; i<sizes[sz_num]; i++){
                scanf("%d ", &x1);
                if(i<n-1)
                    scanf("%d ", &y1);
                else{
                    scanf("%d\n", &y1);
                }
                sets[sz_num].push_back({x1,y1});
            }
            // for(auto p: sets[sz_num])
            //     cout<<p.first<<" "<<p.second<<" ";
            // cout<<endl;
        }

        vector<vector<double>> dist;
        float min_dist = DBL_MAX;

        vi seq1 = {0,1,2,3};
        vi seq2 = {0,2,1,3};
        vvi seqs({seq2, seq1});

        for(auto seq: seqs){

            // dist of ith set, jth point
            dist.clear();
            dist.resize(4);
            
            dist[0].resize(1, 0); // size 1 with dist 0
            for(int size_i=1; size_i<sizes.size(); size_i++){
                dist[size_i].resize(sizes[size_i], INF);
            }

            for(int ilevel=0; ilevel<3; ilevel++){
                for(int p1=0; p1<sizes[seq[ilevel]]; p1++){
                    for(int p2=0; p2<sizes[seq[ilevel+1]]; p2++){
                        float weight = find_weight(sets[seq[ilevel]][p1], sets[seq[ilevel+1]][p2]);
                        if(dist[seq[ilevel]][p1] + weight < dist[seq[ilevel+1]][p2])
                            dist[seq[ilevel+1]][p2] = dist[seq[ilevel]][p1] + weight;
                        
                        // cout<<"l1:"<<seq[ilevel]<<" l2:"<<seq[ilevel+1]<<" p1:"<<p1<<" p2:"<<p2<<endl;
                    }
                    // cout<<endl;
                }
            }

            // for(auto d: dist[3]){
            //     cout<<d<<" ";
            // }
            // cout<<endl;

            float min_in_seq = *min_element(dist[3].begin(), dist[3].end());
            // deb(min_in_seq);
            min_dist = min(min_dist, min_in_seq);
            // min_in_seq = INF;

        }

        printf("%.16f\n", min_dist);


    }

    return 0;
}

// Optimized version of https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/
