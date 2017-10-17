/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int p1,p2,d;
	jp(int a=0,int b=0,int c=0):p1(a),p2(b),d(c){}
	bool operator<(const jp &X)const{return d<X.d;}
}E[1000050];
int n,q;
int bag[10][1050],x[1050],y[1050],en,cho[1050],f[1050],num[1050];
int dist(int i,int j){return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);}
int find(int x)
{
	while(f[x]!=f[f[x]])f[x]=f[f[x]];
	return f[x];
}
void make_cho()
{
	int a,b;
	memcpy(f,num,sizeof num);
	for(int i=1;i<=en&&cho[0]<n-1;i++)
	{
		a=find(E[i].p1);b=find(E[i].p2);
		if(a!=b)cho[++cho[0]]=i,f[b]=a;
	}
	return;
}
int Kruskal(int S)
{
	int ans=0,a,b;
	memcpy(f,num,sizeof num);
	for(int i=1;i<=q;i++)if(S&(1<<(i-1)))
	{
		for(int j=1;j<=bag[i][0];j++)f[find(bag[i][1])]=find(bag[i][j]);
		ans+=bag[i][1049];
	}
	for(int i=1;i<=cho[0];i++)
	{
		a=find(E[cho[i]].p1);b=find(E[cho[i]].p2);
		if(a!=b)
		{
			f[b]=a;
			ans+=E[cho[i]].d;
		}
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T,ans;
	scanf("%d",&T);
	for(int i=0;i<1050;i++)num[i]=i;
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&bag[i][0],&bag[i][1049]);
			for(int j=1;j<=bag[i][0];j++)scanf("%d",&bag[i][j]);
		}
		en=cho[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			for(int j=1;j<i;j++)E[++en]=jp(i,j,dist(i,j));
		}
		sort(E+1,E+en+1);
		make_cho();
		ans=2147483647;
		int k;
		for(int i=(1<<q)-1;i>=0;i--)
			ans=min(ans,k=Kruskal(i));
		printf("%d\n",ans);
		if(T)putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

