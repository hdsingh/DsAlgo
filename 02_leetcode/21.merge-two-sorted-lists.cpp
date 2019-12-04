/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (48.81%)
 * Likes:    2665
 * Dislikes: 386
 * Total Accepted:    690K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        node* dummy = new node(INT_MIN);
        node* l3 = dummy;

        while(l1 && l2){
            if(l1->val<l2->val){
                l3->next = l1;
                l1 = l1->next;
            }else
            {
                l3->next=l2;
                l2 = l2->next;

            }
            l3 = l3->next;
        }

        l3->next = l1? l1:l2;
                
        return dummy->next;
    }

    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        node* l3;
        if(l1->val<l2->val){
            l3 = l1;
            l1 = l1->next;
        }else
        {
            l3 = l2;
            l2 = l2->next;
        }
        node* cur = l3;

        while(l1 && l2){
            if(l1->val<l2->val){
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }else
            {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;

            }
        }

        while(l1){
            cur->next = l1;
            cur = l1;
            l1 = l1->next;
        }
        
        while(l2){
            cur->next = l2;
            cur = l2;
            l2 = l2->next;
        }
        
        return l3;
    }
};

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* out = new ListNode(0);
        ListNode *cur = out;
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        while(l1){
            cur->next = new ListNode(l1->val);
            l1 = l1->next;
            cur = cur->next;
        }
        
        while(l2){
            cur->next = new ListNode(l2->val);
            l2 = l2->next;
            cur = cur->next;
            
        }
        
        return out->next;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().mergeTwoLists(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
