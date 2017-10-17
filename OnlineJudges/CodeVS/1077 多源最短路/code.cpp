#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int dis[105][105],n,q,ak[105][105];
int key[10050],L[10050],R[10050],dist[10050],top,p[10050];
void swap(int &a,int &b)
{
	a^=b;
	b=a^b;
	a^=b;
	return;
}
int merge(int A,int B)
{
	if(!A)
		return B;
	else if(!B)
		return A;
	if(key[B]<key[A])
		swap(A,B);
	R[A]=merge(R[A],B);
	if(dist[L[A]]<dist[R[A]])
		swap(L[A],R[A]);
	dist[A]=R[A]?0:dist[R[A]]+1;
	return A;
}
void Hijkstras()
{
	int u;
	bool exist[105];
	for(int st=1;st<=n;st++)
	{
		memset(exist,false,sizeof(exist));
		memset(dis[st],127,sizeof(dis[st]));
		for(int i=0;i<10050;i++)p[i]=i;
		top=0;
		dis[st][st]=0;
		for(int i=1;i<=n;i++)
		{
			if(!ak[st][i])
				continue;
			key[p[++p[0]]]=dis[st][i]=ak[st][i];
			L[p[p[0]]]=R[p[p[0]]]=0;
			top=merge(top,p[p[0]]);
		}
		exist[st]=true;
		for(int i=1;i<n;i++)
		{
			while(exist[top])
			{
				p[p[0]--]=top;
				top=merge(L[top],R[top]);
			}
			u=top;
			exist[u]=true;
			for(int i=1;i<=n;i++)
				if(dis[st][u]+ak[u][i]<dis[st][i])
				{
					dis[st][i]=dis[st][u]+ak[u][i];
					key[p[++p[0]]]=dis[st][i];
					L[p[p[0]]]=R[p[p[0]]]=0;
					top=merge(top,p[p[0]]);
				}
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d",&n);
	for(int i=1,j;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&ak[i][j]);
	Hijkstras();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",dis[a][b]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
