/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (52.75%)
 * Likes:    1096
 * Dislikes: 139
 * Total Accepted:    131.6K
 * Total Submissions: 249K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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

// Use Stack to deserilaze the lists
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1, stk2;
        ListNode* cur = l1;
        while(cur){
            stk1.push(cur->val);
            cur = cur->next;
        }
        cur = l2;
        while(cur){
            stk2.push(cur->val);
            cur = cur->next;
        }

        ListNode *dummy = new ListNode(-1);
        int carry = 0;
        while(carry || stk1.size() || stk2.size()){
            int a = stk1.size() ? stk1.top() : 0;
            int b = stk2.size() ? stk2.top() : 0;
            int c = a+b+carry;
            carry = c/10;
            c%=10;

            ListNode* x = new ListNode(c);
            if(!dummy->next){
                dummy->next = x;
            }else{
                x->next = dummy->next;
                dummy->next = x;
            }

            if(stk1.size()) stk1.pop();
            if(stk2.size()) stk2.pop();
        } 
        return dummy->next;
    }
};
// @lc code=end

int main(){
    Solution sol; ListNode *out, *l1, *l2;
    l1 = createList({7,2,4,3});
    l2 = createList({5,6,4});
    out = sol.addTwoNumbers(l1, l2); printList(out);
    return 0;
}