/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (48.25%)
 * Likes:    1783
 * Dislikes: 152
 * Total Accepted:    413.8K
 * Total Submissions: 855.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
#define deb(x) cout<<#x<<" "<<x<<endl;
typedef vector<int> vi;
#include "LinkedList.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = head;
        ListNode* prev = dummy;

        while(cur && cur->next){
            ListNode* nx = cur->next->next;
            prev->next = cur->next;
            cur->next->next = cur;
            cur->next = nx;
            prev = cur;
            cur = cur->next;
        }

        return dummy->next;
    }
};
// @lc code=end

int main(){
    Solution sol; ListNode* head;
    head = createList({1,2,3,4,5,6,7,8});
    head = sol.swapPairs(head); printList(head);
    return 0;
}
