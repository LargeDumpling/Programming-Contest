/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(int argc,char *argv[])
{
	freopen("code.in","w",stdout);
	int x; sscanf(argv[1],"%d",&x);
	srand(x);
	int n=rand()%10+1,m=rand()%10+1,order,a,b;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) printf("%d ",rand()%n+1);
	printf("\n%d\n",m);
	while(m--)
	{
		order=rand()%2+1;
		a=rand()%n;
		printf("%d %d",order,a);
		if(order==2)
		{
			b=rand()%n+1;
			printf(" %d",b);
		}
		putchar('\n');
	}
	fclose(stdout);
	return 0;
}

