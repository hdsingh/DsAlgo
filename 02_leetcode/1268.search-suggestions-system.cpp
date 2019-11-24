/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 *
 * https://leetcode.com/problems/search-suggestions-system/description/
 *
 * algorithms
 * Medium (43.60%)
 * Likes:    23
 * Dislikes: 23
 * Total Accepted:    2.7K
 * Total Submissions: 6.3K
 * Testcase Example:  '["mobile","mouse","moneypot","monitor","mousepad"]\r\n"mouse"\r'
 *
 * Given an array of strings products and a string searchWord. We want to
 * design a system that suggests at most three product names from products
 * after each character of searchWord is typed. Suggested products should have
 * common prefix with the searchWord. If there are more than three products
 * with a common prefix return the three lexicographically minimums products.
 * 
 * Return list of lists of the suggested products after each character of
 * searchWord is typed. 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: products = ["mobile","mouse","moneypot","monitor","mousepad"],
 * searchWord = "mouse"
 * Output: [
 * ["mobile","moneypot","monitor"],
 * ["mobile","moneypot","monitor"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"]
 * ]
 * Explanation: products sorted lexicographically =
 * ["mobile","moneypot","monitor","mouse","mousepad"]
 * After typing m and mo all products match and we show user
 * ["mobile","moneypot","monitor"]
 * After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: products = ["havana"], searchWord = "havana"
 * Output:
 * [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: products = ["bags","baggage","banner","box","cloths"], searchWord =
 * "bags"
 * Output:
 * [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: products = ["havana"], searchWord = "tatiana"
 * Output: [[],[],[],[],[],[],[]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= products.length <= 1000
 * 1 <= Σ products[i].length <= 2 * 10^4
 * All characters of products[i] are lower-case English letters.
 * 1 <= searchWord.length <= 1000
 * All characters of searchWord are lower-case English letters.
 * 
 * 
 */
#include "cpp.h"
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vector<int>> vvi;

// @lc code=start
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
// @lc code=end


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

