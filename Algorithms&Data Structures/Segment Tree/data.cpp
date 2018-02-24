#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int n,m,opt,a,b,c;
	n=rand()%1000+1;
	m=rand()%1000+1;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%1000+1);
	printf("\n");
	for(int i=1;i<=m;i++)
	{
		opt=rand()%4+1;
		if(opt==1)
		{
			a=rand()%n+1;
			b=rand()%1000;
			printf("1 %d %d\n",a,b);
		}
		else if(opt==2)
		{
			a=rand()%n+1;
			b=rand()%n+1;
			c=rand()%1000;
			if(a>b)
			{
				a+=b;
				b=a-b;
				a=a-b;
			}
			printf("2 %d %d %d\n",a,b,c);
		}
		else if(opt==3)
		{
			a=rand()%n+1;
			printf("3 %d\n",a);
		}
		else if(opt==4)
		{
			a=rand()%n+1;
			b=rand()%n+1;
			if(a>b)
			{
				a+=b;
				b=a-b;
				a=a-b;
			}
			printf("4 %d %d\n",a,b);
		}
	}
	fclose(stdout);
	return 0;
}

