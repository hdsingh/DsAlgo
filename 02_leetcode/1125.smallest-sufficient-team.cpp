/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 *
 * https://leetcode.com/problems/smallest-sufficient-team/description/
 *
 * algorithms
 * Hard (45.51%)
 * Likes:    221
 * Dislikes: 7
 * Total Accepted:    5.6K
 * Total Submissions: 12.2K
 * Testcase Example:  '["java","nodejs","reactjs"]\n[["java"],["nodejs"],["nodejs","reactjs"]]'
 *
 * In a project, you have a list of required skills req_skills, and a list of
 * people.  The i-th person people[i] contains a list of skills that person
 * has.
 * 
 * Consider a sufficient team: a set of people such that for every required
 * skill in req_skills, there is at least one person in the team who has that
 * skill.  We can represent these teams by the index of each person: for
 * example, team = [0, 1, 3] represents the people with skills people[0],
 * people[1], and people[3].
 * 
 * Return any sufficient team of the smallest possible size, represented by the
 * index of each person.
 * 
 * You may return the answer in any order.  It is guaranteed an answer
 * exists.
 * 
 * 
 * Example 1:
 * Input: req_skills = ["java","nodejs","reactjs"], people =
 * [["java"],["nodejs"],["nodejs","reactjs"]]
 * Output: [0,2]
 * Example 2:
 * Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"],
 * people =
 * [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
 * Output: [1,2]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= req_skills.length <= 16
 * 1 <= people.length <= 60
 * 1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
 * Elements of req_skills and people[i] are (respectively) distinct.
 * req_skills[i][j], people[i][j][k] are lowercase English letters.
 * Every skill in people[i] is a skill in req_skills.
 * It is guaranteed a sufficient team exists.
 * 
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
template <typename T>void print_vv(T v){int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}


// referenced
// Try forming all combinations of people and check which comb has minimum people
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<string, int> skill_map;
        for(int i=0; i<n; i++)
            skill_map[req_skills[i]] = i;
        
        unordered_map<int, vi> res;
        // mask of skills, with minimum people needed for the set of skills
        res.reserve(1<<n);

        res[0] = {};
        for(int i=0; i<people.size(); i++){
            int mask = 0;
            for(auto skill: people[i])
                mask|= (1<<(skill_map[skill]));
            
            for(auto it=res.begin(); it!=res.end(); it++){
                int comb = mask | it->first;
                if(res.find(comb)==res.end() || res[comb].size() > 1+it->second.size()){
                    res[comb] = it->second;
                    res[comb].pb(i);
                }
            }
        }

        return res[(1<<n) -1];
    }
};
// @lc code=end


int main(){
    Solution sol; vi out; vs req_skills; vector<vs> people;
    req_skills = {"java","nodejs","reactjs"}, people = {{"java"},{"nodejs"},{"nodejs","reactjs"}};
    out = sol.smallestSufficientTeam(req_skills, people); print(out);

    req_skills = {"algorithms","math","java","reactjs","csharp","aws"}, people = {{"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}};
    out = sol.smallestSufficientTeam(req_skills, people); print(out);

    return 0;
}
