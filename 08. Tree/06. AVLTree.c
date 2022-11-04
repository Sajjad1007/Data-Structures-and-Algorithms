#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
} *root = NULL;

int heightOf(struct node *p)
{
    int hl = p && p->lchild ? p->lchild->height : -1;
    int hr = p && p->rchild ? p->rchild->height : -1;
    return hl > hr ? hl+1 : hr+1;
}

int balanceFactor(struct node *p)
{
    int hl = p && p->lchild ? p->lchild->height : -1;
    int hr = p && p->rchild ? p->rchild->height : -1;
    return hl-hr;
}

struct node *inorderPredecessor(struct node *p)
{
    while(p && p->rchild) p = p->rchild;
    return p;
}

struct node *inorderSuccessor(struct node *p)
{
    while(p && p->lchild) p = p->lchild;
    return p;
}

struct node *LLRotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = heightOf(p);
    pl->height = heightOf(pl);

    if(root == p) root = pl;
    return pl;
}

struct node *LRRotation(struct node *p)
{
    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    pl->height = heightOf(pl);
    p->height = heightOf(p);
    plr->height = heightOf(plr);

    if(root == p) root = plr;
    return plr;
}

struct node *RRRotation(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;
    p->height = heightOf(p);
    pr->height = heightOf(pr);

    if(root == p) root = pr;
    return pr;
}

struct node *RLRotation(struct node *p)
{
    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
    prl->rchild = pr;
    prl->lchild = p;
    pr->height = heightOf(pr);
    p->height = heightOf(p);
    prl->height = heightOf(prl);

    if(root == p) root = prl;
    return prl;
}

struct node *insert(struct node *p, int key)
{
    if(p == NULL){
        p = (struct node*)malloc(sizeof(struct node));
        p->data = key;
        p->height = 0; //height == 0 when a node is newly created
        p->lchild = p->rchild = NULL;
    }
    else if(key < p->data) p->lchild = insert(p->lchild, key);
    else if(key > p->data) p->rchild = insert(p->rchild, key);

    p->height = heightOf(p);

    if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) return LLRotation(p);
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) return LRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) return RRRotation(p);
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) return RLRotation(p);
    return p;
}

struct node *delete(struct node *p, int key)
{
    if(p == NULL) return p;
    else if(key == p->data && p->lchild == NULL && p->rchild == NULL){
        if(p == root) root = NULL;
        free(p);
        p = NULL;
        return p;
    }
    else if(key < p->data) p->lchild = delete(p->lchild, key);
    else if(key > p->data) p->rchild = delete(p->rchild, key);
    else{
        if(heightOf(p->lchild) >= heightOf(p->rchild)){
            struct node *q = inorderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = delete(p->lchild, q->data);
        }
        else{
            struct node *q = inorderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = delete(p->rchild, q->data);
        }
    }

    p->height = heightOf(p);

    if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) return LLRotation(p); //L1 Rotation
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) return LRRotation(p); //L-1 Rotation
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) return RRRotation(p); //R-1 Rotation
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) return RLRotation(p); //R1 Rotation
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 0) return LLRotation(p); //L0 Rotation
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == 0) return RRRotation(p); //R0 Rotation
    return p;
}

void preorder(struct node *p)
{
    if(p != NULL){
        printf(" %d", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
    return;
}

void inorder(struct node *p)
{
    if(p != NULL){
        inorder(p->lchild);
        printf(" %d", p->data);
        inorder(p->rchild);
    }
    return;
}

int main(void)
{
    int i, n, key;
    printf("Number of nodes = ");
    scanf("%d", &n);
    printf("Enter %d node(s) : ", n);

    for(i = 1; i <= n; i++){
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("\nPre-order traversal of AVL tree :");
    preorder(root);
    printf("\nIn-order traversal of AVL tree  :");
    inorder(root);

    printf("\n\nEnter a value to delete : ");
    scanf("%d", &key);
    root = delete(root, key);
    printf("\nPre-order traversal of AVL tree :");
    preorder(root);
    printf("\nIn-order traversal of AVL tree  :");
    inorder(root);
    printf("\n");
    return 0;
}
