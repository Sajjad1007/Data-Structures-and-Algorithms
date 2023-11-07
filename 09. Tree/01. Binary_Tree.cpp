#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class BT
{
private:
    struct node{
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

    int diameter = 0;
    queue <node*> q;
    vector <int> pre;
    vector <int> in;
    vector <int> post;

public:
    BT()
    {
        root = nullptr;
    }

    ~BT()
    {
        while(!q.empty()){
            q.pop();
        }
    }

    node *get_root()
    {
        return root;
    }

    void create()
    {
        int rt, l, r;
        node *p = nullptr;
        node *t = nullptr;

        cout << "\nEnter root (non-zero value) : " << flush;
        cin >> rt;
        if(rt != 0){
            root = new node(rt);
            q.push(root);
        }

        while(!q.empty()){
            p = q.front();
            q.pop();

            cout << "Enter left and right child of " << p->val << " : ";
            cin >> l >> r;
            if(l != 0){
                t = new node(l);
                p->lchild = t;
                q.push(t);
            }

            if(r != 0){
                t = new node(r);
                p->rchild = t;
                q.push(t);
            }
        }
        return;
    }

    int count_nodes(node *p)
    {
        if(p == nullptr){
            return 0;
        }
        else{
            int n = count_nodes(p->lchild) + count_nodes(p->rchild) + 1;
            return n;
        }
    }

    int external_nodes(node *p)
    {
        if(p == nullptr){
            return 0;
        }
        else if(p->lchild == nullptr && p->rchild == nullptr){
            return 1;
        }
        else{
            int e = external_nodes(p->lchild) + external_nodes(p->rchild);
            return e;
        }
    }

    int height(node *p)
    {
        if(p == nullptr){
            return 0;
        }
        else{
            int lh = height(p->lchild);
            int rh = height(p->rchild);
            diameter = max(diameter, lh + rh);
            return 1 + max(lh, rh);
        }
    }

    int get_diameter()
    {
        return diameter;
    }

    bool balanced(node *p)
    {
        if(p == nullptr){
            return true;
        }
        else{
            int lh = height(p->lchild);
            int rh = height(p->rchild);

            if(abs(lh - rh) > 1){
                return false;
            }
            else{
                bool lb = balanced(p->lchild);
                bool rb = balanced(p->rchild);

                if(lb == false || rb == false){
                    return false;
                }
                else{
                    return true;
                }
            }
        }
    }

    /*
    Total number of iterative calls = n
    Time complexity of the traversals = O(n)
    Size of the stack of recursive calls in memory = h+1
    */
    void preorder()
    {
        node *p = root;
        stack <node*> s;

        while(!s.empty() || p != nullptr){
            if(p != nullptr){
                cout << " " << p->val;
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
                cout << " " << p->val;
                p = p->rchild;
            }
        }
        return;
    }

    void postorder()
    {
        node *q, *p = root;
        stack <node*> s;

        while(!s.empty() || p != nullptr){
            if(p != nullptr){
                s.push(p);
                p = p->lchild;
            }
            else{
                q = s.top()->rchild;
                if(q == nullptr){
                    q = s.top();
                    s.pop();
                    cout << " " << q->val;

                    while(!s.empty() && q == s.top()->rchild){
                        q = s.top();
                        s.pop();
                        cout << " " << q->val;
                    }
                }
                else{
                    p = q;
                }
            }
        }
        return;
    }

    void levelorder()
    {
        int level = 1;
        node *p = root;
        queue <node*> lq;
        lq.push(root);

        while(!lq.empty()){
            int sz = lq.size();
            cout << "\nLevel " << level << " :";
            level++;

            for(int i = 1; i <= sz; i++){
                p = lq.front();
                lq.pop();
                cout << " " << p->val;

                if(p->lchild != nullptr){
                    lq.push(p->lchild);
                }
                if(p->rchild != nullptr){
                    lq.push(p->rchild);
                }
            }
        }
        return;
    }

    void all_traversals()
    {
        stack <pair <node*, int>> s;
        s.push({root, 1});

        while(!s.empty()){
            pair <node*, int> p = s.top();
            s.pop();

            switch(p.second)
            {
                case 1:
                    pre.push_back(p.first->val);
                    s.push({p.first, 2});

                    if(p.first->lchild){
                        s.push({p.first->lchild, 1});
                    }
                    break;

                case 2:
                    in.push_back(p.first->val);
                    s.push({p.first, 3});

                    if(p.first->rchild){
                        s.push({p.first->rchild, 1});
                    }
                    break;

                case 3:
                    post.push_back(p.first->val);
                    break;
            }
        }
        return;
    }

    int lca(node *p, int x, int y)
    {
        if(p == nullptr){
            return 0;
        }
        else if(p->val == x || p->val == y){
            return p->val;
        }
        else{
            int l = lca(p->lchild, x, y);
            int r = lca(p->rchild, x, y);

            if(l == 0){
                return r;
            }
            else if(r == 0){
                return l;
            }
            else{
                return p->val;
            }
        }
    }
};

void choice_list()
{
    cout << "Menu\n";
    cout << "1. Initialize\n";
    cout << "2. Number of nodes\n";
    cout << "3. Height and diameter\n";
    cout << "4. Check balance\n";
    cout << "5. Traversals\n";
    cout << "6. Least common ancestor\n";
    cout << "7. Quit\n";
    return;
}

int main()
{
    BT t;
    vector <int> v;
    int n, e, x, y, ch;

    while(true){
        choice_list();
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                t.create();
                cout << "\nThe binary tree has been initialized";
                break;

            case 2:
                n = t.count_nodes(t.get_root());
                e = t.external_nodes(t.get_root());
                cout << "\nNumber of nodes = " << n;
                cout << "\nExternal nodes = " << e;
                cout << "\nInternal nodes = " << n - e;
                break;

            case 3:
                cout << "\nHeight of the tree = " << t.height(t.get_root()) - 1;
                cout << "\nDiameter of the tree = " << t.get_diameter();
                break;

            case 4:
                if(t.balanced(t.get_root())){
                    cout << "\nThe tree is balanced";
                }
                else{
                    cout << "\nThe tree is not balanced";
                }
                break;

            case 5:
                cout << "\nPre-order traversal :";
                t.preorder();
                cout << "\nIn-order traversal :";
                t.inorder();
                cout << "\nPost-order traversal :";
                t.postorder();
                cout << "\n";
                t.levelorder();
                break;

            case 6:
                cout << "Enter two nodes : ";
                cin >> x >> y;
                cout << "\nLeast Common Ancestor : " << t.lca(t.get_root(), x, y);
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
