/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100050;
long long p,k;
int q[MAXN];
int main()
{
	long long t;
	scanf("%I64d%I64d",&p,&k);
	q[0]=0;
	while(p)
	{
		q[++q[0]]=p%k;
		t=-1LL*p/k;
		if(q[q[0]]<0)
		{
			q[q[0]]+=k;
			t++;
		}
		p=t;
	}
	if(!q[q[0]]) puts("-1");
	else
	{
		printf("%d\n",q[0]);
		for(int i=1;i<=q[0];i++)
			printf("%d ",q[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

