/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (35.98%)
 * Likes:    1476
 * Dislikes: 104
 * Total Accepted:    215.9K
 * Total Submissions: 598.3K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) return NULL;
        node* dummy = new node(INT_MIN);
        dummy->next = head;
        node* prev = dummy;
        node* cur = dummy->next;
        int c = 1; //count

        while(c<m){
            prev = cur;
            cur = cur->next;
            c++;
        }
        node* prev_first = prev;

        // Reverse
        while(c<=n){
            node* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            c++;
        }

        node* temp = prev_first->next;
        prev_first->next = prev;
        temp->next = cur;

        return dummy->next;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        ListNode* ret = Solution().reverseBetween(head, m, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
