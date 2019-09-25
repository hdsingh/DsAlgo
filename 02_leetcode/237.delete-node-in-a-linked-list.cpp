/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 *
 * https://leetcode.com/problems/delete-node-in-a-linked-list/description/
 *
 * algorithms
 * Easy (55.45%)
 * Likes:    891
 * Dislikes: 4318
 * Total Accepted:    317.3K
 * Total Submissions: 569.9K
 * Testcase Example:  '[4,5,1,9]\n5'
 *
 * Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node.
 * 
 * Given linked list -- head = [4,5,1,9], which looks like following:
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [4,5,1,9], node = 5
 * Output: [4,1,9]
 * Explanation: You are given the second node with value 5, the linked list
 * should become 4 -> 1 -> 9 after calling your function.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [4,5,1,9], node = 1
 * Output: [4,5,9]
 * Explanation: You are given the third node with value 1, the linked list
 * should become 4 -> 5 -> 9 after calling your function.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The linked list will have at least two elements.
 * All of the nodes' values will be unique.
 * The given node will not be the tail and it will always be a valid node of
 * the linked list.
 * Do not return anything from your function.
 * 
 * 
 */

//  Definition for singly-linked list.
#include "cpp.h"
#include "node.h"
using namespace std;

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* cur = node;
        ListNode* prev = NULL;
        
        while(cur->next){
            cur->val = cur->next->val;
            prev = cur;
            cur = cur->next;
        }
        prev->next =  NULL;
    }
};

// Since the node provided is itself to be deleted, we will 
// swap the values of the nodes.
