/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (52.05%)
 * Likes:    1229
 * Dislikes: 268
 * Total Accepted:    200.2K
 * Total Submissions: 383.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 * 
 * 
 * Note:
 * 
 * 
 * The relative order inside both the even and odd groups should remain as it
 * was in the input.
 * The first node is considered odd, the second node even and so on ...
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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *odd(head), *even(head->next), *evenHead(even);

        // while(even && even->next){
        //     odd->next = even->next;
        //     odd = odd->next;
        //     even->next = odd->next;
        //     even = even->next;
        // }

        // or more simply
        while(even && even->next){
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        
        odd->next = evenHead;
        return head;
    }
};

// @lc code=end
int main(){
    Solution sol;
    ListNode *l1 = createList({1,2,3,4,5});
    l1 = sol.oddEvenList(l1); printList(l1);

    l1 = createList({2,1,3,5,6,4,7});
    l1 = sol.oddEvenList(l1); printList(l1);

    return 0;
}
