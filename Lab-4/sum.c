#include<stdio.h>
long int sum(int n,long int a)
{
    if(n==0){
        return a;
    }
    else{
        return sum(n-1,a+n);
    }
}
int main()
{
    int n;
    printf("enter n:");
    scanf("%d",&n);
    printf("The sum upto %d is %ld\n",n,sum(n,0));
    return 0;
}