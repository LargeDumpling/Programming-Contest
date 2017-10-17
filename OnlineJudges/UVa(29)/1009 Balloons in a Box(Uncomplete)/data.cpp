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
	int T=rand()%10+1,n,x1,y1,z1,x2,y2,z2,x,y,z;
	while(T--)
	{
		n=rand()%10+1;
		printf("%d\n",n);
		x1=rand()%10;
		y1=rand()%10;
		z1=rand()%10;
		x2=rand()%10;
		y2=rand()%10;
		z2=rand()%10;
		if(x1>x2)
		{
			x1^=x2;
			x2=x1^x2;
			x1^=x2;
		}
		printf("%d %d %d\n%d %d %d\n",x1,y1,z1,x2,y2,z2);
		for(int i=1;i<=n;i++)
		{
			x=rand()%(x2-x1)+x1;
			y=rand()%(y2-y1)+y1;
			z=rand()%(z2-z1)+z1;
			printf("%d %d %d\n",x,y,z);
		}
	}
	printf("0");
	fclose(stdout);
	return 0;
}

