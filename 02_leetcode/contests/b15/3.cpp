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


class CombinationIterator {
    int pos = 0;
    vector<string> out;
    int sz = 0;
public:
    CombinationIterator(string cs, int l) {
        out.clear();
        pos = 0;

        int n = cs.size();
        string sub;
        makeCombs(0, l, cs, sub, out);

        sort(out.begin(), out.end());  
        sz = out.size();     
    }

    void makeCombs(int start, int l, string &cs, string sub, vector<string> &out){
        int n = cs.size();
        
        if(sub.size()==l){
            out.push_back(sub);
            return;
        }

        for(int i=start; i<n; i++){
            sub.push_back(cs[i]);
            makeCombs(i+1, l, cs, sub, out);
            sub.pop_back();
        }
    }
    
    string next() {
        return out[pos++];
    }
    
    bool hasNext() {
        return (pos<sz);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(){
    string characters = "abcdef";
    int combinationLength = 1; 
    CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
    // 
    string param_1 = obj->next();
    deb(param_1);
    param_1 = obj->next();
    deb(param_1);param_1 = obj->next();
    deb(param_1);param_1 = obj->next();
    deb(param_1);param_1 = obj->next();
    deb(param_1);param_1 = obj->next();
    deb(param_1);param_1 = obj->next();
    deb(param_1);param_1 = obj->next();
    deb(param_1);
    bool param_2 = obj->hasNext(); 
    deb(param_2);
     param_2 = obj->hasNext(); 
    deb(param_2); param_2 = obj->hasNext(); 
    deb(param_2); param_2 = obj->hasNext(); 
    deb(param_2); param_2 = obj->hasNext(); 
deb(param_2); param_2 = obj->hasNext(); 
    deb(param_2); param_2 = obj->hasNext(); 
    deb(param_2); param_2 = obj->hasNext(); 
    deb(param_2); param_2 = obj->hasNext(); 
    deb(param_2); param_2 = obj->hasNext(); 
    deb(param_2); param_2 = obj->hasNext(); 
    deb(param_2); param_2 = obj->hasNext(); 
    deb(param_2); param_2 = obj->hasNext(); 
    deb(param_2);

    return 0;
    // vs a = {"abd", "ghi"};
    // print_vv(a);

}