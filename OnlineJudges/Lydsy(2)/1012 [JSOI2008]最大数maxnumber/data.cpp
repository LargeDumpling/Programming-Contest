#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int m,D,n=0;
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	m=rand()%20000+1;
	D=rand()+1;
	printf("%d %d\n",m,D);
	for(int i=1;i<=m;i++)
	{
		if(n)
		{
			if(rand()&1)
			{
				printf("A %d\n",rand());
				n++;
			}
			else
				printf("Q %d\n",rand()%n+1);
		}
		else
		{
			n++;
			printf("A %d\n",rand());
		}
	}
	fclose(stdout);
	return 0;
}

