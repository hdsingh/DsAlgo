/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (33.42%)
 * Likes:    1729
 * Dislikes: 136
 * Total Accepted:    241.9K
 * Total Submissions: 720.4K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects
 * to. If pos is -1, then there is no cycle in the linked list.
 * 
 * Note: Do not modify the linked list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 * 
 * 
 * 
 * 
 * 
 * 
 * Follow-up:
 * Can you solve it without using extra space?
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
    // Simplified
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        node* F(head); node* S(head);

        while(S){
            if(!S->next) return NULL;
            F = F->next;
            S = S->next->next;
            if(F==S){
                node* p1 = head;
                while(p1!=S){
                    p1 = p1->next;
                    S = S->next;
                }
                return p1;
            }
            
        }
        
        return NULL;     
    }


    ListNode *detectCycle2(ListNode *head) {
        if(!head || !head->next) return NULL;
        node* F(head); node* S(head);
        
        bool is_a_cycle = false;
        while(S){
            if(!S->next) return NULL;
            if(F==S){
                is_a_cycle = true;
                break;
            }
            F = F->next;
            S = S->next->next;
        }
        
        if(!is_a_cycle) return NULL;

        node* p1 = head;
        node* p2 = F;
        // Move both by 1

        while(true){
            if(p1==p2) break;
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;        
    }

    ListNode *detectCycle1(ListNode *head) {
        unordered_set<node*> us;
        node* cur = head;
        while(cur){
            if(us.find(cur)==us.end()){
                us.insert(cur);
                cur = cur->next;
            }
            else break;
        }
        return cur;
    }
};

// https://www.youtube.com/watch?v=-YiQZi3mLq0