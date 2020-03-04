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

// 1,2,3,4 -> 3
ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
};

// 1,2,3,4 -> 2
ListNode* findMid2(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
};


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

ListNode* reverseListRec(ListNode* head){
    if(!head || !head->next) return head;

    ListNode *end = reverseListRec(head->next);
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