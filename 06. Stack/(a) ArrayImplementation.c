#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack{
    int top;
    int size;
    int *S;
} st;

void create(int sz)
{
    st.top = -1;
    st.size = sz;
    st.S = (int*)malloc(sz*sizeof(int));
    return;
}

bool isEmpty()
{
    if(st.top == -1) return true;
    else return false;
}

bool isFull()
{
    if(st.top == st.size-1) return true;
    else return false;
}

void push(int data)
{
    st.S[++st.top] = data;
    return;
}

int pop()
{
    return st.S[st.top--];
}

int peek(int pos)
{
    return st.S[st.top-pos+1];
}

int stackTop()
{
    return st.S[st.top];
}

void display()
{
    printf("The stack :");
    for(int i = st.top; i >= 0; --i){
        printf(" %d", st.S[i]);
    }
    printf("\n");
    return;
}

void printChoiceList()
{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print the topmost element\n");
    printf("4. Print any element\n");
    printf("5. Quit\n");
    return;
}

int main(void)
{
    int sz, choice, data, pos;
    printf("Enter size of the stack = ");
    scanf("%d", &sz);
    create(sz);
    printf("The stack has been initialized\n\n");

    while(true){
        printChoiceList();
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(!isFull()){
                    printf("Enter the element to be pushed : ");
                    scanf("%d", &data);
                    push(data);
                    printf("\n%d is pushed successfully\n", data);
                    display();
                }
                else printf("\nStack overflow\n");
                break;
            case 2:
                if(!isEmpty()){
                    printf("\nDeleted element is %d\n", pop());
                    display();
                }
                else printf("\nThe stack is empty\n");
                break;
            case 3:
                if(!isEmpty()){
                    printf("\nThe topmost element is %d\n", stackTop());
                }
                else printf("\nThe stack is empty\n");
                break;
            case 4:
                if(!isEmpty()){
                    printf("Enter the position : ");
                    scanf("%d", &pos);
                    if(st.top-pos+1 < 0 || pos <= 0) printf("\nInvalid position\n");
                    else{
                        printf("\nThe element at position %d is %d\n", pos, peek(pos));
                    }
                }
                else printf("\nThe stack is empty\n");
                break;
            case 5:
                printf("\nFee Amanillah\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }
}
