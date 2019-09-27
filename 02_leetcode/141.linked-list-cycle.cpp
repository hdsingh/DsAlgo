/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (38.09%)
 * Likes:    1815
 * Dislikes: 232
 * Total Accepted:    462.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, determine if it has a cycle in it.
 * 
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects
 * to. If pos is -1, then there is no cycle in the linked list.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * Can you solve it using O(1) (i.e. constant) memory?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "cpp.h"
#include "node.h"
#include "extra.h"
using namespace std;
typedef ListNode node;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;

        node* first = head; // will move 1 node
        node* second = head->next->next; // will move 2 nodes

        while(first){
            if(first==second) return true;
            if(!second || !second->next) return false;
                first = first->next;
                second = second->next->next;
        }
        return false;
    }

    bool hasCycle1(ListNode *head) {
        if(!head) return false;
        if(!head->next) return false;
        if(!head->next->next) return false;

        node* first = head; // will move 1 node
        node* second = head->next->next; // will move 2 nodes

        while(first){
            if(first==second) return true;
            if(first->next) 
                first = first->next;
            else return false;
            if(second->next){
                if(second->next->next)
                    second = second->next->next;
                else
                    return false;
            }else return false;
        }
        return false;
    }
};
