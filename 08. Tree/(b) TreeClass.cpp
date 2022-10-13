#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct node{
    node *lchild;
    int data;
    node *rchild;
};

class Tree
{

private:
    node *root;
    queue <node*> q;

    void postorder(node *p)
    {
        if(p != NULL){
            postorder(p->lchild);
            postorder(p->rchild);
            cout << " " << p->data;
        }
        return;
    }

public:
    Tree()
    {
        root = nullptr;
    }

    ~Tree()
    {
        while(!q.empty()) q.pop();
    }

    node *getRoot()
    {
        return root;
    }

    void createTree()
    {
        int data;
        node *p = nullptr;
        node *t = nullptr;

        cout << "The tree has been initialized\n" << endl;
        cout << "Enter root : " << flush;
        cin >> data;
        root = new node;
        root->data = data;
        root->lchild = nullptr;
        root->rchild = nullptr;
        q.push(root);

        while(!q.empty()){
            p = q.front();
            q.pop();

            cout << "\nEnter left  child (non-zero value) of " << p->data << " : ";
            cin >> data;
            if(data != 0){
                t = new node;
                t->data = data;
                t->lchild = t->rchild = nullptr;
                p->lchild = t;
                q.push(t);
            }

            cout << "Enter right child (non-zero value) of " << p->data << " : ";
            cin >> data;
            if(data != 0){
                t = new node;
                t->data = data;
                t->lchild = t->rchild = nullptr;
                p->rchild = t;
                q.push(t);
            }
        }
        return;
    }

    int countNodes(node *p)
    {
        if(p) return countNodes(p->lchild) + countNodes(p->rchild) + 1;
        else return 0;
    }

    int countExternalNodes(node *p)
    {
        if(p == nullptr) return 0;
        if(p->lchild == nullptr && p->rchild == nullptr)
            return countExternalNodes(p->lchild) + countExternalNodes(p->rchild) + 1;
        else return countExternalNodes(p->lchild) + countExternalNodes(p->rchild);
    }

    int countHeight(node *p)
    {
        int l = 0, r = 0;
        if(p == nullptr) return 0;
        else{
            l = countHeight(p->lchild);
            r = countHeight(p->rchild);
            if(l > r) return l+1;
            else return r+1;
        }
    }

    /*
    total number of iterative calls = n
    time complexity of the traversals is O(n)
    size of the stack of recursive calls in memory = h+1
    */
    void preorder()
    {
        node *p = root;
        stack <node*> s;
        while(!s.empty() || p != nullptr){
            if(p != nullptr){
                cout << " " << p->data;
                s.push(p);
                p = p->lchild;
            }
            else{
                p = s.top();
                s.pop();
                p = p->rchild;
            }
        }
        return;
    }

    void inorder()
    {
        node *p = root;
        stack <node*> s;
        while(!s.empty() || p != nullptr){
            if(p != nullptr){
                s.push(p);
                p = p->lchild;
            }
            else{
                p = s.top();
                s.pop();
                cout << " " << p->data;
                p = p->rchild;
            }
        }
        return;
    }

    void postorder()
    {
        return postorder(root);
    }

    void levelorder()
    {
        node *p = root;
        queue <node*> lq;
        cout << " " << root->data;
        lq.push(root);

        while(!lq.empty()){
            p = lq.front();
            lq.pop();

            if(p->lchild != nullptr){
                cout << " " << p->lchild->data;
                lq.push(p->lchild);
            }
            if(p->rchild != nullptr){
                cout << " " << p->rchild->data;
                lq.push(p->rchild);
            }
        }
        return;
    }

};

int main()
{
    Tree t;
    t.createTree();
    cout << "\n\nNumber of nodes = " << t.countNodes(t.getRoot()) << endl;
    cout << "External nodes = " << t.countExternalNodes(t.getRoot()) << endl;
    cout << "Internal nodes = " << t.countNodes(t.getRoot())
            - t.countExternalNodes(t.getRoot()) << endl;
    cout << "Height = " << t.countHeight(t.getRoot())-1 << endl;

    cout << "\nPre-order   traversal : ";
    t.preorder();
    cout << "\nIn-order    traversal : ";
    t.inorder();
    cout << "\nPost-order  traversal : ";
    t.postorder();
    cout << "\nLevel-order traversal : ";
    t.levelorder();
    cout << endl;
    return 0;
}
