/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-21	File created.
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
	int x; sscanf(argv[1],"%d",&x); srand(x);
	freopen("J.in","w",stdout);
	//int n=rand()%20+3,m=rand()%20+3,q=rand()%20+1;
	int n=rand()+3,m=rand()+3,q=rand()+1;
	m=min(n,100);
	printf("%d %d %d\n",n,m,q);
	for(int i=1;i<=m;i++)
		//printf("%d ",rand()%20);
		printf("%d ",rand());
	putchar('\n');
	while(q--)
		printf("%d ",rand()%n+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

