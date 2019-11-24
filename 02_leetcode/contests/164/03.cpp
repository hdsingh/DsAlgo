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
    for(auto i= v.begin(); i!=v.end(); i++){
        string t = *i;
        cout<<t<<" ";
    }
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


class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		int sw_size = searchWord.size();
        int n = products.size();
        int loc = 0;
        sort(products.begin(), products.end());
        vector<vector<string>> out(sw_size);
        for(int i=0; i<sw_size; i++){
            string s = searchWord.substr(0, i+1);
            bool first_match = true;

            for(int j=loc; j<n; j++){
                if(out[i].size()>=3) break;

                if(products[j].substr(0, i+1)==s){
                    if(first_match){
                         loc = j;
                         first_match = false;
                    }
                    out[i].push_back(products[j]);
                }
            }
        }
        return out;
	}
};

class Solution2 {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		int sl = searchWord.length(), i, j, k;
		sort(products.begin(), products.end());
		vector<vector<string>> ans(sl);
		for (i = 0; i < sl; i++) {
			string s = searchWord.substr(0, i + 1);
			for (auto p : products) {
				if (ans[i].size() >= 3) break;
				if (p.substr(0, i + 1) == s) ans[i].push_back(p);
			}
		}
		return ans;
	}
};

class Solution1 {
public:
    vector<vector<string>> suggestedProducts(vector<string>products, string searchWord) {
        int n = products.size();
        sort(products.begin(), products.end());
        // print(products);

        int ws = searchWord.size();
        vector<vector<string>> out(ws);
        int loc = 0; //represents the loc from where I should start looking for similar words
        
        for(int i=0; i<ws; i++){
            char c = searchWord[i];

            // find loc
            bool found = false;
            for(int j=loc; j<n; j++){
                if(products[j].size()>i)
                    if(products[j][i]==c){
                        loc = j;
                        found = true;
                        break;
                    }
            }
            if(!found) break;

            int count = 0;
            int pos = loc;
            while(count<3 && pos<n){
                if(products[pos].size()>i){
                    if(products[pos][i]==c){
                        out[i].push_back(products[pos]);
                        count++;
                        }
                    else break;
                }
                pos++;
            }
        }
        
        return out;
    }
};

int main(){
    Solution sol;
    vs test; string s; vector<vector<string>> out;

    test = {"mobile","mouse","moneypot","monitor","mousepad"};
    s = "mouse";
    out = sol.suggestedProducts(test, s);
    print_vv(out);

    test = {"havana"};
    s = "havana";
    out = sol.suggestedProducts(test, s);
    print_vv(out);


    test = {"havana"};
    s = "tivana";
    out = sol.suggestedProducts(test, s);
    print_vv(out);


    test = {"bags","baggage","banner","box","cloths"};
    s = "bags";
    out = sol.suggestedProducts(test, s);
    print_vv(out);



    return 0;
}