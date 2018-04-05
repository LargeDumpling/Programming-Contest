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
const int MAXN=10050;
struct jz
{
	int id,cnt,mn;
	double total;
	jz() { id=cnt=total=0; mn=1; }
	bool operator<(const jz &X)const
	{
		if(total*X.mn==X.total*mn) return id<X.id;
		else return total*X.mn>X.total*mn;
	}
}p[MAXN];
int n,f[MAXN],idx[MAXN*10];
bool exist[MAXN];
int fInd(int x)
{
	while(f[x]!=f[f[x]])
		f[x]=fInd(f[x]);
	return f[x];
}
void mErge(int a,int b)
{
	a=fInd(a); b=fInd(b);
	if(b<a) swap(a,b);
	f[b]=a;
	return;
}
int main()
{
	int x,pat,patin,k,u;
	memset(exist,false,sizeof(exist));
	idx[0]=0;
	for(int i=0;i<MAXN;i++) f[i]=i;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x,&pat,&patin,&k);
		idx[++idx[0]]=x;
		if(pat!=-1) idx[++idx[0]]=pat;
		if(patin!=-1) idx[++idx[0]]=patin;
		if(pat!=-1&&patin!=-1) mErge(pat,patin);
		if(pat!=-1) mErge(x,pat);
		else if(patin!=-1) mErge(x,patin);
		while(k--)
		{
			scanf("%d",&u);
			idx[++idx[0]]=u;
			mErge(x,u);
		}
		scanf("%d%lf",&p[x].cnt,&p[x].total);
	}
	sort(idx+1,idx+idx[0]+1);
	idx[0]=unique(idx+1,idx+idx[0]+1)-idx-1;
	for(int i=1;i<=idx[0];i++)
	{
		exist[idx[i]]=true;
		p[idx[i]].id=idx[i];
	}
	int cnt=0;
	for(int i=1;i<=idx[0];i++)
		if(fInd(idx[i])!=idx[i])
		{
			x=idx[i];
			p[f[x]].mn++;
			p[f[x]].cnt+=p[x].cnt;
			p[f[x]].total+=p[x].total;
		}
		else cnt++;
	sort(p+1,p+MAXN);
	printf("%d\n",cnt);
	for(int i=1;i<MAXN;i++)
		if(exist[p[i].id]&&f[p[i].id]==p[i].id)
			printf("%04d %d %.3lf %.3lf\n",p[i].id,p[i].mn,(double)p[i].cnt/p[i].mn,(double)p[i].total/p[i].mn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

