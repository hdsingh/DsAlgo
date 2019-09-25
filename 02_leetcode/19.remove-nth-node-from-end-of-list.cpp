/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.59%)
 * Likes:    2161
 * Dislikes: 160
 * Total Accepted:    453.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
    // Using two pointers + Can also use dummy and NULL
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = 0; 
        node* prev = NULL;
        node* p1 = head;
        node* p2 = head; 

        while(c<n){
            p2 = p2->next;
            c++;
        }

        while(p2){
            prev = p1;
            p1 = p1->next;
            p2 = p2->next;
        }

        if(prev){
            prev->next = p1->next;
            delete p1;
            p1 = NULL;
        }else{
            node* temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
        }
        
        return head;
    }


    // Using array as cache
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        vector<node*> cache;
        node* cur = head;
        while(cur){
            cache.push_back(cur);
            cur = cur->next;
        }
        int len = cache.size();

        node* temp;
        if(len-n==0){ //delete head
            temp = head;
            head = head->next;
            
        }
        else{
            int pos = len - n;
            temp = cache[pos];
            cache[pos-1]->next = cache[pos]->next;
        }
        delete temp;
        temp = NULL;
        return head;
    }


    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        node* temp; node* prev;
        node* cur = head;
        // Iterate to get count;
        int c = 0; //count
        while(cur){
            cur = cur->next;
            c++;
        }
        // deb(c);
        // Handle the head
        if(n==c){
            temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
            return head;
        }
        prev = head;
        cur = head->next;
        c--;
        // deb(prev->val);
        // deb(cur->val);
        // deb(c);

        while(c>=n){
            if(c==n){
                prev->next = cur->next;
                delete cur;
                cur = NULL;
                break;
            }
            prev = cur;
            cur = cur->next;
            c--;
        }


        return head;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        ListNode* ret = Solution().removeNthFromEnd(head, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}

