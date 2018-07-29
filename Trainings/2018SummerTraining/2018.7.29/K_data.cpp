/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int num[MAXN];
int bigrand() { return (rand()<<15)+rand(); }
int main(int argc,char *argv[])
{
	int x; sscanf(argv[1],"%d",&x); srand(x);
	freopen("K.in","w",stdout);
	int n=bigrand()%100000+1;
	//int n=rand()%6+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		num[i]=i;
		printf("%d ",rand()&1);
	}
	for(int i=2;i<=n;i++)
		printf("\n%d %d",i,rand()%(i-1)+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

