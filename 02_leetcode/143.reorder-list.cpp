/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (34.31%)
 * Likes:    1417
 * Dislikes: 98
 * Total Accepted:    199.6K
 * Total Submissions: 579.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *mid = findMid(head);
        ListNode *cur = head;
        // Discoonnect mid from prev
        while(cur->next!=mid){
            cur = cur->next;
        }
        cur->next = NULL;

        ListNode *beg = head;
        ListNode *end = reverseList(mid);

        ListNode *dummy = new ListNode(-1);
        ListNode *out = dummy;

        while(beg){
            out->next = beg;
            beg = beg->next;
            out = out->next;

            out->next = end;
            end = end->next;
            out = out->next;
        }
        head = dummy->next;
    }


    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    };

    ListNode* reverseList(ListNode* head){
    if(!head || !head->next) return head;

    ListNode *end = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return end;	
    }
};
// @lc code=end

int main(){
    Solution sol;
    ListNode *head = createList({1,2,3,4,5});
    sol.reorderList(head); printList(head);
    
    return 0;
}
