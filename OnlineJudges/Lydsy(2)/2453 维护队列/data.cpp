/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-22	File created.
*/

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
	int C=100;
	//int n=rand()%1000+1,m=rand()%1000+1;
	int n=10000,m=10000;
	int a=1000,b=m-1000,k;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++) printf("%d ",rand()%C+1); putchar('\n');
	for(int i=1;i<=m;i++)
	{
		k=rand()%(a+b);
		if(k<a)
		{
			a--;
			printf("R %d %d\n",rand()%n+1,rand());
			//printf("R %d %d\n",1,n);
		}
		else
		{
			b--;
			int l=rand()%n+1,r=rand()%n+1;
			if(l>r) swap(l,r);
			printf("Q %d %d\n",l,r);
		}
		/*if(rand()%2)
		{
			int l=rand()%n+1,r=rand()%n+1;
			if(l>r) swap(l,r);
			printf("Q %d %d\n",l,r);
		}
		else printf("R %d %d\n",rand()%n+1,rand()%C+1);*/
	}
	fclose(stdout);
	return 0;
}

