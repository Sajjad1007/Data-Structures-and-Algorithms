#include <iostream>
#include <stack>

using namespace std;

struct node{
    node *lchild;
    int data;
    node *rchild;
} *root = nullptr;

void createBST(int *nodes, int n)
{
    int i = 0;
    root = new node; //root node created
    root->data = nodes[i++];
    root->lchild = root->rchild = nullptr;

    node* p = root;
    node* t = nullptr;
    stack <node*> s;

    while(i < n){
        if(nodes[i] < p->data){
            t = new node;
            t->data = nodes[i++];
            t->lchild = t->rchild = nullptr;
            p->lchild = t; //insert at left child
            s.push(p);
            p = t;
        }
        else{
            if(nodes[i] > p->data && nodes[i] < (s.empty() ? INT_MAX : s.top()->data)){
                t = new node;
                t->data = nodes[i++];
                t->lchild = t->rchild = nullptr;
                p->rchild = t; //insert at right child
                p = t;
            }
            else{
                p = s.top();
                s.pop();
            }
        }
    }
    return;
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

int main()
{
    int i, n;
    cout << "Number of nodes = ";
    cin >> n;
    int nodes[n];
    cout << "\nEnter pre-order traversal of BST : ";

    for(i = 0; i < n; i++) cin >> nodes[i];
    createBST(nodes, n);
    cout << "\nIn-order traversal of BST :";
    inorder(root);
    cout << '\n';
    return 0;
}
