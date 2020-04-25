/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (37.09%)
 * Likes:    1218
 * Dislikes: 71
 * Total Accepted:    286.1K
 * Total Submissions: 770.6K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
#include "LinkedList.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int x) {
        if(!head) return head;
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* prev = dummyHead;
        ListNode* cur = head;

        while(cur){
            if(cur->val==x)
                prev->next = cur->next;
            else
                prev = cur;
            
            cur = cur->next;
        }
        return dummyHead->next;
    }
};
// @lc code=end

int main(){
    Solution sol; 
    ListNode* head = createList({1,2,6,3,4,5,6});
    head = sol.removeElements(head, 6); printList(head);
    head = createList({1,1,1,6,3,4,1,1,3,5}); 
    head = createList({}); 
    head = sol.removeElements(head, 1); printList(head);
    return 0;
}
