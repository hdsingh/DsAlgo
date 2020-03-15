/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 *
 * https://leetcode.com/problems/accounts-merge/description/
 *
 * algorithms
 * Medium (45.72%)
 * Likes:    1044
 * Dislikes: 254
 * Total Accepted:    61.2K
 * Total Submissions: 133.8K
 * Testcase Example:  '[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]'
 *
 * Given a list accounts, each element accounts[i] is a list of strings, where
 * the first element accounts[i][0] is a name, and the rest of the elements are
 * emails representing emails of the account.
 * 
 * Now, we would like to merge these accounts.  Two accounts definitely belong
 * to the same person if there is some email that is common to both accounts.
 * Note that even if two accounts have the same name, they may belong to
 * different people as people could have the same name.  A person can have any
 * number of accounts initially, but all of their accounts definitely have the
 * same name.
 * 
 * After merging the accounts, return the accounts in the following format: the
 * first element of each account is the name, and the rest of the elements are
 * emails in sorted order.  The accounts themselves can be returned in any
 * order.
 * 
 * Example 1:
 * 
 * Input: 
 * accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John",
 * "johnnybravo@mail.com"], ["John", "johnsmith@mail.com",
 * "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
 * Output: [["John", 'john00@mail.com', 'john_newyork@mail.com',
 * 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary",
 * "mary@mail.com"]]
 * Explanation: 
 * The first and third John's are the same person as they have the common email
 * "johnsmith@mail.com".
 * The second John and Mary are different people as none of their email
 * addresses are used by other accounts.
 * We could return these lists in any order, for example the answer [['Mary',
 * 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
 * ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
 * would still be accepted.
 * 
 * 
 * 
 * Note:
 * The length of accounts will be in the range [1, 1000].
 * The length of accounts[i] will be in the range [1, 10].
 * The length of accounts[i][j] will be in the range [1, 30].
 * 
 */

// @lc code=start
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
template <class T, class U> void print_m(unordered_map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

// Could be optimised further
class Solution {
    unordered_map<string, string> par;
    unordered_map<string, int> rank;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        par.clear();
        unordered_map<string, string> owner; // mail to name

        // make set
        for(auto acc: accounts){
            string name = acc[0];
            for(int i=1; i<(int)acc.size(); ++i){
                par[acc[i]] = acc[i];
                owner[acc[i]] = name;
            }
        }

        for(auto acc: accounts){
            string mail1 = acc[1];
            for(int i=2; i<(int)acc.size(); ++i){
                unite(mail1, acc[i]);
            }
        }

        // print_m(par);

        map<string, set<string>> united; // par_email, children_emails
        for(auto acc: accounts){
            for(int i=1; i<(int)acc.size(); ++i){
                united[find_par(acc[i])].insert(acc[i]);
            }
        }

        // for(auto p: united){
        //     cout<<p.first<<" ";
        //     print(p.second);
        // }

        vector<vector<string>> out;
        for(auto &p: united){
            string name = owner[p.first];
            vector<string> cur;
            cur.push_back(name);
            for(auto &mail: p.second)
                cur.push_back(mail);
            out.push_back(cur);
        }

        return out;
    }

    void unite(string &mail1, string &mail2){
        mail1 = find_par(mail1);
        mail2 = find_par(mail2);
        if(mail1 != mail2){
            if(rank[mail1]<rank[mail2])
                swap(mail1, mail2);

            if(rank[mail1]==rank[mail2])
                ++rank[mail1];
    
            par[mail2] = mail1; 
        }
    }

    string find_par(string mail){
        if(mail==par[mail]) return mail;
        return par[mail] = find_par(par[mail]);
    }
};

// @lc code=end

int main(){
    Solution sol; vector<vs> accounts;
    accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, 
                {"John", "johnnybravo@mail.com"}, 
                {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, 
                {"Mary", "mary@mail.com"}};
    accounts = sol.accountsMerge(accounts); 
    print_vv(accounts);

    accounts = {{"David","David0@m.co","David1@m.co"},
                {"David","David3@m.co","David4@m.co"},
                {"David","David4@m.co","David5@m.co"},
                {"David","David2@m.co","David3@m.co"},
                {"David","David1@m.co","David2@m.co"}};
    accounts = sol.accountsMerge(accounts); 
    print_vv(accounts);

    accounts = {{"Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"},
                {"Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"},
                {"Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"},
                {"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"},
                {"Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"}};
    accounts = sol.accountsMerge(accounts); 
    print_vv(accounts);
    
    accounts = {{"x","1","2"},
                {"x","2","3"}};
    accounts = sol.accountsMerge(accounts); 
    print_vv(accounts);
    return 0;
}
