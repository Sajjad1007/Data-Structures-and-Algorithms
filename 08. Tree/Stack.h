struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct stack{
    int size;
    int top;
    struct node **S; //pointer to an array of node pointers
};

void createStack(struct stack *s, int sz)
{
    s->top = -1;
    s->size = sz;
    s->S = (struct node**)malloc(sz*sizeof(struct node*));
    return;
}

bool isEmpty(struct stack *s)
{
    if(s->top == -1) return true;
    else return false;
}

struct node *top(struct stack *s)
{
    return s->S[s->top];
}

void push(struct stack *s, struct node *data)
{
    s->S[++s->top] = data;
    return;
}

void pop(struct stack *s)
{
    s->S[s->top--];
    return;
}
