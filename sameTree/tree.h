#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

using namespace std;

class Tree{
    class Node{
        public:
            friend class Tree;
            Node() {data = -1; left = NULL; right = NULL;}
            Node(const int x, Node* left, Node* right) : data(x), left(left), right(right) {}

        protected:
            int data;
            Node* left;
            Node* right;
    };
public:

    Tree() {
        mRoot = NULL;
        mSize = 0;
    }

    ~Tree() {
        clear(mRoot);
    }

    Node getNode(Node r, int e)
    {
        if (r == NULL) return nullptr;
        int cmp compare(e, r.element);
        if (cmp == 0) return r;
        if (cmp < 0) return getNode(r->left, e);
        else return getNode(r->right, e);

    }

    void clear(Node*& r) {
        if (!r) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

    void insert(int x) {
        insertAt(mRoot, x);
    }

    int countNode(Node* mRoot) {
        if (!mRoot) return 0;
        return 1 + countNode(mRoot->left) + countNode(mRoot->right);
    }

    bool isSameBinaryTree(Tree& t) {
        return isSameCheck(mRoot, t.mRoot);
    }

    bool isSameCheck(Node* l, Node* r){

        if (!l && !r) return true;
        if (l->data != r->data) return false;
        return isSameCheck(l->left, r->left) && isSameCheck(l->right, r->right);

    }



public:
    void insertAt(Node*& r, int x) {
        if (!r) {
           r = new Node(x, NULL, NULL);
           mSize++;
           return;
        }
        if (r->data == x) return; // Do nothing
        if (x < r->data) insertAt(r->left, x); else
        insertAt(r->right, x);
    }
    Node* mRoot;
    int mSize;

};

#endif // TREE_H_INCLUDED
