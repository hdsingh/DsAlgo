struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

ListNode* createList(vi a){
    int n = a.size();
    if(!n) return NULL;
    ListNode *head = new ListNode(a[0]);
    ListNode *cur = head;
    for(int i=1; i<n; ++i){
        cur->next = new ListNode(a[i]);
        cur = cur->next;
    }
    return head;
}

void printList(ListNode* head){
    ListNode* cur = head;
    while(cur){
        cout<<cur->val<<" ";
        cur=cur->next;
    }
    cout<<endl;
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

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};