/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int C[4];
int main(int argc,char *argv[])
{
	int x; sscanf(argv[1],"%d",&x); srand(x);
	freopen("A.in","w",stdout);
	int n=rand()%20+1;
	printf("%d\n",n);
	for(int j=0;j<4;j++)
		C[j]=rand()%37;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<4;j++)
			printf("%d ",rand()%(C[j]+1));
		printf("%d\n",rand()%37);
	}
	for(int j=0;j<4;j++)
		printf("%d ",C[j]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

