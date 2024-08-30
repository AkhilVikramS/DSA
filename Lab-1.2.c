#include<stdio.h>
#include<stdlib.h>
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return 0;
    }
    return 1; 
}
int primeSum(int*a,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(isPrime(a[i]))
        {
            sum=sum+a[i];
        }
    }
    return sum;
}
int main()
{
    int n;
    printf("enter the number of elements");
    scanf("%d",&n);
    int*a=(int*)malloc(n*sizeof(int));
    if(a == NULL)
    {
      printf("Memory allocation failed.");
    }
    printf("enter the elemnts of the array.");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int sum= primeSum(a,n);
    printf("the sum of the prime numbers in the array is %d", sum);
    free(a);
	return 0;
}
