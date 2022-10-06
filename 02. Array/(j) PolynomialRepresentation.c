#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct term{
    int coef;
    int expo;
};

struct polynomial{
    int numberOfTerms;
    struct term *terms;
};

void create(struct polynomial *p)
{
    printf("enter the number of terms = ");
    scanf("%d", &p->numberOfTerms);
    p->terms = (struct term*)malloc(p->numberOfTerms*sizeof(struct term));
    printf("\n");

    for(int i = 0; i < p->numberOfTerms; i++){
        printf("Enter the coefficient and exponent for term %d : ", i+1);
        scanf("%d %d", &p->terms[i].coef, &p->terms[i].expo);
    }
    return;
}

void display(struct polynomial p)
{
    for(int i = 0; i < p.numberOfTerms; i++){
        if(p.terms[i].coef != 0 && p.terms[i].expo != 0){
            printf("(%dx^%d)", p.terms[i].coef, p.terms[i].expo);
        }
        else if(p.terms[i].coef != 0 && p.terms[i].expo == 0){
            printf("(%d)", p.terms[i].coef);
        }
        else continue;

        if(i != p.numberOfTerms-1) printf(" + ");
        else printf("\n");
    }
    return;
}

struct polynomial add(struct polynomial p1, struct polynomial p2)
{
    int i = 0, j = 0, k = 0;
    struct polynomial sum;
    sum.numberOfTerms = p1.numberOfTerms + p2.numberOfTerms;
    sum.terms = (struct term*)malloc(sizeof(struct term)*(sum.numberOfTerms));

    while(i < p1.numberOfTerms && j < p2.numberOfTerms){
        if(p1.terms[i].expo > p2.terms[j].expo){
            sum.terms[k++] = p1.terms[i++];
        }
        else if(p1.terms[i].expo < p2.terms[j].expo){
            sum.terms[k++] = p2.terms[j++];
        }
        else{
            sum.terms[k].expo = p1.terms[i].expo;
            sum.terms[k].coef = p1.terms[i++].coef + p2.terms[j++].coef;
            if(sum.terms[k++].coef == 0) k--;
        }
    }

    while(i < p1.numberOfTerms) sum.terms[k++] = p1.terms[i++];
    while(j < p2.numberOfTerms) sum.terms[k++] = p2.terms[j++];
    sum.numberOfTerms = k;
    return sum;
}

void evaluate(struct polynomial p, int x)
{
    int i, sum = 0;
    for(i = 0; i < p.numberOfTerms; i++){
        sum += (p.terms[i].coef * pow(x, p.terms[i].expo));
    }
    printf("For x = %d, sum = %d\n", x, sum);
    return;
}

int main(void)
{
    int x;
    struct polynomial p1, p2, sum;
    printf("For 1st polynomial, ");
    create(&p1);
    printf("\n1st polynomial = ");
    display(p1);
    printf("\n\nFor 2nd polynomial, ");
    create(&p2);
    printf("\n2nd polynomial = ");
    display(p2);
    sum = add(p1, p2);
    printf("\n\nAdded polynomial = ");
    display(sum);
    printf("\nEnter the value of x = ");
    scanf("%d", &x);
    evaluate(sum, x);
    return 0;
}
