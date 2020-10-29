#include <bits/stdc++.h>
using namespace std;
#include "LinkedList.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevend = dummy;
        
        while(prevend){
            ListNode* cur = prevend;
            for(int i=0; i<k; ++i){
                cur = cur->next;
                if(!cur) return dummy->next;
            }
            ListNode* nx = cur->next; // save
            // break link
            cur->next = NULL;
            ListNode* beg = prevend->next;
            prevend->next = reverseList(beg);
            
            beg->next = nx;
            prevend = beg;
        }
        
        return dummy->next;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode *prev(NULL), *cur(head), *next(NULL);
        
        while(cur){
            next = cur->next;
            cur->next =  prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}