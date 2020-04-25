struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

// typedef TreeNode node;

// node* createLevelOrder(vector<int> v){
//     int n = v.size();
//     if (n<1) return new node(0);
//     node* root = new node(v[0]);
//     node* cur = root;
//     queue<node*> q;
//     q.push(root);
    
//     auto i = v.begin()+1;
//     while(i!=v.end()){
//         cur = q.front();
//         q.pop();

//         node* l = new node(*i);
//         q.push(l);
//         cur->left = l;
//         i++;
        
//         if(i!=v.end()){
//             node* r = new node(*i);
//             q.push(r);
//             cur->right = r;
//             i++;
//         }
//     }
//     return root;
// }

// vector<int> levelOrder(node* root){
//     vector<int> v;
//     queue<node*> q;
//     q.push(root);

//     while(!q.empty()){
//         node* cur = q.front();
//         cout<<cur->val<<" ";
//         v.push_back(cur->val);

//         if(cur->left) q.push(cur->left);
//         if(cur->right) q.push(cur->right);
//         q.pop();
//     }
//     return v;
// }

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };