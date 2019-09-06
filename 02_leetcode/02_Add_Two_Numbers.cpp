#include <bits/stdc++.h>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* convertToLinkedList(int n);
int convertToInt(ListNode *l);

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n, m, r;
        int c = 0;
        ListNode *prev = NULL, *head = NULL;

        while (l1 || l2 || c)
        {
            n = l1 ? l1->val : 0;
            m = l2 ? l2->val : 0;
            r = n + m + c;
            c = r/10;
            ListNode *curr = new ListNode(r%10);
    
            if (!head) head = curr;
            if (prev) prev->next = curr;
            prev = curr;

            l1 = l1 ? l1->next: NULL;
            l2 = l2 ? l2->next: NULL;
        }

        if (c>0){
            prev->next = new ListNode(c);
        }
        return head;
        
    }
};

ListNode* convertToLinkedList(int n){
    int j;
    j = n%10;
    n = n/10;
    ListNode *l1 = new ListNode(j);
    ListNode *currr = l1;
    while(n!=0){
        j = n%10;
        n = n/10;
        ListNode *t = new ListNode(j);
        currr->next = t;
        currr=t;
    }
    return l1;
}

int convertToInt(ListNode *l){
    int n = 0;
    int i = 0;
    if (l==NULL){
        return n;
    }else{
        ListNode *currr = l;
        while(currr!=NULL){
            int j = currr->val;
            currr = currr->next;
            n = n + j*pow(10.0,i);
            i++;
        }
        return n;
    }
}


int vtoi(vector<int> v){
    string s1 = "";

    for(int x: v){
        s1 +=to_string(x);
    }

    return stoi(s1);
}

ListNode* vtol(vector<int> v){
    int i = vtoi(v);
    return convertToLinkedList(i);
}

void show(ListNode *l){
    ListNode *temp = l;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

int main(){
    vector<int> v1 {3,4,2};
    ListNode *l1 = vtol(v1);

    vector<int> v2 {4,6,5};
    ListNode *l2 = vtol(v2);

    Solution *s1 = new Solution;
    ListNode *out = s1->addTwoNumbers(l1, l2);
    show(out);

}