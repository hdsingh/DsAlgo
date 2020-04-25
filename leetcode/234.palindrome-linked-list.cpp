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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#include "LinkedList.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if(!head) return head;
        ListNode* mid = findMid(head);
		ListNode* end = reverseList(mid);

		while(end){
			if(head->val!=end->val)
				return false;
			head = head->next;
			end = end->next;
		}
		return true;
    }

	ListNode* findMid(ListNode* head){
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast && fast->next){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	};

	ListNode* reverseList(ListNode* head){
		if(!head || !head->next) return head;

		ListNode *end = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;

		return end;	
	}
};

int main(){
	ListNode *l1 = createList({1,2,1}); 
	Solution sol; bool out;
	out = sol.isPalindrome(l1); deb(out);
	l1 = createList({1});
    out = sol.isPalindrome(l1); deb(out);
	return 0;
}