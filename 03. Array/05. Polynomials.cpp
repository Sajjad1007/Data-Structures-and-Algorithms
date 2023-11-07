#include <iostream>
#include <cmath>

using namespace std;

struct term
{
    int coef;
    int expo;
};

struct polynomial
{
    int terms_cnt;
    term *terms;

    void input()
    {
        cout << "number of terms = ";
        cin >> terms_cnt;
        terms = new term[terms_cnt];
        cout << "\n";

        for(int i = 0; i < terms_cnt; i++){
            cout << "Coefficient and exponent for term " << (i + 1) << " : ";
            cin >> terms[i].coef >> terms[i].expo;
        }
        return;
    }

    void display()
    {
        for(int i = 0; i < terms_cnt; i++){
            if(terms[i].coef != 0 && terms[i].expo != 0){
                printf("(%dx^%d)", terms[i].coef, terms[i].expo);
            }
            else if(terms[i].coef != 0 && terms[i].expo == 0){
                printf("(%d)", terms[i].coef);
            }
            else{
                continue;
            }

            if(i != terms_cnt - 1){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }
        return;
    }
};

polynomial add(polynomial p1, polynomial p2)
{
    int i = 0, j = 0, k = 0;
    polynomial sum;
    sum.terms_cnt = p1.terms_cnt + p2.terms_cnt;
    sum.terms = new term[sum.terms_cnt];

    while(i < p1.terms_cnt && j < p2.terms_cnt){
        if(p1.terms[i].expo > p2.terms[j].expo){
            sum.terms[k++] = p1.terms[i++];
        }
        else if(p1.terms[i].expo < p2.terms[j].expo){
            sum.terms[k++] = p2.terms[j++];
        }
        else{
            sum.terms[k].expo = p1.terms[i].expo;
            sum.terms[k].coef = p1.terms[i++].coef + p2.terms[j++].coef;
            if(sum.terms[k++].coef == 0){
                k--;
            }
        }
    }

    while(i < p1.terms_cnt){
        sum.terms[k++] = p1.terms[i++];
    }
    while(j < p2.terms_cnt){
        sum.terms[k++] = p2.terms[j++];
    }
    sum.terms_cnt = k;
    return sum;
}

void evaluate(polynomial p, int x)
{
    int i, sum = 0;
    for(i = 0; i < p.terms_cnt; i++){
        sum += (p.terms[i].coef * pow(x, p.terms[i].expo));
    }
    printf("For x = %d, Sum = %d\n", x, sum);
    return;
}

int main()
{
    int x;
    polynomial p1, p2, sum;
    cout << "For 1st polynomial, ";
    p1.input();
    cout << "\n1st polynomial = ";
    p1.display();
    cout << "\nFor 2nd polynomial, ";
    p2.input();
    cout << "\n2nd polynomial = ";
    p2.display();
    sum = add(p1, p2);
    cout << "\nSum = ";
    sum.display();
    cout << "\nEnter x = ";
    cin >> x;
    evaluate(sum, x);
    return 0;
}

/*
For 1st polynomial, number of terms = 3

Coefficient and exponent for term 1 : 3 2
Coefficient and exponent for term 2 : -5 1
Coefficient and exponent for term 3 : 1 0

1st polynomial = (3x^2) + (-5x^1) + (1)

For 2nd polynomial, number of terms = 3

Coefficient and exponent for term 1 : -2 2
Coefficient and exponent for term 2 : 3 1
Coefficient and exponent for term 3 : 4 0

2nd polynomial = (-2x^2) + (3x^1) + (4)

Sum = (1x^2) + (-2x^1) + (5)

Enter x = 2
For x = 2, Sum = 5
*/
