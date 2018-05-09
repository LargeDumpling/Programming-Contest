#include<stdio.h>
int fun(int x)
{
	int i;
	for(i=2;i*i<=x;i++)
		if(!(x%i))
			return 0;
	return 1;
}
int main()
{
	int x,i,first=1;
	scanf("%d",&x);
	for(i=2;i*i<=x;i++) if(fun(i)&&!(x%i))
	{
		if(first)
		{
			printf("%d = %d",x,i);
			x/=i;
			first=0;
		}
		while(!(x%i))
		{
			printf("  * %d",i);
			x/=i;
		}
	}
	if(x!=1)
	{
		if(first) printf("%d = %d",x,x);
		else printf(" * %d",x);
	}
	return 0;
}

