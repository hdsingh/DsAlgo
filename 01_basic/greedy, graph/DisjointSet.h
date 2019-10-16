using namespace std;

struct Node{
    int data;
    Node *parent;
    int rank;
    Node(int x): data(x), parent(NULL), rank(0){}
};

class DisjointSet{
private:
    map<int, Node*> m;

public:
    void makeSet(int data){
        Node *node = new Node(data);
        // Make a node point back to itself
        node->parent = node;
        m.insert({data, node});
    }

    bool Union(int a, int b){
        // find the node for a data element
        Node *n1 = m[a];
        Node *n2 = m[b];

        // find parent of nodes
        Node *p1 = findSet(n1);
        Node *p2 = findSet(n2);

        // If same do nothing
        if(p1->data==p2->data) return false;

        if(p1->rank>=p2->rank){
            p1->rank = p1->rank==p2->rank ? p1->rank+1 : p1->rank;
            p2->parent = p1;
        }
        else{//p2->rank > p1->rank
            p1->parent = p2;
            p2->rank+=1;
        }
        return true;
    }

    int findSet(int data){
        return findSet(m[data])->data;
    }
    
    // find representative recursively and do path compression as well
    Node* findSet(Node *node){
        Node *parent = node->parent;
        if (parent->data == node->data) {
            return parent;
        }
        // path compression
        node->parent = findSet(node->parent);
        return node->parent;
    }
};