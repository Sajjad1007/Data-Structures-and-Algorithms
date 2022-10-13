struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct queue{
    int size;
    int front;
    int rear;
    struct node **Q; //pointer to an array of pointers
};

void createQueue(struct queue *q, int sz)
{
    q->front = q->rear = -1;
    q->size = sz;
    q->Q = (struct node**)malloc(sz*sizeof(struct node*));
    return;
}

bool isEmpty(struct queue q)
{
    if(q.front == -1) return true;
    else return false;
}

bool isFull(struct queue q)
{
    if((q.front == 0 && q.rear == q.size-1) || (q.front == q.rear+1)) return true;
    else return false;
}

int countElement(struct queue *q)
{
    if(q->front == -1) return 0;
    int cnt = 0;
    int front = q->front;
    while(front != q->rear){
        cnt++;
        front = (front + 1) % q->size;
    }
    return ++cnt;
}

void enqueue(struct queue *q, struct node *data)
{
    if(q->front == -1) q->front = 0;
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = data;
    return;
}

struct node *dequeue(struct queue *q)
{
    struct node *data = q->Q[q->front];
    if(q->front == q->rear) q->front = q->rear = -1;
    else q->front = (q->front + 1) % q->size;
    return data;
}
