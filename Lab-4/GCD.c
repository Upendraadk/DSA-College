#include<stdio.h>
long int GCD(int a,int b)
{
    if(b==0)
        return a;
    else
        return GCD(b, a%b);
}
int main()
{
    int a,b;
    printf("Enter the values of a and b:");
    scanf("%d\n,%d",&a,&b);
    printf("The gcd of two number is:%d",GCD(a,b));
}

