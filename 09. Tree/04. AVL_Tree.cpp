#include <iostream>

using namespace std;

class AVL
{
private:
    struct node
    {
        node *lchild;
        int val;
        int ht;
        node *rchild;

        node(int val)
        {
            lchild = nullptr;
            this->val = val;
            ht = 0;
            rchild = nullptr;
        }
    } *root = nullptr;

    int height(node *p)
    {
        int hl = (p && p->lchild) ? p->lchild->ht : -1;
        int hr = (p && p->rchild) ? p->rchild->ht : -1;
        return (hl > hr) ? hl+1 : hr+1;
    }

    int balance_factor(node *p)
    {
        int hl = (p && p->lchild) ? p->lchild->ht : -1;
        int hr = (p && p->rchild) ? p->rchild->ht : -1;
        return hl-hr;
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

    node *LL_rotation(node *p)
    {
        node *pl = p->lchild;
        node *plr = pl->rchild;

        pl->rchild = p;
        p->lchild = plr;
        p->ht = height(p);
        pl->ht = height(pl);

        if(root == p)
        {
            root = pl;
        }
        return pl;
    }

    node *LR_rotation(node *p)
    {
        node *pl = p->lchild;
        node *plr = pl->rchild;

        pl->rchild = plr->lchild;
        p->lchild = plr->rchild;
        plr->lchild = pl;
        plr->rchild = p;
        pl->ht = height(pl);
        p->ht = height(p);
        plr->ht = height(plr);

        if(root == p)
        {
            root = plr;
        }
        return plr;
    }

    node *RR_rotation(node *p)
    {
        node *pr = p->rchild;
        node *prl = pr->lchild;

        pr->lchild = p;
        p->rchild = prl;
        p->ht = height(p);
        pr->ht = height(pr);

        if(root == p)
        {
            root = pr;
        }
        return pr;
    }

    node *RL_rotation(node *p)
    {
        node *pr = p->rchild;
        node *prl = pr->lchild;

        pr->lchild = prl->rchild;
        p->rchild = prl->lchild;
        prl->rchild = pr;
        prl->lchild = p;
        pr->ht = height(pr);
        p->ht = height(p);
        prl->ht = height(prl);

        if(root == p)
        {
            root = prl;
        }
        return prl;
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

        p->ht = height(p);
        int bf_p = balance_factor(p);
        int bf_pl = balance_factor(p->lchild);
        int bf_pr = balance_factor(p->rchild);

        if(bf_p == 2 && bf_pl == 1)
        {
            return LL_rotation(p);
        }
        else if(bf_p == 2 && bf_pl == -1)
        {
            return LR_rotation(p);
        }
        else if(bf_p == -2 && bf_pr == -1)
        {
            return RR_rotation(p);
        }
        else if(bf_p == -2 && bf_pr == 1)
        {
            return RL_rotation(p);
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

            p->ht = height(p);
            int bf_p = balance_factor(p);
            int bf_pl = balance_factor(p->lchild);
            int bf_pr = balance_factor(p->rchild);

            if(bf_p == 2 && bf_pl == 1)
            {
                return LL_rotation(p);       // L1 Rotation
            }
            else if(bf_p == 2 && bf_pl == -1)
            {
                return LR_rotation(p);       // L-1 Rotation
            }
            else if(bf_p == -2 && bf_pr == -1)
            {
                return RR_rotation(p);       // R-1 Rotation
            }
            else if(bf_p == -2 && bf_pr == 1)
            {
                return RL_rotation(p);       // R1 Rotation
            }
            else if(bf_p == 2 && bf_pl == 0)
            {
                return LL_rotation(p);       // L0 Rotation
            }
            else if(bf_p == -2 && bf_pr == 0)
            {
                return RR_rotation(p);       // R0 Rotation
            }
        }
        return p;
    }

public:
    AVL()
    {
        root = nullptr;
    }

    ~AVL()
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
    cout << "4. Traversals\n";
    cout << "5. Quit\n";
    return;
}

int main()
{
    AVL t;
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
                cout << "\nThe AVL tree has been initialized.";
                break;

            case 2:
                cout << "Enter a node : ";
                cin >> key;
                t.Insert(key);
                cout << "\n" << key << " has been inserted.";
                break;

            case 3:
                cout << "Enter a node : ";
                cin >> key;
                t.Delete(key);
                cout << "\n" << key << " has been deleted.";
                break;

            case 4:
                cout << "\nPre-order traversal :";
                t.preorder(t.get_root());
                cout << "\nIn-order traversal :";
                t.inorder(t.get_root());
                cout << "\nPost-order traversal :";
                t.postorder(t.get_root());
                break;

            case 5:
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
