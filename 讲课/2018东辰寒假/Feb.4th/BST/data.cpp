/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main(int argc,char *argv[])
{
	int x; sscanf(argv[1],"%d",&x); srand(x);
	freopen("BST.in","w",stdout);
	int n,m;
	n=m=1000000;
	//n=m=3;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
		printf("%d\n",rand());
	for(int i=1;i<=m;i++)
		printf("%d %d\n",rand()%3+1,rand());
	fprintf(stderr,"Datamaker %lf\n",(double)clock()/CLOCKS_PER_SEC);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

