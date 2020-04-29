struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef TreeNode node;

//     sample inorder tree
//			40        
//		  /    \
//		 20     60
//		/ \     /
//	   10  30  50

TreeNode* ExampleInTree(){
    TreeNode* root = new TreeNode(40);
    root->left = new TreeNode(20);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(30);
    root->right->left = new TreeNode(50);
    return root;
};

//     sample preorder tree
//			10        
//		  /    \
//		 20    50
//		/ \     \
//	   30  40   60

node* ExamplePreTree(){
    node* root = new node(10);
    root->left = new node(20);
    root->right = new node(50);
    root->left->left = new node(30);
    root->left->right = new node(40);
    root->right->right = new node(60);
    return root;
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

// class Solution {
// public:

    TreeNode* create(vector<int> & a, int l, int r){
        if(l>r) return NULL;
        // if(l==r){
        //     return new TreeNode(a[l]);
        // }
        int mid = l + (r-l)/2;
        
        TreeNode* midnode = new TreeNode(a[mid]);
        midnode->left = create(a, l, mid-1);
        midnode->right = create(a, mid+1, r);
        return midnode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(!n) return NULL;
        int l = 0;
        int r = n-1;
        return create(nums, l, r);
    }
// };