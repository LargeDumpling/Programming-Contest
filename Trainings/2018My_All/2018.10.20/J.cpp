/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
int T_T,N,W,L,f[MAXN],lef[MAXN],rig[MAXN],ans;
struct Cir
{
	int x,y,r;
}C[MAXN];
int find(int x)
{
	if(f[x]!=f[f[x]]) f[x]=find(f[x]);
	return f[x];
}
void merge(int a,int b)
{
	a=find(a); b=find(b);
	if(a==b) return;
	f[b]=a;
	lef[a]=min(lef[a],lef[b]);
	rig[a]=max(rig[a],rig[b]);
	return;
}
long long sqr(long long x) { return x*x; }
long long dis(int i,int j) { return sqr(C[i].x-C[j].x)+sqr(C[i].y-C[j].y); }
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		ans=0;
		scanf("%d%d%d",&N,&W,&L);
		for(int i=1;i<=N;i++)
		{
			scanf("%d%d%d",&C[i].x,&C[i].y,&C[i].r);
			f[i]=i;
			lef[i]=C[i].x-C[i].r;
			rig[i]=C[i].x+C[i].r;
		}
		for(int i=1;i<=N;i++)
			for(int j=i+1;j<=N;j++)
				if(dis(i,j)<=sqr(C[i].r+C[j].r))
					merge(i,j);
		for(int i=1;i<=N;i++) if(f[i]==i)
		{
			if(lef[i]<=0&&W<=rig[i])
				ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

