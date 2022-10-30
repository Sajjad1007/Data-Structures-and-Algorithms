#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL;

int heightOf(struct node *p)
{
    int l = 0, r = 0;
    if(p == NULL) return 0;
    else{
        l = heightOf(p->lchild);
        r = heightOf(p->rchild);
        if(l > r) return l+1;
        else return r+1;
    }
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

void insert(int key)
{
    struct node *t = root;
    struct node *r = NULL;

    if(root == NULL){
        root = (struct node*)malloc(sizeof(struct node));
        root->data = key;
        root->lchild = root->rchild = NULL;
        return;
    }

    while(t != NULL){
        r = t;
        if(key < t->data) t = t->lchild;
        else if(key > t->data) t = t->rchild;
        else return; //if key is found

    }

    t = (struct node*)malloc(sizeof(struct node));
    t->data = key;
    t->lchild = t->rchild = NULL;

    if(key < r->data) r->lchild = t;
    else r->rchild = t;
    return;
}

struct node *delete(struct node *p, int key)
{
    if(p == NULL); //tree has no nodes
    else if(key == p->data && p->lchild == NULL && p->rchild == NULL){
        if(p == root) root = NULL;
        free(p); //node has been deleted
        p = NULL;
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
    return p;
}

bool search(int key)
{
    struct node *t = root;
    while(t != NULL){
        if(key < t->data) t = t->lchild;
        else if(key > t->data) t = t->rchild;
        else return true;
    }
    return false;
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
        insert(key);
    }

    printf("\nIn-order traversal of BST :");
    inorder(root);

    printf("\n\nEnter a value to search : ");
    scanf("%d", &key);
    if(search(key)) printf("%d is found in the tree\n", key);
    else printf("%d is not found in the tree\n", key);

    printf("\nEnter a value to delete : ");
    scanf("%d", &key);
    root = delete(root, key);
    printf("\nIn-order traversal of BST :");
    inorder(root);
    printf("\n");
    return 0;
}
