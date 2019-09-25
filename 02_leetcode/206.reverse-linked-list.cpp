/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (56.75%)
 * Likes:    2840
 * Dislikes: 69
 * Total Accepted:    690K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        node* reversedListHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return reversedListHead;
    }

    ListNode* reverseList3(ListNode* head) {
        node* prev = NULL;
        node* cur = head;
        while(cur){
            node* temp = cur->next; //save
            cur->next = prev; // reverse ptr
            prev = cur; // save to be used in next iteration
            cur = temp; //utilise saved to mob=ve forward
        }
        return prev;
    }

    ListNode* reverseList2(ListNode* head) {
        node* nh = NULL; //new _head
        node* cur = head;

        while(cur){
            node* temp = new ListNode(cur->val);
            temp->next = nh;
            nh = temp;
            cur = cur->next;
        }    

        return nh;

    }
    // Using Stack
    ListNode* reverseList1(ListNode* head) {
        if(!head) return NULL;
        stack<node*> s;
        node* cur = head;
        while(cur){
            s.push(cur);
            cur = cur->next;
        }
        head = s.top(); s.pop();
        cur = head;
        while(!s.empty()){
            cur->next = s.top(); s.pop();
            cur = cur->next;
        }
        cur->next = NULL;
        return head;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        ListNode* ret = Solution().reverseList(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}

