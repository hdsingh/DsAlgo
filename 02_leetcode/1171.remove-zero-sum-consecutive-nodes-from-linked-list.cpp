/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
 *
 * https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
 *
 * algorithms
 * Medium (41.69%)
 * Likes:    306
 * Dislikes: 25
 * Total Accepted:    11K
 * Total Submissions: 26.4K
 * Testcase Example:  '[1,2,-3,3,1]'
 *
 * Given the head of a linked list, we repeatedly delete consecutive sequences
 * of nodes that sum to 0 until there are no such sequences.
 * 
 * After doing so, return the head of the final linked list.  You may return
 * any such answer.
 * 
 * 
 * (Note that in the examples below, all sequences are serializations of
 * ListNode objects.)
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,-3,3,1]
 * Output: [3,1]
 * Note: The answer [1,2,1] would also be accepted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,-3,4]
 * Output: [1,2,4]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2,3,-3,-2]
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The given linked list will contain between 1 and 1000 nodes.
 * Each node in the linked list has -1000 <= node.val <= 1000.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

#include "LinkedList.h"

// Similar to using difcnt, and deleting intermediate node bw 
// two matching sums;
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        map<int, ListNode*> m;
        ListNode *cur = dummy;
        int sum = 0;
        while(cur){
            sum += cur->val;
            // delete all values from [ m[sum]->next to cur ];
            // then m[sum]->next = cur->next
            if(m.count(sum)){
                cur = m[sum]->next;
                int isum = sum + cur->val;
                while(isum!=sum){
                    m.erase(isum);
                    cur = cur->next;
                    isum += cur->val;
                }
                m[sum]->next = cur->next;
            }else 
                m[sum] = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};

// @lc code=end

int main(){
    Solution sol; ListNode *head;
    head = createList({5,-3,-4,1,6, -2, -5});
    head = sol.removeZeroSumSublists(head); printList(head);
    head = createList({1,2,-3,3,1});
    head = sol.removeZeroSumSublists(head); printList(head);
    head = createList({1,3,2,-3,-2,5,5,-5,1});
    head = sol.removeZeroSumSublists(head); printList(head);

    head = createList({0,0});
    head = sol.removeZeroSumSublists(head); printList(head);
    return 0;
}
