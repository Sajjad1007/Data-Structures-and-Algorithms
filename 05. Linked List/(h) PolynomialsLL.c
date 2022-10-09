#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct term{
    int coef;
    int expo;
    struct term *next;
} *poly = NULL;

struct term *create()
{
    int n;
    struct term *t = NULL;
    struct term *first = NULL;
    struct term *last = NULL;
    printf("Enter the number of terms = ");
    scanf("%d", &n);
    printf("\n");

    for(int i = 1; i <= n; i++){
        t = (struct term*)malloc(sizeof(struct term));
        printf("Enter the coefficient and exponent for term %d : ", i);
        scanf("%d %d", &t->coef, &t->expo);
        t->next = NULL;
        if(first == NULL) first = last = t;
        else{
            last->next = t;
            last = t;
        }
    }
    return first;
}

void display(struct term *p)
{
    while(p){
        if(p->coef != 0 && p->expo != 0){
            printf("(%dx^%d)", p->coef, p->expo);
        }
        else if(p->coef != 0 && p->expo == 0){
            printf("(%d)", p->coef);
        }

        p = p->next;
        if(p) printf(" + ");
        else printf("\n");
    }
    return;
}

void evaluate(int x)
{
    int sum = 0;
    struct term *p = poly;
    while(p){
        sum += (p->coef * pow(x, p->expo));
        p = p->next;
    }
    printf("For x = %d, sum = %d\n", x, sum);
    return;
}

int main(void)
{
    int x;
    poly = create();
    printf("\nThe given polynomial = ");
    display(poly);
    printf("\nEnter the value of x = ");
    scanf("%d", &x);
    evaluate(x);
    return 0;
}
