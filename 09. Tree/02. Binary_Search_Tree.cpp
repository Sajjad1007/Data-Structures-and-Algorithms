#include <iostream>

using namespace std;

class BST
{
private:
    struct node
    {
        node *lchild;
        int val;
        node *rchild;

        node(int val)
        {
            lchild = nullptr;
            this->val = val;
            rchild = nullptr;
        }
    } *root = nullptr;

    int height(node *p)
    {
        if(p == nullptr)
        {
            return 0;
        }
        else
        {
            int lh = height(p->lchild);
            int rh = height(p->rchild);
            return 1+max(lh, rh);
        }
    }

    node *inorder_predecessor(node *p)
    {
        node *t = p->lchild;
        while(t && t->rchild)
        {
            t = t->rchild;
        }
        return t;
    }

    node *inorder_successor(node *p)
    {
        node *t = p->rchild;
        while(t && t->lchild)
        {
            t = t->lchild;
        }
        return t;
    }

    node *Insert(node *p, int key)
    {
        if(p == nullptr)
        {
            p = new node(key);
        }
        else if(key < p->val)
        {
            p->lchild = Insert(p->lchild, key);
        }
        else if(key > p->val)
        {
            p->rchild = Insert(p->rchild, key);
        }
        return p;
    }

    node *Delete(node *p, int key)
    {
        if(p == nullptr);
        else if(key == p->val && !p->lchild && !p->rchild)
        {
            if(p == root)
            {
                root = nullptr;
            }
            delete p;
            p = nullptr;
        }
        else if(key < p->val)
        {
            p->lchild = Delete(p->lchild, key);
        }
        else if(key > p->val)
        {
            p->rchild = Delete(p->rchild, key);
        }
        else
        {
            if(height(p->lchild) >= height(p->rchild))
            {
                node *q = inorder_predecessor(p);
                p->val = q->val;
                p->lchild = Delete(p->lchild, q->val);
            }
            else
            {
                node *q = inorder_successor(p);
                p->val = q->val;
                p->rchild = Delete(p->rchild, q->val);
            }
        }
        return p;
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

    node *get_root()
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
        while(t)
        {
            if(key < t->val)
            {
                t = t->lchild;
            }
            else if(key > t->val)
            {
                t = t->rchild;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    int get_floor(int key)
    {
        int floor = 0;
        node *t = root;

        while(t)
        {
            if(key == t->val)
            {
                floor = t->val;
                break;
            }
            else if(key < t->val)
            {
                t = t->lchild;
            }
            else if(key > t->val)
            {
                floor = t->val;
                t = t->rchild;
            }
        }
        return floor;
    }

    int get_ceil(int key)
    {
        int ceil = 0;
        node *t = root;

        while(t)
        {
            if(key == t->val)
            {
                ceil = t->val;
                break;
            }
            else if(key > t->val)
            {
                t = t->rchild;
            }
            else if(key < t->val)
            {
                ceil = t->val;
                t = t->lchild;
            }
        }
        return ceil;
    }

    /*
    Total number of recursive calls = (2n+1)
    Time complexity of the traversals = O(n)
    Size of the stack of recursive calls in memory = h+2
    */
    void preorder(node *p)
    {
        if(p != nullptr)
        {
            cout << " " << p->val;
            preorder(p->lchild);
            preorder(p->rchild);
        }
        return;
    }

    void inorder(node *p)
    {
        if(p != nullptr)
        {
            inorder(p->lchild);
            cout << " " << p->val;
            inorder(p->rchild);
        }
        return;
    }

    void postorder(node *p)
    {
        if(p != nullptr)
        {
            postorder(p->lchild);
            postorder(p->rchild);
            cout << " " << p->val;
        }
        return;
    }
};

void choice_list()
{
    cout << "Menu\n";
    cout << "1. Initialize\n";
    cout << "2. Insert\n";
    cout << "3. Delete\n";
    cout << "4. Search\n";
    cout << "5. Floor and ceil\n";
    cout << "6. Traversals\n";
    cout << "7. Quit\n";
    return;
}

int main()
{
    BST t;
    int i, n, ch, key;

    while(true)
    {
        choice_list();
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Number of nodes : ";
                cin >> n;
                cout << "Enter " << n << " nodes : ";
                for(i = 1; i <= n; i++)
                {
                    cin >> key;
                    t.Insert(key);
                }
                cout << "\nThe binary search tree has been initialized";
                break;

            case 2:
                cout << "Enter a node : ";
                cin >> key;
                t.Insert(key);
                cout << "\n" << key << " has been inserted";
                break;

            case 3:
                cout << "Enter a node : ";
                cin >> key;
                t.Delete(key);
                cout << "\n" << key << " has been deleted";
                break;

            case 4:
                cout << "Enter a node : ";
                cin >> key;
                cout << "\n";
                if(t.Search(key))
                {
                    cout << key << " is found";
                }
                else
                {
                    cout << key << " is not found";
                }
                break;

            case 5:
                cout << "Enter a value : ";
                cin >> key;
                cout << "\nFloor of " << key << " : " << t.get_floor(key);
                cout << "\nCeil  of " << key << " : " << t.get_ceil(key);
                break;

            case 6:
                cout << "\nPre-order traversal :";
                t.preorder(t.get_root());
                cout << "\nIn-order traversal :";
                t.inorder(t.get_root());
                cout << "\nPost-order traversal :";
                t.postorder(t.get_root());
                break;

            case 7:
                cout << "\nFee Amanillah\n";
                return 0;

            default:
                cout << "\nInvalid choice";
                break;
        }
        cout << "\n\n";
    }
    return 0;
}

/*
Menu driven program
*/
