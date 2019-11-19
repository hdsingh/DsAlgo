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

int main(){
    int n;
    scanf("%d\n", &n);

    vi arr(n);
    for(int i=0; i<n; i++){
        scanf("%d ", &arr[i]);
    }

    unordered_set<int> days;
    unordered_map<int, int> count;
    vi events;
    int e=0;
    bool is_break = false;

    for(int i = 0; i<n; i++){
        int x = arr[i];
        

        if(x>0){
            auto found = days.find(x);
            if(found!=days.end()){ //found
                {printf("%d\n", -1); is_break=true; break;}
            }else{ //!found
                if(count[x]){printf("%d\n", -1);is_break=true; break;}
                else count[x]++;

                days.insert(x);
                e++;
            }
        }else{//x<0
            auto found = days.find(-1*x);
            if(found!=days.end()){ //found
                days.erase(-1*x);
                e++;
            }else{ //!found
                {printf("%d\n", -1);is_break=true; break;}
            }
        }

        if(days.empty()){
            count.clear();
            events.push_back(e);
            e=0;
        }

    }

    if(!is_break && !days.empty()){
        printf("%d\n", -1);

    }

    if(!is_break && days.empty()){
        printf("%d\n", (int)events.size());
        for(auto e: events){
            printf("%d ", e);
        }
    }

    

    return 0;
}