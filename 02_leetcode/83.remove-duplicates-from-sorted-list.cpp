/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (44.29%)
 * Likes:    1171
 * Dislikes: 95
 * Total Accepted:    414K
 * Total Submissions: 933.7K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
typedef vector<int> vi;

#include "LinkedList.h"

class Solution0 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode*prev = head;
        ListNode* cur = head->next;

        while(cur){
            if(cur->val==prev->val){
                ListNode* nx = cur->next;
                prev->next = cur->next;
                cur = cur->next;
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur && cur->next){
            if(cur->val==cur->next->val){
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end

int main(){
    Solution sol;
    ListNode *head = createList({1,1,1,1,32,2});
    head = sol.deleteDuplicates(head); printList(head); 
    return 0;
}
