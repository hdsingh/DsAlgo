/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (36.99%)
 * Likes:    1974
 * Dislikes: 284
 * Total Accepted:    301.5K
 * Total Submissions: 813.2K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        node* first = head;
        node* sec = head;

        while(sec->next && sec->next->next){
            first = first->next;
            sec = sec->next->next;
        }

        first->next = revList(first->next);
        first = first->next;

        while(first){
            if(head->val!=first->val)
                return false;
            head = head->next;
            first = first->next;
        }

        return true;
    }

    node* revList(node* head){
        node* pre = NULL;
        node* next = NULL;

        while(head){
            next =  head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    // by reversing a list
    bool isPalindrome2(ListNode* head) {
        if(!head) return true;
        node* rev_head = NULL;
        node* cur = head;
        while(cur){
            node* temp = new node(cur->val);
            temp->next = rev_head;
            rev_head = temp;
            cur = cur->next;
        }
        
        while(head){
            if(head->val!=rev_head->val) return false;
            head = head->next;
            rev_head = rev_head->next;
        }

        return true;
    }

    // using deque
    bool isPalindrome1(ListNode* head) {
        if(!head) return true;
        deque<node*> dq;
        node* cur = head;
        while(cur){
            dq.push_back(cur);
            cur = cur->next;
        }
        while(dq.size()>1){
            node* l = dq.front(); dq.pop_front();
            node* r = dq.back(); dq.pop_back();
            if(l->val!=r->val) return false;
        }
        return true;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        
        bool ret = Solution().isPalindrome(head);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}

