#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int no_of_digits(int n);
int karatsuba(int n1,int n2);

int main()
{
    int x;
    printf("Number 1 : ");
    scanf("%d",&x);

    int y;
    printf("Number 2 : ");
    scanf("%d",&y);

    int result = karatsuba(x,y);

    printf("%d",result);

    return 0;
}

int karatsuba(int n1,int n2)
{
    if (n1 < 10 || n2 < 10)
    {
        return n1*n2;
    }
    else
    {
        int n;

        if(n1 > n2)
        {
            n = no_of_digits(n1);
        }
        else
        {
            n = no_of_digits(n2);
        }

        int half = n/2;

        int a,b,c,d;

        int temp = pow(10,n/2);

        a = n1 / temp;
        b = n1 - (a*temp);
        c = n2 / temp;
        d = n2 - (c*temp);

        int a_c = karatsuba(a,c);
        int b_d = karatsuba(b,d);
        int ad_plus_bc = karatsuba(a+b,c+d) - a_c - b_d;

        return (a_c * pow(10,(2*half))) + (ad_plus_bc * pow(10,half)) + b_d ;
    }
}

int no_of_digits(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int digits = 0;

        while (n != 0)
        {
            n = n/10;
            digits++;
        }
        return digits;
    }
}
