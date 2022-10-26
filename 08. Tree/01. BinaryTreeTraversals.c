#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

int size;
struct node *root = NULL;

void createTree()
{
    struct node *p = NULL;
    struct node *t = NULL;
    struct queue q;

    int data;
    printf("Enter size of the queue (size > 0) = ");
    scanf("%d", &size);
    if(size <= 0) return;
    createQueue(&q, size);
    printf("\nThe tree has been initialized\n");
    printf("\nEnter root : ");
    scanf("%d", &data);

    root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q)){
        p = dequeue(&q);
        printf("\nCount = %d\n", countElement(&q)); //Count = number of elements in the queue


        printf("Enter left  child (non-zero value) of %d : ", p->data);
        scanf("%d", &data);
        if(data != 0){
            t = (struct node*)malloc(sizeof(struct node));
            t->data = data;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        if(!isFull(q)){
            printf("Enter right child (non-zero value) of %d : ", p->data);
            scanf("%d", &data);
            if(data != 0){
                t = (struct node*)malloc(sizeof(struct node));
                t->data = data;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                enqueue(&q, t);
            }
        }
        else return;
    }
    return;
}

int countNodes(struct node *p)
{
    if(p) return countNodes(p->lchild) + countNodes(p->rchild) + 1;
    else return 0;
}

int countExternalNodes(struct node *p)
{
    if(p == NULL) return 0;
    if(p->lchild == NULL && p->rchild == NULL)
        return countExternalNodes(p->lchild) + countExternalNodes(p->rchild) + 1;
    else return countExternalNodes(p->lchild) + countExternalNodes(p->rchild);
}

int countHeight(struct node *p)
{
    int l = 0, r = 0;
    if(p == NULL) return 0;
    else{
        l = countHeight(p->lchild);
        r = countHeight(p->rchild);
        if(l > r) return l+1;
        else return r+1;
    }
}

/*
Total number of recursive calls = (2n+1)
Time complexity of the traversals is O(n)
Size of the stack of recursive calls in memory = h+2
*/
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

void postorder(struct node *p)
{
    if(p != NULL){
        postorder(p->lchild);
        postorder(p->rchild);
        printf(" %d",p->data);
    }
    return;
}

void levelorder()
{
    struct queue lq;
    createQueue(&lq, size);
    printf(" %d", root->data);
    enqueue(&lq, root);

    while(!isEmpty(lq)){
        root = dequeue(&lq);

        if(root->lchild != NULL){
            printf(" %d", root->lchild->data);
            enqueue(&lq, root->lchild);
        }
        if(root->rchild != NULL){
            printf(" %d", root->rchild->data);
            enqueue(&lq, root->rchild);
        }
    }
    return;
}

int main(void)
{
    createTree();
    if(root == NULL){
        printf("\nSize of the queue must be greater than 0\n");
        return 0;
    }
    printf("\n\nNumber of nodes = %d\n", countNodes(root));
    printf("External nodes = %d\n", countExternalNodes(root));
    printf("Internal nodes = %d\n", countNodes(root)-countExternalNodes(root));
    printf("Height = %d\n", countHeight(root)-1);

    printf("\nPre-order   traversal : ");
    preorder(root);
    printf("\nIn-order    traversal : ");
    inorder(root);
    printf("\nPost-order  traversal : ");
    postorder(root);
    printf("\nlevel-order traversal : ");
    levelorder(root);
    printf("\n");
    return 0;
}
