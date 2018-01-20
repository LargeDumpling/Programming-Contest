/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-23	File created.
*/

#include<stdio.h>
#define MAXN 305
int n,m,sz[MAXN],st[MAXN];
int main()
{
	int i;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		sz[1]=0;
		for(i=2;i<=n;i++)
			sz[i]=(sz[i-1]+m)%i;
		printf("%d\n",sz[n]+1);
	}
	return 0;
}

