/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (38.21%)
 * Likes:    1913
 * Dislikes: 98
 * Total Accepted:    218.3K
 * Total Submissions: 570.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 * 
 */
#include "cpp.h"
using namespace std;

// @lc code=start
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    // eqivalet to merge procedure
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        // Divide
        ListNode *slow(head), *fast(head);
        //
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        
        return  merge(sortList(head), sortList(fast));
    }
    
    //merge two sorted lists
    ListNode* merge(ListNode* left, ListNode* right){
        if(!left && !right) return left;
        
        if(!left) return right;
        if(!right) return left;
        
        ListNode* sortedList = new ListNode(0);
        ListNode* cur = sortedList;
        
        while(left && right){
            if(left->val <= right->val){
                cur->next = left;
                left = left->next;
            }else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        

        cur->next = left ? left : right;
        
        return sortedList->next;
    }
};
// @lc code=end

