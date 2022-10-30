#include <iostream>

using namespace std;

struct node{
    node *lchild;
    int data;
    node *rchild;
};

class BST
{

private:
    node *root;

    int height(node *p)
    {
        int l = 0, r = 0;
        if(p == nullptr) return 0;
        else{
            l = height(p->lchild);
            r = height(p->rchild);
            if(l > r) return l+1;
            else return r+1;
        }
    }

    node *inorderPredecessor(node *p)
    {
        while(p && p->rchild) p = p->rchild;
        return p;
    }

    node *inorderSuccessor(node *p)
    {
        while(p && p->lchild) p = p->lchild;
        return p;
    }

    node *Insert(node *p, int key)
    {
        if(p == nullptr){
            p = new node;
            p->data = key;
            p->lchild = p->rchild = nullptr;
        }
        else if(key < p->data) p->lchild = Insert(p->lchild, key);
        else if(key > p->data) p->rchild = Insert(p->rchild, key);
        return p;
    }

    node *Delete(node *p, int key)
    {
        if(p == nullptr); //tree has no nodes
        else if(key == p->data && p->lchild == nullptr && p->rchild == nullptr){
            if(p == root) root = nullptr;
            delete p; //node has been deleted
            p = nullptr;
        }
        else if(key < p->data) p->lchild = Delete(p->lchild, key);
        else if(key > p->data) p->rchild = Delete(p->rchild, key);
        else{
            if(height(p->lchild) >= height(p->rchild)){
                node *q = inorderPredecessor(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            }
            else{
                node *q = inorderSuccessor(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }
        return p;
    }

    void inorder(node *p)
    {
        if(p != nullptr){
            inorder(p->lchild);
            cout << " " << p->data;
            inorder(p->rchild);
        }
        return;
    }

public:
    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        delete root;
        root = nullptr;
    }

    node *getRoot()
    {
        return root;
    }

    void Insert(int key)
    {
        root = Insert(root, key);
        return;
    }

    void Delete(int key)
    {
        root = Delete(root, key);
        return;
    }

    bool Search(int key)
    {
        node *t = root;
        while(t != nullptr){
            if(key < t->data) t = t->lchild;
            else if(key > t->data) t = t->rchild;
            else return true;
        }
        return false;
    }

    void inorder()
    {
        inorder(root);
        return;
    }

};

int main()
{
    BST t;
    int i, n, key;
    cout << "Number of nodes = ";
    cin >> n;
    cout << "Enter " << n << " node(s) : ";

    for(i = 1; i <= n; i++){
        cin >> key;
        t.Insert(key);
    }

    cout << "\nIn-order traversal of BST :";
    t.inorder();

    cout << "\n\nEnter a value to search : ";
    cin >> key;
    if(t.Search(key)) cout << key << " is found in the tree\n";
    else cout << key << " is not found in the tree\n";

    cout << "\nEnter a value to delete : ";
    cin >> key;
    t.Delete(key);
    cout << "\nIn-order traversal of BST :";
    t.inorder();
    cout << '\n';
    return 0;
}
