/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (38.91%)
 * Likes:    436
 * Dislikes: 490
 * Total Accepted:    164.9K
 * Total Submissions: 423.2K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list using insertion sort.
 * 
 * 
 * 
 * 
 * 
 * A graphical example of insertion sort. The partial sorted list (black)
 * initially contains only the first element in the list.
 * With each iteration one element (red) is removed from the input data and
 * inserted in-place into the sorted list
 * 
 * 
 * 
 * 
 * 
 * Algorithm of Insertion Sort:
 * 
 * 
 * Insertion sort iterates, consuming one input element each repetition, and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list, and inserts it
 * there.
 * It repeats until no input elements remain.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}
template <class T, class U> void print_m(map<T,U> m, int w=3){if(m.empty()){cout<<"Empty"<<endl; return;}for(auto x: m)cout<<"("<<x.first<<": "<<x.second<<"),"<<endl;cout<<endl;}

#include "LinkedList.h"

class Solution0 {
public:
    ListNode* insertionSortList(ListNode* head) {
		if(!head || !head->next) return head; 
        ListNode *cur, *prev, *back, *nx, *dummy, *icur;
		dummy = new ListNode(INT_MIN);
		back = head;
		cur = head->next;
		back->next =  dummy;
		
		while(cur){
			// deb2(cur->val, back->val);
			if(cur->val < back->val){
				icur = back;
				while(icur->next->val > cur->val){
					if(icur->next==dummy)
						break;
					icur = icur->next;
				}
				
				nx = cur->next;
				insertAfter(icur, cur); // after, node
				cur = nx;				
			}else{
				nx = cur->next;
				cur->next = back;
				back = cur;
				cur = nx;
			}
			// printList(back);
		}

		back = reverseList(back);
		// printList(back->next);
		
		return back->next;
    }

	void insertAfter(ListNode* after, ListNode* node){
		if(!after) return;
		ListNode* nx = after->next;
		after->next = node;
		node->next = nx;
	}

	ListNode* reverseList(ListNode *head){
		ListNode *cur, *prev, *nx, *temp;
		prev = NULL;
		cur = head;

		while(cur){
			nx = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nx;
		}
		return prev;		
	}
};

// Ref: https://leetcode.com/problems/insertion-sort-list/discuss/46423/Explained-C%2B%2B-solution-(24ms)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy, *pre, *cur, *temp;
        dummy = new ListNode(0);
        dummy->next = head;
        cur = head; pre = dummy;

        while(cur){
            if(cur->next && cur->next->val < cur->val){
                while(pre->next && pre->next->val < cur->next->val){
                    pre = pre->next;
                }
                temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
                pre = dummy;
            }else{
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

int main(){
	Solution sol; ListNode *head;
	head = createList({2,4,1,3});
	head = createList({5,2});
	head = sol.insertionSortList(head); printList(head);
	return 0;
}
// @lc code=end

