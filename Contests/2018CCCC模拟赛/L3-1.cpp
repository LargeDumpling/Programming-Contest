/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
int f[MAXN],size[MAXN],n;
int fInd(int x)
{
	int xx;
	while(f[x]!=f[f[x]])
	{
		xx=fInd(f[x]);
		size[f[x]]-=size[x];
		size[xx]+=size[x];
		f[x]=xx;
	}
	return f[x];
}
void mErge(int a,int b)
{
	a=fInd(a); b=fInd(b);
	if(a!=b)
	{
		if(b<a) swap(a,b);
		f[b]=a;
		size[a]+=size[b];
	}
	return;
}
int main()
{
	int k,x,y,idx[MAXN]={0};
	for(int i=0;i<MAXN;i++) f[i]=i,size[i]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d:%d",&k,&x);
		for(int j=2;j<=k;j++)
		{
			scanf("%d",&y);
			mErge(x,y);
		}
		size[fInd(x)]++;
	}
	for(int i=1;i<MAXN;i++) if(f[i]==i&&size[i]!=0)
		idx[++idx[0]]=size[i];
	sort(idx+1,idx+idx[0]+1);
	printf("%d\n",idx[0]);
	for(int i=idx[0];i;i--)
	{
		printf("%d",idx[i]);
		if(i!=1) putchar(' ');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

