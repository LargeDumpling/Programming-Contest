/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10050;
const int M=2;
int n,num[MAXN],ch[320050][2],val[320050],sz=0;
int f[MAXN],mAx,cnt;
void insert(int x)
{
	int dig[35],u=0;
	for(int i=0;i<M;i++)
		dig[i]=(num[x]>>i)&1;
	for(int i=M-1;0<=i;u=ch[u][dig[i--]])
		if(!ch[u][dig[i]])
			ch[u][dig[i]]=++sz;
	val[u]=x;
	return;
}
int query(int x)
{
	int dig[35],u=0,v;
	for(int i=0;i<M;i++)
		dig[i]=(num[x]>>i)&1;
	for(int i=M-1;0<=i;u=v,i--)
		v=ch[u][dig[i]^1]?ch[u][dig[i]^1]:ch[u][dig[i]];
	return val[u];
}
int main()
{
	scanf("%d",&n);
	num[0]=mAx=cnt=0;
	insert(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		num[i]^=num[i-1];
		f[i]=query(i);
		insert(i);
		if((num[mAx]^num[f[mAx]])<(num[i]^num[f[i]]))
		{
			mAx=i;
			cnt=1;
		}
		else if((num[mAx]^num[f[mAx]])==(num[i]^num[f[i]]))
			cnt++;
	}
	printf("%d %d %d\n",num[mAx]^num[f[mAx]],cnt,mAx-f[mAx]);
	for(int i=f[mAx]+1;i<=mAx;i++)
		printf("%d ",num[i]^num[i-1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

