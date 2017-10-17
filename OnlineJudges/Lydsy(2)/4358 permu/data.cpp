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
int Rand() { return 1LL*rand()*rand()%1000000; }
int main(int argc,char *argv[])
{
	freopen("code.in","w",stdout);
	int x; sscanf(argv[1],"%d",&x);
	srand(x);
	int n=50000,m=50000,num[50050],l,r;
	//n=rand()%10000+1;
	//m=rand()%10000+1;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++) num[i]=i;
	for(int i=1;i<=(m<<1);i++)
	{
		l=Rand()%n+1;
		r=Rand()%n+1;
		swap(num[l],num[r]);
	}
	for(int i=1;i<=n;i++) printf("%d ",num[i]);
	putchar('\n');
	for(int i=1;i<=m;i++)
	{
		l=Rand()%n+1;
		r=Rand()%n+1;
		if(l>r) swap(l,r);
		printf("%d %d\n",l,r);
	}
	fclose(stdout);
	return 0;
}

