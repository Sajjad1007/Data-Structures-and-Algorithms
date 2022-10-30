#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

struct node *root = NULL;

void createBST(int *nodes, int n)
{
    int i = 0;
    root = (struct node*)malloc(sizeof(struct node)); //root node created
    root->data = nodes[i++];
    root->lchild = root->rchild = NULL;

    struct node *p = root;
    struct node *t = NULL;
    struct stack s;
    createStack(&s, n);

    while(i < n){
        if(nodes[i] < p->data){
            t = (struct node*)malloc(sizeof(struct node));
            t->data = nodes[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            push(&s, p);
            p = t;
        }
        else{
            if(nodes[i] > p->data && nodes[i] < (isEmpty(&s) ? 10000 : top(&s)->data)){
                t = (struct node*)malloc(sizeof(struct node));
                t->data = nodes[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else{
                p = top(&s);
                pop(&s);
            }
        }
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
    int i, n;
    printf("Number of nodes = ");
    scanf("%d", &n);
    int nodes[n];
    printf("\nEnter pre-order traversal of BST : "); //the nodes must be in pre-order traversal

    for(i = 0; i < n; i++) scanf("%d", &nodes[i]);
    createBST(nodes, n);
    printf("\nIn-order traversal of BST :");
    inorder(root);
    printf("\n");
    return 0;
}
