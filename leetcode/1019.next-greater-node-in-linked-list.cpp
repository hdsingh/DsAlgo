/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 *
 * https://leetcode.com/problems/next-greater-node-in-linked-list/description/
 *
 * algorithms
 * Medium (56.71%)
 * Likes:    494
 * Dislikes: 32
 * Total Accepted:    30.4K
 * Total Submissions: 53.6K
 * Testcase Example:  '[2,1,5]'
 *
 * We are given a linked list with head as the first node.  Let's number the
 * nodes in the list: node_1, node_2, node_3, ... etc.
 * 
 * Each node may have a next larger value: for node_i, next_larger(node_i) is
 * the node_j.val such that j > i, node_j.val > node_i.val, and j is the
 * smallest possible choice.  If such a j does not exist, the next larger value
 * is 0.
 * 
 * Return an array of integers answer, where answer[i] =
 * next_larger(node_{i+1}).
 * 
 * Note that in the example inputs (not outputs) below, arrays such as [2,1,5]
 * represent the serialization of a linked list with a head node value of 2,
 * second node value of 1, and third node value of 5.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [2,1,5]
 * Output: [5,5,0]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [2,7,4,3,5]
 * Output: [7,0,5,5,0]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,7,5,1,9,2,5,1]
 * Output: [7,9,9,9,0,5,0,0]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= node.val <= 10^9 for each node in the linked list.
 * The given list has length in the range [0, 10000].
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<" "<<x<<endl;
typedef vector<int> vi;
template <typename T>void print(T v, bool show_index = false){int w = 2;if(show_index){for(int i=0; i<v.size(); i++)cout<<setw(w)<<i<<" ";cout<<endl;}for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(w)<<*i<<" ";cout<<endl;}
template <typename T>void print_vv(T v){if(v.size()==0) {cout<<"Empty"<<endl; return;} int w = 3;cout<<setw(w)<<" ";for(int j=0; j<v[0].size(); j++)cout<<setw(w)<<j<<" ";cout<<endl;for(auto i= 0; i<v.size(); i++){cout<<i<<" {";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(w)<<v[i][j]<<",";}cout<<"},"<<endl;}cout<<endl;}

#include "LinkedList.h"

// Using montonic property of stack
// Reversing list inplace
class Solution0 {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head) return {};
        if(!head->next) return {0};
        head = reverseList(head);
        // use head as cur
        vi out;
        stack<int> stk;
        while(head){
            while(stk.size() && stk.top()<=head->val)
                stk.pop();
            int x = stk.size() ? stk.top() : 0;
            out.push_back(x);
            stk.push(head->val);
            head = head->next;
        }
        reverse(out.begin(), out.end());
        return out;
    }

    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* end = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return end;
    }
};

// using res array to store elements of list
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head) return {};
        if(!head->next) return {0};
        vi out;
        while(head){
            out.push_back(head->val);
            head = head->next;
        }
        stack<int> stk;
        for(auto i=(int)out.size()-1; i>=0; --i){
            while(stk.size() && stk.top()<=out[i])
                stk.pop();
            
            int temp = out[i];
            out[i] = stk.size() ? stk.top() : 0;
            stk.push(temp);
        }
        return out;
    }
};
// @lc code=end


int main(){
    Solution sol; vi out; ListNode* head;
    head = createList({2,1,5});
    out = sol.nextLargerNodes(head); print(out);
    return 0;
}