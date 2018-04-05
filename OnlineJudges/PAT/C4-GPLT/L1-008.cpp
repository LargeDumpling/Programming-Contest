#include<cstdio>
int a,b;
int main()
{
	int sum=0,cnt=0;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++)
	{
		sum+=i;
		cnt++;
		printf("%5d",i);
		if(cnt==5)
		{
			cnt=0;
			putchar('\n');
		}
	}
	if(cnt) putchar('\n');
	printf("Sum = %d",sum);
	return 0;
}

