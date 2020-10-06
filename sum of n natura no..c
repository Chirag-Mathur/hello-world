// To calculate sum of n natural numbers 

#include<stdio.h>
int main()
{
	int n,i,sum=0;
	printf("Enter the no. = ");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<=n;i++)
	
		sum=sum+i;
	
	printf("sum=%d",sum);
	return 0;
}
