#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int n,m,T,jx,jy,f1,f2,f3;
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	T=rand()%10+1;
	printf("%d\n",T);
	for(int t=1;t<=T;t++)
	{
		n=rand()%10+1;
		m=rand()%10+1;
		printf("%d %d\n",n,m);
		jx=rand()%n+1;
		jy=rand()%m+1;
		f1=(rand()%n+1)*10000+(rand()%m+1);
		f2=(rand()%n+1)*10000+(rand()%m+1);
		f3=(rand()%n+1)*10000+(rand()%m+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==jx&&j==jy)
					printf("J");
				else if(i*10000+j==f1)
					printf("F");
				else if(i*10000+j==f2)
					printf("F");
				else if(i*10000+j==f3)
					printf("F");
				else if(rand()%5+1>1)
					printf(".");
				else
					printf("#");
			}
			printf("\n");
		}
	}
	fclose(stdout);
	return 0;
}

