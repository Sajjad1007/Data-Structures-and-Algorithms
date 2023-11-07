#include <stdio.h>

#define ll long long

int m;

ll big_mod(ll a, ll b)
{
    if(b == 0){
        return 1;
    }
    else if(b % 2 == 0){
        ll ans = ((big_mod(a, b / 2) % m) * (big_mod(a, b / 2) % m)) % m;  //(a*b)%m = ((a%m)*(b%m))%m
        return ans;
    }
    else if(b % 2 == 1){
        ll ans = ((a % m) * (big_mod(a, b - 1) % m)) % m;
        return ans;
    }
}

int main(void)
{
    ll a, b;
    printf("Enter a and b = ");
    scanf("%lld %lld", &a, &b);
    printf("Enter m = ");
    scanf("%d", &m);
    printf("\n(%lld^%lld) %% %d = %lld\n", a, b, m, big_mod(a, b));
    return 0;
}

/*
Enter a and b = 23 3
Enter m = 30

(23^3) % 30 = 17
*/
