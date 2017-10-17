#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
/*
第一行三个正整数n, m, k(n是节点个数，m是有向边的条数，k是参加聚会的地点
编号)( 1 ≤ n ≤ 1000 ,1 ≤ m ≤ 100,000)
第二行..m + 1行每行3个整数x，y，w 代表从x到y需要花w的时间 0<w<=100
*/
int n,m,s,fir[1005],d[1005],end[200050],next[200050],len[200050],ed=0;
bool exist[1005];
void addedge(int u,int v,int lenth)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=lenth;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	len[ed]=lenth;
	return;
}
void Dijkstra()
{
	int u;
	for(int i=1;i<=n;i++)
		d[i]=2147483647;
	memset(exist,false,sizeof(exist));
	d[s]=0;
	exist[s]=true;
	for(int i=fir[s];i;i=next[i])
		d[end[i]]=len[i];
	for(int cnt=1;cnt<n;cnt++)
	{
		u=0;
		for(int i=1;i<=n;i++)
			if(!exist[i]&&d[i]<d[u])
				u=i;
		exist[u]=true;
		for(int i=fir[u];i;i=next[i])
		{
			if(d[u]+len[i]<d[end[i]])
				d[end[i]]=d[u]+len[i];
		}
	}
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout); 
	int a,b,c,md=0;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
	}
	Dijkstra();
	for(int i=1;i<=n;i++)
		if(d[i]!=2147483647&&d[i]>md)
			md=d[i];
	printf("%d",md*2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

