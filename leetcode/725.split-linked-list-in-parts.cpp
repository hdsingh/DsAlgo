/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 *
 * https://leetcode.com/problems/split-linked-list-in-parts/description/
 *
 * algorithms
 * Medium (50.78%)
 * Likes:    508
 * Dislikes: 102
 * Total Accepted:    40.2K
 * Total Submissions: 79.1K
 * Testcase Example:  '[1,2,3,4]\n5'
 *
 * Given a (singly) linked list with head node root, write a function to split
 * the linked list into k consecutive linked list "parts".
 * 
 * The length of each part should be as equal as possible: no two parts should
 * have a size differing by more than 1.  This may lead to some parts being
 * null.
 * 
 * The parts should be in order of occurrence in the input list, and parts
 * occurring earlier should always have a size greater than or equal parts
 * occurring later.
 * 
 * Return a List of ListNode's representing the linked list parts that are
 * formed.
 * 
 * 
 * Examples
 * 1->2->3->4, k = 5 // 5 equal parts
 * [ [1], 
 * [2],
 * [3],
 * [4],
 * null ]
 * 
 * Example 1:
 * 
 * Input: 
 * root = [1, 2, 3], k = 5
 * Output: [[1],[2],[3],[],[]]
 * Explanation:
 * The input and each element of the output are ListNodes, not arrays.
 * For example, the input root has root.val = 1, root.next.val = 2,
 * \root.next.next.val = 3, and root.next.next.next = null.
 * The first element output[0] has output[0].val = 1, output[0].next = null.
 * The last element output[4] is null, but it's string representation as a
 * ListNode is [].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
 * Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
 * Explanation:
 * The input has been split into consecutive parts with size difference at most
 * 1, and earlier parts are a larger size than the later parts.
 * 
 * 
 * 
 * Note:
 * The length of root will be in the range [0, 1000].
 * Each value of a node in the input will be an integer in the range [0, 999].
 * k will be an integer in the range [1, 50].
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> out;
        int len = 0;
        ListNode *cur= root;
        while(cur){
            ++len;
            cur = cur->next;
        }
        int cnt = len/k;
        int mod = len%k;

        cur = root;
        while(k--){
            ListNode* head = new ListNode(-1);
            ListNode* innerCur = head;
            if(!cur){
                out.push_back(head->next);
                continue;
            }
            int extra = mod ? 1 : 0;
            if(mod) --mod;

            for(int i=0; i<cnt + extra; ++i){

                innerCur->next = cur;
                innerCur = innerCur->next;
                cur = cur->next;
            }
            innerCur->next = NULL;
            out.push_back(head->next);
        }

        return out;
    }
};
// @lc code=end

int main(){
    Solution sol; ListNode* root; int k; vector<ListNode*> out;
    root = createList({1,2,3});
    out = sol.splitListToParts(root, 5);
    for(auto node: out){
        printList(node);
    }

    root = createList({1, });
    out = sol.splitListToParts(root, 3);
    for(auto node: out){
        printList(node);
    }
    deb(out.size());

    return 0;
}
