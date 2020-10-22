#include <bits/stdc++.h>
using namespace std;
#include "LinkedList.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* out = new ListNode(-1);
        ListNode* outhead = out;
        
        auto compare = [&](ListNode* node1, ListNode* node2){
            return node1->val>node2->val;  
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        
        for(auto head: lists)
            if(head)
                pq.push(head);
        
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            out->next = top;
            out = out->next;
            
            if(top->next)
                pq.push(top->next);
        }
        
        return outhead->next;
    }
};

class Solution0 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,ListNode*> save; // val : node with that val
        ListNode *dummy = new ListNode(INT_MIN);
        save[INT_MIN] = dummy;
        
        for(auto list: lists){
            ListNode *cur = list, *nextNode = NULL;
            while(cur){
                nextNode = cur->next;
                
                auto pos = save.upper_bound(cur->val);
                --pos;

                ListNode* tempNext = pos->second->next;
                pos->second->next = cur;
                cur->next = tempNext;
                save[cur->val] = cur;
                
                cur = nextNode;
            }
        }
        
        return dummy->next;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    return 0;
}