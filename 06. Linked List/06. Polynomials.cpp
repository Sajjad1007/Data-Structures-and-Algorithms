#include <iostream>
#include <cmath>

using namespace std;

struct term
{
    int coef;
    int expo;
    term *next;

    term(int coef, int expo)
    {
        this->coef = coef;
        this->expo = expo;
    }
};

struct polynomial
{
    int terms_cnt;
    term *head = nullptr;

    //Insert() function inserts a term in descending order based on its exponent.
    void Insert(int coef, int expo)
    {
        term *p = head;
        term *t = new term(coef, expo);

        if((head == nullptr) || (expo > head->expo)){
            t->next = head;
            head = t;
        }
        else{
            while((p->next != nullptr) && (p->next->expo >= expo)){
                p = p->next;
            }
            if(p->expo == expo){
                p->coef = p->coef + coef;
            }
            else{
                t->next = p->next;
                p->next = t;
            }
        }
        return;
    }

    void input()
    {
        int i, coef, expo;
        cout << "number of terms = ";
        cin >> terms_cnt;

        if(terms_cnt > 0){
            cout << "\n";
            for(i = 1; i <= terms_cnt; ++i){
                cout << "Coefficient and exponent for term " << i << " : ";
                cin >> coef >> expo;
                Insert(coef, expo);
            }
        }
        return;
    }

    double evaluate(int x)
    {
        double ans = 0;
        term *p = head;

        while(p){
            ans += (p->coef * pow(x, p->expo));
            p = p->next;
        }
        return ans;
    }

    void display()
    {
        term *p = head;

        if(p == nullptr){
            printf("0\n");
        }
        else{
            while(true){
                if(p->coef == 0){
                    printf("0");
                }
                else if(p->coef != 0 && p->expo == 0){
                    printf("%d", abs(p->coef));
                }
                else if(p->coef == 1){
                    printf("x^%d", p->expo);
                }
                else if(p->expo == 1){
                    printf("%dx", abs(p->coef));
                }
                else if(p->expo > 1){
                    if(p == head){
                        printf("%dx^%d", p->coef, p->expo);
                    }
                    else{
                        printf("%dx^%d", abs(p->coef), p->expo);
                    }
                }

                p = p->next;
                if(p){
                    if(p->coef < 0){
                        printf(" - ");
                    }
                    else{
                        printf(" + ");
                    }
                }
                else{
                    printf("\n");
                    break;
                }
            }
        }
        return;
    }
};

polynomial add(polynomial poly1, polynomial poly2)
{
    polynomial sum;
    sum.terms_cnt = 0;
    term *p1 = poly1.head;
    term *p2 = poly2.head;

    while(p1 && p2){
        if(p1->expo == p2->expo){
            sum.Insert((p1->coef + p2->coef), p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->expo > p2->expo){
            sum.Insert(p1->coef, p1->expo);
            p1 = p1->next;
        }
        else{
            sum.Insert(p2->coef, p2->expo);
            p2 = p2->next;
        }
    }

    while(p1){
        sum.Insert(p1->coef, p1->expo);
        p1 = p1->next;
    }

    while(p2){
        sum.Insert(p2->coef, p2->expo);
        p2 = p2->next;
    }
    return sum;
}

polynomial multiply(polynomial poly1, polynomial poly2)
{
    polynomial pro;
    term *p1 = poly1.head;
    term *p2 = poly2.head;

    while(p1){
        while(p2){
            pro.Insert((p1->coef * p2->coef), (p1->expo + p2->expo));
            p2 = p2->next;
        }
        p1 = p1->next;
        p2 = poly2.head;
    }
    return pro;
}

int main()
{
    double x, ans;
    polynomial poly1, poly2, sum, pro;

    cout << "Enter x = ";
    cin >> x;
    cout << "\nFor 1st polynomial, ";
    poly1.input();
    cout << "\n1st polynomial = ";
    poly1.display();
    ans = poly1.evaluate(x);
    cout << "When x = " << x << ", 1st polynomial = " << ans << "\n";

    cout << "\nFor 2nd polynomial, ";
    poly2.input();
    cout << "\n2nd polynomial = ";
    poly2.display();
    ans = poly2.evaluate(x);
    cout << "When x = " << x << ", 2nd polynomial = " << ans << "\n";

    cout << "\nSum = ";
    sum = add(poly1, poly2);
    sum.display();
    ans = sum.evaluate(x);
    cout << "When x = " << x << ", sum = " << ans << "\n";

    cout << "\nProduct = ";
    pro = multiply(poly1, poly2);
    pro.display();
    ans = pro.evaluate(x);
    cout << "When x = " << x << ", product = " << ans << "\n";
    return 0;
}

/*
Enter x = 2

For 1st polynomial, number of terms = 3

Coefficient and exponent for term 1 : 3 2
Coefficient and exponent for term 2 : -5 1
Coefficient and exponent for term 3 : 1 0

1st polynomial = 3x^2 - 5x + 1
When x = 2, 1st polynomial = 3

For 2nd polynomial, number of terms = 3

Coefficient and exponent for term 1 : -2 2
Coefficient and exponent for term 2 : 3 1
Coefficient and exponent for term 3 : 4 0

2nd polynomial = -2x^2 + 3x + 4
When x = 2, 2nd polynomial = 2

Sum = x^2 - 2x + 5
When x = 2, sum = 5

Product = -6x^4 + 19x^3 - 5x^2 - 17x + 4
When x = 2, product = 6
*/
