/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
int pri[MAXN],x2;
bool exist[MAXN],poss[MAXN];
int L[MAXN<<2],R[MAXN<<2],data[MAXN<<2];
void pre_calc()
{
	memset(exist,true,sizeof(exist));
	pri[0]=0;
	for(int i=2;i<MAXN;i++)
	{
		if(exist[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<MAXN;j++)
		{
			exist[i*pri[j]]=false;
			if(i%pri[j]==0) break;
		}
	}
	return;
}
void build(int root,int l,int r)
{
	L[root]=l;
	R[root]=r;
	if(l==r)
	{
		data[root]=r;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	data[root]=-1;
	return;
}
void change(int root,int l,int r,int x)
{
	if(l<=L[root]&&R[root]<=r)
	{
		data[root]=x;
		return;
	}
	if(l<=R[root<<1]) change(root<<1,l,r,x);
	if(R[root<<1]<r) change(root<<1|1,l,r,x);
	if(data[root<<1]==data[root<<1|1])
		data[root]=data[root<<1];
	else data[root]=-1;
	return;
}
int fInd(int root,int x)
{
	if(data[root]!=-1)
		return data[root];
	if(x<=R[root<<1]) return fInd(root<<1,x);
	return fInd(root<<1|1,x);
}
int main()
{
	int ans=-1;
	pre_calc();
	memset(poss,false,sizeof(poss));
	scanf("%d",&x2);
	for(int i=1;i<=pri[0]&&pri[i]<=x2;i++) if(x2%pri[i]==0)
	{
		for(int j=1;j<=pri[i];j++)
			exist[x2-pri[i]+j]=true;
	}
	int p;
	for(int i=3;i<=x2;i++)
	{
		for(int j=1;j<=pri[0]&&pri[j]<i;j++)
		{
			p=i/pri[j]*pri[j];
			if(p<i) p+=pri[j];
			if(exist[p])
			{
				ans=i;
				i=x2;
				break;
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

