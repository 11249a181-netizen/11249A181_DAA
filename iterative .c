#include <stdio.h>
int main()
{
	int n = 10;
	int a=0, b=1;
	int i;
	printf("the fibonacci series upto n numbers : \n",n);
	for(i=2;i <=n; ++i)
	{
		printf("%d",a);
		int next =a+b;
		a=b;
		b=next;
		
	}
	printf("\n");
	return 0;
}
