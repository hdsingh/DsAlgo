/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (35.28%)
 * Likes:    1283
 * Dislikes: 98
 * Total Accepted:    224.7K
 * Total Submissions: 636K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Return the linked list sorted as well.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
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
#define pb push_back
#define deb(x) cout<<#x<<" "<<x<<endl;
#define deb2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define deb3(x, y, z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#include "LinkedList.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* prev = dummyHead;
        ListNode* cur = dummyHead->next;

        while(cur && cur->next){
            int x = cur->val;
            if(cur->next->val==x){
                while(cur && cur->val==x){
                    prev->next = cur->next;
                    cur = cur->next;
                }
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};
// @lc code=end

int main(){
    Solution sol;
    ListNode* head = createList({1,2,3,3,4,4,5});
    head = sol.deleteDuplicates(head); printList(head);
    head = createList({});
    head = sol.deleteDuplicates(head); printList(head);
    return 0;
}

